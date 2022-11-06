#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
struct node{
    long long tag, mn;
    long long v(){
        return mn + tag;
    }
    void clear() {
        tag = mn = 0;
    }
}f[N * 4];
int a[N], b[N];
long long c[N];
int n;
void build(int l, int r, int s) {
    if (l == r) {
        f[s].mn = c[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l+ r) / 2 + 1, r, s + s + 1);
    f[s].mn = min(f[s+s].v(), f[s+s+1].v());
}
void add(int l, int r, int s, int ll, int rr ,int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        return;
    }
    add(l, (l+r) / 2, s+s, ll, rr, v);
    add((l+r)/2+1,r,s+s+1, ll, rr, v);
    f[s].mn =min(f[s+s].v(), f[s+s+1].v());
}
int main() {
    scanf("%d", &n);
    for (int i=  1;i  <=n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 1;i  <= n; i++) {
        scanf("%d", &b[i]);
        c[a[i]] += b[i];
    }
    for (int i = 1; i <= n; i++)
        c[i] += c[i - 1];
    build(0, n, 1);
    long long ans = 1e18;
    for (int i = 1; i < n ; i ++) {
        add(0, n, 1, a[i], n, -b[i]);
        add(0, n, 1, 0, a[i] - 1, b[i]);
        ans = min(ans, f[1].v());
    }
    printf("%lld\n",ans);
    return 0;
}