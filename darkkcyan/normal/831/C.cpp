#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i =-1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)

#define maxn 2222
int n, k;
int a[maxn], b[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> k >> n;
  rep1(i, k) cin >> a[i];
  rep1(i, n) cin >> b[i];

  rep1(i, k) a[i] += a[i - 1];
  sort(b + 1, b + n + 1);
  sort(a + 1, a + k + 1);

  k = unique(a + 1, a + k + 1) - a - 1;
  
  int ans = 0;
  rep1(i, k) {
    int d = b[1] - a[i];
    rep1(f, k) a[f] += d;
    bool ok = 1;
    rep1(f, n) {
      if (!binary_search(a + 1, a + k + 1, b[f])) {
        ok = 0;
        break;
      }
    }
    ans += ok;
  }

  cout << ans;

  return 0;
}