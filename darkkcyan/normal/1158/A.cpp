#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 101010
int n, m;
llong a[maxn], b[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a, a + n, greater<int>());
    auto min_b = *min_element(b, b + m);
    if (a[0] > min_b) {
      cout << -1;
      return 0;
    }

    bool eq_max = a[0] == min_b;

    llong ans = 0;
    rep(i, m) ans += b[i];
    rep(i, n) ans += a[i] * m;
    ans -= a[0] * (m - 1) + (eq_max ? a[0] : a[1]);
    cout << ans;

    return 0;
}