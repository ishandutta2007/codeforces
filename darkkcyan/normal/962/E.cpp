#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

vector<llong> a, b;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  llong ans = 0;
  llong lastp = INT_MIN;
  rep(_, n) {
    llong u; char c; cin >> u >> c;
    if (c == 'B') a.push_back(u);
    if (c == 'R') b.push_back(u);
    if (c != 'P') continue;
    if (!len(a)) a.push_back(u);
    if (!len(b)) b.push_back(u);
    if (lastp == INT_MIN) {
      ans += 2 * u - a[0] - b[0];
    } else {
      llong c1 = 2 * (u - lastp);
      llong c2 = 3 * (u - lastp);
      llong m1 = max(a[0] - lastp, u - a.back()), m2 = max(b[0] - lastp, u - b.back());
      rep(i, len(a) - 1) m1 = max(m1, a[i + 1] - a[i]);
      rep(i, len(b) - 1) m2 = max(m2, b[i + 1] - b[i]);
      c2 -= m1 + m2;
      ans += min(c1, c2);
    }
    clog << ans << endl;
    lastp = u;
    a.clear();
    b.clear();
  }
  if (!len(a)) a.push_back(lastp);
  if (!len(b)) b.push_back(lastp);
  if (lastp != INT_MIN)
    ans += a.back() + b.back() - 2 * lastp;
  else ans += a.back() + b.back() - a[0] - b[0];
  cout << ans;

  return 0;
}