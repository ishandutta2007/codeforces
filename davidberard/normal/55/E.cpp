#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Pt {
  ll x, y;
  Pt operator+ (const Pt& o) { return {x+o.x, y+o.y}; }
  Pt operator- (const Pt& o) { return {x-o.x, y-o.y}; }
};

ll cp(const Pt& a, const Pt& b) { return a.x*b.y - a.y*b.x; }

const int N = 100100;
Pt p[N];
int n;

ll choose3(ll x) {
  return x*(x-1)*(x-2)/6;
}

ll choose2(ll x) {
  return x*(x-1)/2;
}

ll solve(ll _x, ll _y) {
  Pt ctr = {_x, _y};
  int j = 1;
  ll ans = choose3(n);
  for (int i=0; i<n; ++i) {
    if (cp(p[(i+1)%n]-p[i], ctr-p[i]) > 0) {
      return 0;
    }
    while (cp(p[(j+1)%n]-p[i], ctr-p[i]) < 0) {
      ++j;
    }
    //cerr << " I " << i << " J " << j << endl;
    ans -= choose2(j-i);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> p[i].x >> p[i].y;
  }
  int TT;
  cin >> TT;
  while (TT--) {
    int x, y;
    cin >> x >> y;
    ll ans= solve(x, y);
    cout << ans << "\n";
  }
  return 0;
}