#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;
const ll MOD = 1e9+7;
ll f[N];
ll ans[N];
ll fac[N];
ll ifac[N];
ll twentysix[N];
ll twentyfive[N];

struct query {
    ll n, k, i;
    query() {}
    query(ll a, ll b, ll c) : n(a), k(b), i(c) {}
};
vector<query> queries[N];

ll modpow(ll b, ll p) {
    ll ans = 1;
    for (; p; p/=2, b=b*b%MOD) {
        if (p&1) ans = ans*b%MOD;
    }
    return ans;
}

void setup() {
    twentysix[0] = twentyfive[0] = fac[0] = ifac[0] = 1;
    for (int i=1; i<N; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        ifac[i] = ifac[i-1]*modpow(i, MOD-2)%MOD;
        twentysix[i] = twentysix[i-1]*26%MOD;
        twentyfive[i] = twentyfive[i-1]*25%MOD;
    }
}

ll choose(int n, int k) {
    return (fac[n]*ifac[n-k]%MOD)*ifac[k]%MOD;
}

void fill_to(int k, int nmax) {
    memset(f, 0, sizeof f);
    for (int i=k; i<=nmax; ++i) {
        f[i] = f[i-1]*26 + choose(i-1, k-1)*twentyfive[i-k];
        f[i] %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    int qc = 0;
    int m;
    cin >> m;
    string s;
    cin >> s;
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> s;
        } else if (t == 2) {
            int i = qc++;
            int n;
            cin >> n;
            int k = s.size();
            queries[k].push_back(query(n, k, i));
        }
    }

    for (int i=1; i<=100000; ++i) {
        if (queries[i].empty()) continue;
        int mx = 0;
        for (auto& q : queries[i]) {
            mx = max((ll) mx, q.n);
        }
        fill_to(i, mx);
        for (auto& q : queries[i]) {
            ans[q.i] = f[q.n];
        }
    }

    for (int i=0; i<qc; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}