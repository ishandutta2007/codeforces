#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 1010
bool not_prime[maxn * maxn];
vector<int> primes;
void prime_sieve(int n) {
    memset(not_prime, 0, sizeof(not_prime));
    for (int i = 2; i <= n ;++i) {
        if (not_prime[i]) continue;
        primes.push_back(i);
        for (llong f = 1ll * i * i; f <= n; f += i)
            not_prime[f] = 1;
    }
}

pair<int, int> find_2_prime(int x) {
    assert(x > 2);
    assert(x % 2 == 0);
    for (auto f: primes) {
        assert(f < x);
        if (!not_prime[x - f]) return {f, x -f};
    }
    assert(false);
    return {0, 0};
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    prime_sieve(n * n);

    int ans = n;
    while (not_prime[ans]) ++ans;
    cout << ans << '\n';

    auto spec = find_2_prime((ans - n + 2) * 2);
    int u = spec.xx, v = spec.yy;
    vector<pair<int, int>> deg;
    deg.emplace_back(u, 1);
    deg.emplace_back(v, 2);
    rep(i, n - 2) deg.emplace_back(2, i + 3);
    while (len(deg)) {
        sort(deg.rbegin(), deg.rend());
        while (len(deg) and deg.back().xx == 0) deg.pop_back();
        if (!len(deg)) break;
        rep1(i, deg[0].xx) {
            cout << deg[0].yy << ' ' << deg[i].yy << '\n';
            --deg[i].xx;
        }
        deg[0].xx = 0;
    }


    return 0;
}