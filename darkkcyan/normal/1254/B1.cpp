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
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

vector<llong> find_prime_div(llong num) {
    vector<llong> ans;
    for (llong i = 2; i * i <= num; ++i) {
        if (num % i) continue;
        ans.push_back(i);
        while (num % i == 0) num /= i;
    }
    if (num != 1) ans.push_back(num);
    return ans;
}
#define maxn 1000010
const llong inf = 1e15;
int n;
llong a[maxn];

enum STATE { SGET, SGIVE};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];

    llong sum = accumulate(a, a + n, 0);

    auto primes = find_prime_div(sum);
    if (!len(primes)) {
        cout << -1;
        return 0;
    }

    llong ans = inf;
    for (auto p: primes) {
        llong cur_ans = 0;
        vector<int> cur_pos;
        rep(i, n) {
            if (a[i] == 1) cur_pos.push_back(i);
            if (len(cur_pos) != p) continue;
            for (auto f: cur_pos) 
                cur_ans += abs(cur_pos[p / 2] - f);
            cur_pos.clear();
        }
        ans = min(ans,cur_ans);
    }

    if (ans >= inf) ans = -1;
    cout << ans;

    return 0;
}