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

#define maxn 201010
int n, m;
llong a[maxn], psum[maxn];
llong ans[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    psum[0] = 0;
    rep(i, n) psum[i + 1] = psum[i] + a[i];

    rep(mod, m) {
        llong cur = 0;
        for (int i = mod; i <= n; i += m) {
            cur += psum[i] - psum[0];
            ans[i] = cur;
        }
    }

    rep1(i, n) cout << ans[i] << ' ';;

    return 0;
}