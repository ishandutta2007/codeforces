#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

bool test(string a, string b, char c) {
  string ans;
  int x = 0, y = 0;
  while (1) {
    int c1 = 0, c2 = 0;
    while (x != a.size() && a[x] != c)
      c1++, x++;
    while (y != b.size() && b[y] != c)
      c2++, y++;
    c1 = max(c1, c2);
    while (c1--)
      ans += '0' + '1' - c;
    if (x != a.size() && y != b.size()) {
      ans += c;
      x++, y++;
    } else
      break;
  }
  while (x != a.size())
    ans += a[x], x++;
  while (y != b.size())
    ans += b[y], y++;
  if (ans.size() <= (a.size()) / 2 * 3) {
    cout << ans << endl;
    return 1;
  }
  return 0;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    bool g = test(a, b, '0') || test(a, c, '0') || test(b, c, '0') ||
             test(a, b, '1') || test(a, c, '1') || test(b, c, '1');
    assert(g);
  }
}