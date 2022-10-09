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

#define maxn 201010
int n, m, ta, tb, k;
llong a[maxn], b[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> ta >> tb >> k;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    if (k >= n) {
        cout << -1;
        return 0;
    }
    
    llong ans = LLONG_MIN;
    rep(i, k + 1) {
        int f = (int)(lower_bound(b, b + m, a[i] + ta) - b);
        // clog << i << ' ' << f << ' ' << f + (k - i) << endl;
        if (f + (k - i) >= m) {
            cout << -1;
            return 0;
        }
        ans = max(ans, b[f + (k - i)] + tb);
    }
    cout << ans;

    return 0;
}