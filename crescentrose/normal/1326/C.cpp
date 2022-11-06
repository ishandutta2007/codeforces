#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll calc(ll x, ll y){
    ll z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
namespace C{
    vector<int>a, nia;
    void pre(int n){
        a = vector<int>(n + 1, 1);
        nia = vector<int>(n + 1, 1);
        for (int i = 2; i <= n; i ++)
            a[i] = 1ll * a[i - 1] * i % mod;
        nia[n] = calc(a[n], mod - 2);
        for (int i = n - 1; i >= 2; i --)
            nia[i] = 1ll * nia[i + 1] * (i + 1) % mod;
    }
    ll C(ll x, ll y) {
        if (x < y || y < 0) return 0;
        return 1ll * a[x] * nia[y] % mod * nia[x - y] % mod;
    }
}
const int N = 1000000;
int n, k;
int id[N], a[N];
int main() {
    C::pre(N);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), id[i] = i;
    sort(id+1, id+n+1,[](int x, int y) {
        return a[x] > a[y];
    });
    sort(id+1, id + k  +1);
    ll ans = 1;
    long long anv= 0;
    for (int i =1; i <= k; i ++)
        anv += a[id[i]];
    for (int i = 2; i <= k; i ++) {
        int x = id[i] - id[i - 1];
        ans = ans * x % mod;
    }
    printf("%lld %lld\n",anv, ans);
    return 0;
}