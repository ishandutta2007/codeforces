#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2222;
const int inf = 1 << 30;

int lessPre[N], lessLas[N];
int n, a[N], f[N][N], pos[N], m;
vector<pair<int, int> > vec;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < 0)
            a[i] = -a[i];
        vec.push_back(make_pair(a[i], i));
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++)
            if (a[j] < a[i])
                lessPre[i]++;
        for(int j = n; j > i; j--)
            if (a[j] < a[i])
                lessLas[i]++;
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i = 0, j; i < vec.size(); i = j) {  
        m = 0;
        j = i;
        while(j < vec.size() && vec[i].first == vec[j].first) {
            pos[++m] = vec[j].second;
            j++;    
        }
        for(int k = 0; k <= m; k++)
            for(int l = 0; l <= m; l++)
                f[k][l] = inf;
        f[0][0] = 0;
        for(int k = 0; k < m; k++)
            for(int l = 0; l <= m; l++) {
                // postive
                f[k + 1][l + 1] = min(f[k + 1][l + 1], f[k][l] + lessLas[pos[k + 1]]);
                // 
                f[k + 1][l] = min(f[k + 1][l], f[k][l] + lessPre[pos[k + 1]] + l);      
            }
        int res = inf;
        for(int k = 0; k <= m; k++)
            res = min(res, f[m][k]);
        ans += res;
    }
    printf("%d\n", ans);
    return 0;       
}