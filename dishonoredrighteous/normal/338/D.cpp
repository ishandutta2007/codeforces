// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 10100;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    a /= d;

    if (a > LINF / b) {
        printf("NO\n");
        exit(0);
    }

    return a * b;
}

ll gcdEx(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = gcdEx(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll binmul(ll a, ll b, ll mod) {
    if (b == 0) {
        return 0;
    }
    if (b % 2 == 0) {
        return binmul((a + a) % mod, b / 2, mod);
    } else {
        return (binmul(a, b - 1, mod) + a) % mod;
    }
}

ll solve(ll r1, ll mod1, ll r2, ll mod2) {
    ll g = gcd(mod1, mod2);

    if (r1 % g != r2 % g) {
        printf("NO\n");
        exit(0);
    }

    ll a = mod1 / g;
    ll b = (r2 - r1) / g;
    ll c = mod2 / g;

    ll x, y;
    gcdEx(a, c, x, y);

    x = (x % c + c) % c;

    // ll k = (b % c * x) % c;
    ll k = binmul(b, x, c);
    ll ans = (r1 + k * mod1) % lcm(mod1, mod2);

    return ans;
}

ll a[N];

void run() {
    ll n, m;
    int k;
    scanf("%lld%lld%d", &n, &m, &k);

    for (int i = 0; i < k; ++i) {
        scanf("%lld", &a[i]);
    }

    ll l = a[0];
    for (int i = 1; i < k; ++i) {
        l = lcm(l, a[i]);
    }

    if (l > n) {
        printf("NO\n");
        return;
    }

    std::vector<std::pair<ll, ll>> eq(k);
    for (int i = 0; i < k; ++i) {
        eq[i].second = a[i];
        eq[i].first = ((-i) % a[i] + a[i]) % a[i];
    }

    ll r1 = eq[0].first;
    ll mod1 = eq[0].second;
    for (int i = 1; i < k; ++i) {
        ll curMod = lcm(mod1, eq[i].second);
        ll curR = solve(r1, mod1, eq[i].first, eq[i].second);
        r1 = (curR % curMod + curMod) % curMod;
        mod1 = curMod;
    }

    if (r1 == 0) {
        r1 += mod1;
    }

    if (r1 + k - 1 > m) {
        printf("NO\n");
        return;
    }

    for (int i = 0; i < k; ++i) {
        if (gcd(l, r1 + i) != a[i]) {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}