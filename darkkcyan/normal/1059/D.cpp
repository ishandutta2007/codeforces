#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

template<typename T>
ostream& operator<<(ostream& cout, const vector<T>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v>
ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxn 101010
#define double long double
int n;
pair<double, double> a[maxn];

bool ok(double r) {
  double minr = -1e30, maxr = 1e30;
  rep(i, n) {
    if (a[i].yy > 2 * r) return false;
    double l = sqrt(a[i].yy * (2 * r - a[i].yy));
    double mi = a[i].xx - l, ma = a[i].xx + l;
    if (mi > maxr || ma < minr) return false;
    minr = max(minr, mi);
    maxr = min(maxr, ma);
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  bool hasl = 0, hasr = 0;
  rep(i, n) {
    cin >> a[i].xx >> a[i].yy;
    (a[i].yy < 0 ? hasl : hasr) = 1;
    if (a[i].yy < 0) a[i].yy = -a[i].yy;
  }
  if (hasr and hasl) {
    cout << -1;
    return 0;
  }

  double l = 0, r = 1;
  while (!ok(r)) r *= 2.0;
  rep(_, 200) {
    double mid = (l + r) / 2;
    if (ok(mid)) r = mid;
    else l = mid;
  }
  cout << fixed << setprecision(10) << l;

  return 0;
}