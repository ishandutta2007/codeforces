#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 200200;
const ll MOD = 998244353;

static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned quot, rem;
    asm("divl %4\n"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
}

ll modpow(ll b, ll p) {
    ll ans = 1;
    for (; p; p/=2, b=fast_mod(b*b, MOD)) {
        if (p&1) ans = fast_mod(ans*b, MOD);
    }
    return ans;
}

ll p[N];
ll pp[N];
ll ps[N];
ll pk[N];
ll i100;
map<ll, ll> check;
int n, q;

ll kx(int i, int j) {
    ll a = pk[j-1] - pk[i-1];
    ll b = (i-1)*(MOD+ps[j-1] - ps[i-1]);
    ////cerr << "  kx " << i << "," << j << " : " << a << " / " << i-1 << " " << (ps[j-1]-ps[i-1]+MOD)%MOD << " -> " << b << endl;
    return fast_mod(fast_mod(MOD*MOD+a-b, MOD)*modpow(pp[i-1], MOD-2), MOD);
}

ll e(int i, int j) {
    ll ce = 1 - (ps[j-1] - ps[i-1])*modpow(pp[i-1], MOD-2);
    ce = fast_mod(MOD*MOD + ce, MOD);
    ll cc = (((j-i)*pp[j-1]%MOD)*modpow(pp[i-1], MOD-2) + kx(i, j))%MOD;
    //cerr << "  cc " << (j-i) << " " << pp[j-1]%MOD << " " << modpow(pp[i-1], MOD-2) << ", plus " << kx(i, j) << endl;
    ll ans = cc*modpow(ce, MOD-2)%MOD;
    //cerr << " e(" << i << "," << j << ") : " << (MOD+cc%MOD)%MOD << "/" << (MOD+ce%MOD)%MOD << " = " << ans << endl;
    return ans;
}

void setup() {
    i100 = modpow(100, MOD-2);

    pp[0] = 1;
    ps[0] = 0;
    pk[0] = 0;
    for (int i=1; i<=n; ++i) {
        pp[i] = (pp[i-1]*p[i]%MOD)*i100%MOD;
        ll s = (pp[i-1]*(100-p[i])%MOD)*i100%MOD;
        ps[i] = (ps[i-1]+s)%MOD;
        ll kv = s*i%MOD;
        pk[i] = (pk[i-1]+kv)%MOD;
        //cerr << ":: " << i << " :: " << pp[i] << " " << ps[i] << " " << pk[i] << " ( " << s << " " << kv << ")" << endl;
    }

    check[1] = e(1, n+1);
    check[n+1] = -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; ++i) {
        cin >> p[i];
    }
    setup();

    ll ans = check[1];

    for (int i=0; i<q; ++i) {
        int u;
        cin >> u;
        if (check.count(u)) {
            ans -= check[u];
            check.erase(u);
            //cerr << "! rem " << check.count(u) << endl;
            auto it = check.upper_bound(u);
            int after = it->first;
            --it;
            int before = it->first;
            //cerr << " a b " << after << " " << before << " " << check.count(u) << endl;
            ans -= check[before];
            it->second = e(before, after);
            ans += it->second;
        } else {
            //cerr << "! add " << endl;
            check.erase(u);
            auto it = check.upper_bound(u);
            int after = it->first;
            --it;
            int before = it->first;
            ans -= check[before];
            check[before] = e(before, u);
            check[u] = e(u, after);
            ans += check[before];
            ans += check[u];
        }
        ans = (MOD+ans%MOD)%MOD;
        cout << ans%MOD << "\n";
    }

    return 0;
}