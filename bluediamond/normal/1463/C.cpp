#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = (int) 1e5 + 7;
int n;
int t[N];
int x[N];

struct Move {
  int t1;
  int t2;
  int x1;
  int x2;
};

vector<Move> v;

int what(int t) {
  int l = 0, r = (int) v.size() - 1, pos = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (v[m].t1 <= t) {
      pos = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  if (t >= v[pos].t2) {
    return v[pos].x2;
  } else {
    if (v[pos].x1 <= v[pos].x2) {
      return v[pos].x1 + t - v[pos].t1;
    } else {
      return v[pos].x1 - (t - v[pos].t1);
    }
  }
  assert(pos != -1);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> t[i] >> x[i];
    }
    t[n + 1] = (int) 1e18;
    v.clear();
    v.push_back({0, 0, 0, 0});
    int pos = 0, ajuns = 0;
    for (int i = 1; i <= n; i++) {
      if (ajuns <= t[i]) {
        ajuns = t[i] + abs(pos - x[i]);
        v.push_back({t[i], ajuns, pos, x[i]});
        pos = x[i];

      }
    }
    /**for (auto &it : v) {
      cout << it.t1 << " " << it.t2 << " " << it.x1 << " " << it.x2 << "\n";
    }**/
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (what(t[i]) <= x[i] && what(t[i + 1]) >= x[i]) {
        sol++;
        continue;
      }
      if (what(t[i]) >= x[i] && what(t[i + 1]) <= x[i]) {
        sol++;
        continue;
      }
    }
    cout << sol << "\n";
    continue;
    for (int i = 0; i <= 40; i++) {
      cout << what(i) << " ";
    }
    cout << "\n";
   // cout << sol << "\n";
  }

}