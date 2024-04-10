#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
set <int> s;
struct edge{
    int x,y,w;
    friend bool operator <(edge a,edge b){
        return abs(a.w)<abs(b.w);
    }
}e[305],ee[305];
int fa[55];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
long long cost[300005],down[300005],up[300005];
int v[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n, m, x = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
        for (int i = 1; i <= m; i++) s.insert(e[i].w);
        for (int i = 1; i <= m; i++)
            for (int j = i + 1; j <= m; j++)
                s.insert((e[i].w + e[j].w) / 2), s.insert((e[i].w + e[j].w + 1) / 2), s.insert(
                        (e[i].w + e[j].w) / 2 - 1), s.insert((e[i].w + e[j].w) / 2 + 1);
        s.insert(0), s.insert(100000000);
        //assert(s.size()<=200000);
        for (auto t:s) {
            for (int i = 1; i <= m; i++) ee[i] = e[i], ee[i].w = e[i].w - t;
            sort(ee + 1, ee + m + 1);
            for (int i = 1; i <= n; i++) fa[i] = i;
            long long ans = 0, cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= m; i++) {
                int x = ee[i].x, y = ee[i].y;
                x = find(x), y = find(y);
                if (x != y) {
                    fa[y] = x, ans += abs(ee[i].w);
                    if (ee[i].w <= 0) cnt1++;
                    if (ee[i].w >= 0) cnt2++;
                }
            }
            cost[x] = ans, down[x] = cnt1, up[x] = cnt2;
            v[x++] = t;
        }
        long long ans = 0;
        int p, k, a, b, c, last, cnt = 0;
        cin >> p >> k >> a >> b >> c;
        for (int i = 1; i <= p; i++) {
            scanf("%d", &last);
            int it = lower_bound(v, v + x, last) - v;
            long long mn = LLONG_MAX;
            if (it != x) mn = min(mn, cost[it] + up[it] * (v[it] - last) - (n - 1 - up[it]) * (v[it] - last));
            if (it) --it, mn = min(mn, cost[it] + down[it] * (last - v[it]) - (n - 1 - down[it]) * (last - v[it]));
            ans ^= mn;
        }
        for (int i = p + 1; i <= k; i++) {
            last = (1LL * a * last + b) % c;
            int it = lower_bound(v, v + x, last) - v;
            long long mn = LLONG_MAX;
            if (it != x) mn = min(mn, cost[it] + up[it] * (v[it] - last) - (n - 1 - up[it]) * (v[it] - last));
            if (it) --it, mn = min(mn, cost[it] + down[it] * (last - v[it]) - (n - 1 - down[it]) * (last - v[it]));
            ans ^= mn;
        }
        //cout<<cnt<<endl;
        printf("%lld\n", ans);
    }
    return 0;
}