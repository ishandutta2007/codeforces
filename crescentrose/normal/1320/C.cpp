#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int n, m, p;
struct node{
    long long mx, tag;
}f[N * 4];
long long a[N], b[N];
vector<pair<int, int> > g[N] ;
long long ans = -1e18;
void build(int l, int r, int s) {
    if (l == r) {
        f[s].mx = -b[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2  +1, r, s + s + 1);
    f[s].mx = max(f[s+s].mx, f[s+s+1].mx);
}
void down(int l, int r, int s){
    if (f[s].tag) {
        f[s].mx += f[s].tag;
        if (l !=r)
            f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void add(int l, int r, int s, int ll, int v) {
    down(l, r, s);
    if (r < ll) return;
    if (l >= ll) {
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    add(l, (l + r) / 2, s + s, ll,v), add((l + r) / 2  +1, r, s + s + 1, ll, v);
    f[s].mx = max(f[s+s].mx, f[s+s+1].mx);
}
int main() {
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= 1000000; i++)
        a[i] = b[i] = 1e18;
    for (int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x] = min(a[x], 1ll * y);
    }
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        b[x] = min(b[x], 1ll * y);
    }
    for (int i = 1;i <= p; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
    }
    build(1, 1000000, 1);
    for (int i = 1; i <= 1000000; i ++) {
        ans = max(ans, f[1].mx - a[i]);
        for (auto u:g[i])
            add(1, 1000000, 1, u.first + 1, u.second);
    }
    printf("%lld\n", ans);
    return 0;
}