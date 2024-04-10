#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC optimize("O3")
///#pragma GCC optimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 1000 + 7;
int n;

struct pt {
  ld x, y;
} a[N];

ld area(pt a, pt b) {
  return (a.x - b.x) * (a.y + b.y) * 0.5;
}

ld area(pt a, pt b, pt c) {
  return fabs(area(a, b) + area(b, c) + area(c, a));
}

ld dist(pt p1, pt p2) {
  ld dx = p1.x - p2.x;
  ld dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

ld get(pt p1, pt p2, pt p3) {
  ld total = area(p1, p2, p3);
  ld base = dist(p1, p3);
  return total / base;
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  a[n + 1] = a[1];
  a[n + 2] = a[2];
  ld ret = (ld) 1e18;
  for (int i = 1; i <= n; i++) {
    ret = min(ret, get(a[i], a[i + 1], a[i + 2]));
  }
  cout << fixed << setprecision(6) << ret << "\n";
  return 0;
}