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
int n, k;
llong p;
llong a[maxn];
llong b[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n >> p >> k;
        rep(i, n) cin >> a[i];
        sort(a, a + n);
        fill(b, b + n + 10, 0);

        int ans = 0;

        rep1(i, k - 1) {
            b[i] = b[i - 1] + a[i - 1];
            if (b[i] <= p) ans = i;
        }

        for (int i = k; i <= n; ++i) {
            b[i % k] += a[i - 1];
            if (b[i % k] <= p) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}