#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define int ll
using namespace std;
struct fenwick {
    int dim = 1 << 18;
    vector<int> v;
    fenwick(int k) {
        dim = 1;
        while (dim < k) dim *= 2;
        v = vector<int>(dim);
    }
    void upd(int pos) {
        for (; pos < dim; pos += pos & -pos) v[pos]++;
    }
    int q(int pos) {
        int tot = 0;
        for (; pos; pos -= pos & -pos) tot += v[pos];
        return tot;
    }
};
static const int mod = 998244353;
vector<int> fact, inv_fact;
int pot(int a, int b) {
    if (b == 0) return 1;
    int x = pot(a, b / 2);
    if (b % 2) return x * x % mod * a % mod;
    return x * x % mod;
}
int binom(int n, int k) {
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

int N;
vector<int> v;
vector<int> p;
int sol(int pos, int presi, int last) {
    if (pos == v.size() && presi == N / 2) return 1;
    if (pos == v.size()) return 0;
    int tot = sol(pos + 1, presi, last);
    if (last == -1) {
        if (p[pos] > 0) tot += sol(pos + 1, presi + 1, pos) * p[pos];
    } else {
        if (v[pos] > v[last] && p[last] > 2 * presi - 1) tot += sol(pos + 1, presi + 1, pos) * (p[last] - 2 * presi + 1);
    }
    // cout << pos << " " << presi << " " << last << " " << tot << endl;
    return tot % mod;
}
void solve() {
    cin >> N;
    v.clear();
    p.clear();

    map<int, int> c;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.pb(x);
        c[x]++;
    }
    if (N == 2) {
        cout << (v[0] < v[1]) << '\n';
        return;
    }
    p.pb(0);
    for (int i = 1; i < N; i++) {
        if (v[i] == v[i - 1])
            p.pb(p.back());
        else
            p.pb(i);
    }
    int memo[N + 2];
    int tmp[N + 2];
    for (int i = 0; i < N + 2; i++) {
        tmp[i] = memo[i] = 0;
    }
    tmp[N / 2] = 1;
    int ans = 0;
    for (int i = N - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            for (int j = 0; j < N + 2; j++) {
                memo[j] = (memo[j] + tmp[j]) % mod;
                tmp[j] = 0;
            }
        }
        for (int presi = 1; presi <= N / 2; presi++) {
            if ((p[i] - 2 * presi + 1) <= 0) continue;
            int cur = memo[presi + 1] * (p[i] - 2 * presi + 1) % mod;
            tmp[presi] = (tmp[presi] + cur) % mod;
            if (presi == 1) ans += cur * p[i] % mod;
        }
    }
    ans %= mod;
    for (auto [a, b] : c) ans = ans * inv_fact[b] % mod;
    cout << ans << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact.pb(1);
    for (int i = 0; i < 1000010; i++) fact.pb(fact.back() * (i + 1) % mod);
    for (int x : fact) inv_fact.pb(pot(x, mod - 2));

    int T;
    cin >> T;
    while (T--) solve();
}