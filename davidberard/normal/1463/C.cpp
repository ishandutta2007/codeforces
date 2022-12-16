#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n;

struct Line {
  ll m, b;
  ll start, finish;
  ll eval(ll t) const {
    if (t < start) {
      assert(false);
    }
    if (t >= finish) {
      return m*finish+b;
    }
    return m*t + b;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (auto& [t, x] : v) {
      cin >> t >> x;
    }
    vector<Line> ops;
    ops.push_back({0, 0, 0, 0});
    int ans = 0;
    for (auto& [t, x] : v) {
      if (ops.back().finish <= t) {
        ll oldx = ops.back().eval(ops.back().finish);
        ll m = (x < oldx ? -1 : 1);
        ll b = oldx - m*t;
        ll start = t;
        ll finish = t + abs(x-oldx);
        ops.push_back({m, b, start, finish});
        //cerr << "START " << start << " FINISH " << finish << " x oldx " << x << " " << oldx << " :: " << ops.back().eval(finish) << endl;
      }
    }
    int j= 1;
    for (int i=0; i<v.size(); ++i) {
      ll t = v[i].first;
      ll x = v[i].second;
      ll tnext = (i+1 < v.size() ? v[i+1].first : 0x3f3f3f3f3f);
      if (j+1<ops.size() && ops[j+1].start == t) {
        ++j;
      }
      //cerr << t << " TO " << tnext << " J " << j << endl;
      if (ops[j].m == 1 && ops[j].eval(t) <= x && x <= ops[j].eval(tnext)) {
        ++ans;
      }
      if (ops[j].m == -1 && ops[j].eval(tnext) <= x && x <= ops[j].eval(t)) {
        ++ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}