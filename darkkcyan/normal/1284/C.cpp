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

#define maxn 250101
llong n, m;

llong fac[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    fac[0] = 1;
    rep1(i, n + 10) fac[i] = fac[i - 1] * i % m;

    llong ans = 0;
    rep1(i, n) {
        llong inner = fac[i] * (n - i + 1) % m;
        llong outter = fac[n - i];
        llong places = n - i + 1;
        llong cur_ans = inner * outter % m * places % m;
        (ans += cur_ans) %= m;
    }
    cout << ans;

    return 0;
}