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
llong a[maxn];

bool ok(llong x) {
    llong t = k;
    for (int i = n / 2; i < n; ++i) {
        if (x <= a[i]) continue;
        t -= x - a[i];
    }
    return t >= 0;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    sort(a, a + n);

    llong l = 0, r = 1;
    while (ok(r)) r *= 2;
    while (r - l > 1) {
        llong mid = l + (r - l) / 2;
        if (ok(mid)) l = mid;
        else r = mid;
    }
    cout << l;

    return 0;
}