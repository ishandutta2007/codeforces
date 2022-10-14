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

bool check_collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
  x1 -= x3, y1 -= y3;
  x2 -= x3, y2 -= y3;
  return 1ll * x1 * (-y2) + 1ll * y1 * x2 == 0;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pii> points(n);
  vector<int> ids(n);
  iota(all(ids), 0);
  for (int i = 0; i < n; i++)
    cin >> points[i].fi >> points[i].se;
  sort(all(ids), [&](int i, int j) { return points[i] < points[j]; });
  for (int i = 2; i < n; i++)
    if (!check_collinear(points[ids[0]].fi, points[ids[0]].se,
                         points[ids[1]].fi, points[ids[1]].se,
                         points[ids[i]].fi, points[ids[i]].se)) {
      cout << ids[0] + 1 << ' ' << ids[1] + 1 << ' ' << ids[i] + 1 << endl;
      return 0;
    }
}