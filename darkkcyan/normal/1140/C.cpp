#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 301010
int n, k;
pair<llong, llong> a[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    rep(i, n) cin >> a[i].yy >> a[i].xx;
    sort(a, a + n);

    llong ans = 0;
    multiset<llong> se;
    llong s = 0;
    for (int i = n; i--; ) {
      s += a[i].yy;
      se.insert(a[i].yy);
      if (len(se) > k) {
        s -= *se.begin();
        se.erase(se.begin());
      }
      ans = max(ans, a[i].xx * s);
    }
    cout << ans;
    return 0;
}