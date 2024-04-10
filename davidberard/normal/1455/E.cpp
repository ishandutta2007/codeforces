#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Pt {
  ll x, y;
};
ostream& operator<< (ostream& o, const Pt& p) {
  return o << "(" << p.x << "," << p.y << ")";
}

ll solve(const vector<Pt>& pts) {
  Pt a = pts[0];
  Pt b = pts[1];
  Pt c = pts[2];
  Pt d = pts[3];
  ll base = abs(b.x-c.x) + abs(a.x-d.x) + abs(a.y-b.y) + abs(c.y-d.y);
  pair<ll, ll> xseg = {min(a.x,d.x) - max(b.x,c.x), max(a.x,d.x) - min(b.x,c.x)};
  pair<ll, ll> yseg = {min(a.y,b.y) - max(c.y,d.y), max(a.y,b.y) - min(c.y,d.y)};
  base += 2*max(0LL, max(xseg.first-yseg.second, yseg.first-xseg.second));
  return base;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  vector<Pt> qts;
  vector<Pt> pts(4);
  while (TT--) {
    for (auto& p : pts) {
      cin >> p.x >> p.y;
    }
    vector<int> perm({0,1,2,3});
    ll ans = 1e10;
    do {
      qts.clear();
      for (int i=0; i<4; ++i) {
        qts.push_back(pts[perm[i]]);
      }
      ans = min(ans, solve(qts));
    } while(next_permutation(perm.begin(), perm.end()));

    cout << ans << "\n";
  }
  return 0;
}