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

int n;

vector<int> targ;
int cnt = 0;
int guess(vector<int> s) {
  map<int, int> v;
  if (cnt == 2 * n)
    assert(0);
  cnt++;
  for (int i = 0; i < n; i++)
    assert(1 <= s[i] && s[i] <= n);
  int ans = n + 1;
  for (int i = 0; i < n; i++) {
    int z = s[i] + targ[i];
    if (v.count(z))
      ans = min(ans, v[z]);
    v[z] = i;
  }
  if (ans != n + 1)
    return ans + 1;
  return 0;
}

int chk(int dt) {
  // pi + dt=pn
  int x, y;
  if (dt >= 1)
    x = dt + 1, y = 1;
  else
    x = 1, y = -dt + 1;
  cout << "? ";
  for (int i = 1; i < n; i++)
    cout << x << ' ';
  cout << y << endl;
  vector<int> p(n, x);
  p[n - 1] = y;
  int ans;
  cin >> ans;
  // ans = guess(p);
  return ans;
}

int ans[105];
signed main() {
  cin >> n;
  targ = vector<int>(n);
  // for (int i = 0; i < n; i++)
  //   cin >> targ[i];
  int pn = n;
  for (int i = 1; i < n; i++)
    if (chk(i) == 0) {
      pn = i;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (i != pn)
      ans[chk(pn - i)] = i;
  cout << "! ";
  for (int i = 1; i < n; i++)
    cout << ans[i] << ' ';
  cout << pn << endl;
  // vector<int> r(ans + 1, ans + n);
  // r.pb(pn);
  // assert(r == targ);
}