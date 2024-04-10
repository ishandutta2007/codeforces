#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std;

const int N = 111111;

int f[N][3];

char str[N];
int q;

int main() {
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for(int i = 1; i <= n; i++) {
        for(char j = 'x'; j <= 'z'; j++) {
            f[i][j - 'x'] += f[i - 1][j - 'x'] + (str[i] == j);
        }
    }
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        vector<int> cnt;
        for(char j = 'x'; j <= 'z'; j++) {
            cnt.push_back(f[r][j - 'x'] - f[l - 1][j - 'x']);
        }
        sort(cnt.begin(), cnt.end());
        if ((cnt[2] - cnt[0]) <= 1 || (r - l + 1) < 3) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}