#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;
#define M 110
int n, a[M], out[M], so = 0;

map<int, set<int> > m;
long long sum[M] = {0};
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        m[a[i]].insert(i);
        sum[i] = 0;
        if(a[i] > 0) sum[i] += a[i];
        sum[i] += sum[i-1];
    }
    long long ans = 0, tmp;
    int flag = 0, l, r, tl, tr;
    for(map<int, set<int> >::iterator mit = m.begin(); mit != m.end(); ++mit) {
        if(mit->second.size() >= 2) {
            tl = *mit->second.begin(); tr = *mit->second.rbegin();
            tmp = sum[tr - 1] - sum[tl] + mit->first * 2;
            if(flag == 0) { flag = 1; ans = tmp; l = tl; r = tr;}
            else if(tmp > ans) { ans = tmp; l = tl; r = tr; }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(i < l || i > r) out[so++] = i;
        else if(i > l && i < r && a[i] < 0) out[so++] = i;
    }
    cout << ans << ' ' << so << endl;
    for(int i = 0; i < so; ++i)
        printf("%d ", out[i]);
    puts("");
    return 0;
}