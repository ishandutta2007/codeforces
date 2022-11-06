#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const int N = 1e6;
const int mod = 998244353;
ll a[N], pa[N], fp[N], fpa[N];
int p[N];
int n, m;
set<int>f;
ll calc(ll x, ll y) {
    ll  z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
ll ni(ll x) {
    return calc(x, mod - 2);
}
ll oppose(ll x) {
    if (!x) return 1;
    if (x == 1) return 0;
    return mod - x + 1;
}
ll sub(ll x ,ll y) {
    return x -  y < 0 ? x - y + mod: x - y;
}
ll add(ll x, ll y) {
    return x + y >= mod ? x + y - mod : x + y;
}
ll mul(ll x, ll y){
    return x * y % mod;
}
ll get(int x) {
    int y = *f.upper_bound(x);
    ll f0 = ni(sub(1, mul(sub(fp[y - 1], fp[x - 1]), ni(pa[x - 1]))));
    return mul(f0, mul(sub(fpa[y - 1], fpa[x - 1]), ni(pa[x - 1])));
}
int main() {
    pa[0] = 1;
    fpa[0] = 1;
    scanf("%d %d", &n, &m);
    ll inv100 = ni(100);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        p[i] = inv100 * x % mod;
    }
    for (int i = 1; i <= n; i ++)
        pa[i] = pa[i - 1] * p[i] % mod, fpa[i] = add(fpa[i - 1], pa[i - 1]),fp[i] = add(fp[i - 1], mul(pa[i - 1], oppose(p[i])));
    f.insert(1);
    f.insert(n + 1);
    ll ans = get(1);
    while (m --) {
        int x;
        scanf("%d", &x);
        if (f.find(x) == f.end()) {
            auto y = f.upper_bound(x);
            y --;
            int z = *y;
            ans = sub(ans, get(z));
            f.insert(x);
            ans = add(ans, add(get(x), get(z)));
        } else {
            auto y = f.lower_bound(x);
            y --;
            int z = *y;
            ans = sub(sub(ans, get(x)), get(z));
            f.erase(x);
            ans = add(ans, get(z));
        }
        printf("%lld\n", ans);
    }
    return 0;
}