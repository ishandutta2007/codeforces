#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define ll long long

const int maxn = 100100;
int n, m;
ll ans, ma;
int a[maxn];
multiset<int> q[maxn];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
    for(int i = 1; i < m; i++) 
        if (a[i + 1] != a[i]) q[a[i]].insert(a[i + 1]);
    for(int i = 2; i <= m; i++) 
        if (a[i - 1] != a[i]) q[a[i]].insert(a[i - 1]);
    for(int i = 2; i <= m; i++) ans += abs(a[i] - a[i - 1]);
    for(int i = 1; i <= n; i++){
        int tot = q[i].size();ll ret1 = 0, ret2 = 0;int now, change;
        if (!tot) continue;
        set<int>::iterator it = q[i].begin();
        for(now = 1; it != q[i].end(); it++, now++)
            if (now == (tot + 1) / 2)   { change = *it; break; }
        it = q[i].begin();
        for(; it != q[i].end(); it++) ret1 += abs(i - *it), ret2 += abs(change - *it);
        if ((ret1 - ret2) > ma) ma = ret1 - ret2;
    }
    printf("%I64d\n", ans - ma);
    return 0;
}