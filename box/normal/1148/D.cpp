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

pii c[300005];

vector<int> cal(vector<int> pos, bool mod) {
  sort(pos.begin(), pos.end(), [&](int a, int b) {
    if (!mod)
      return c[a].se > c[b].se;
    else
      return c[a].se < c[b].se;
  });
  return pos;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> X, Y;
  for (int i = 0; i < n; i++) {
    cin >> c[i].fi >> c[i].se;
    if (c[i].fi < c[i].se)
      X.push_back(i);
    else
      Y.push_back(i);
  }
  if (X.size() > Y.size()) {
    auto g = cal(X, 0);
    cout << X.size() << endl;
    for (int i : g)
      cout << i + 1 << " ";
    cout << endl;
  } else {
    auto g = cal(Y, 1);
    cout << Y.size() << endl;
    for (int i : g)
      cout << i + 1 << " ";
    cout << endl;
  }
}