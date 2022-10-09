#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; ) 

struct rect {
  int minx, maxx, miny, maxy;
  rect() {}
  rect(int m, int n, int p, int q)
    : minx(m), maxx(n), miny(p), maxy(q) {}
  bool exist() {
    return minx <= maxx and miny <= maxy;
  }
};

rect join(const rect& u, const rect& v) {
  return rect(
      max(u.minx, v.minx),
      min(u.maxx, v.maxx),
      max(u.miny, v.miny),
      min(u.maxy, v.maxy)
  );
}

#define maxn 201010
int n;
rect a[maxn], up[maxn], down[maxn];
rect all(INT_MIN, INT_MAX, INT_MIN, INT_MAX);

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i].minx >> a[i].miny >> a[i].maxx >> a[i].maxy;
  up[0] = a[0];
  down[n - 1] = a[n - 1];
  rep1(i, n - 1) up[i] = join(up[i - 1], a[i]);
  for (int i = n - 1; i--; ) down[i] = join(down[i + 1], a[i]);
  
  rep(i, n) {
    rect t = join(i ? up[i - 1] : all, i < n - 1 ? down[i + 1] : all);
    if (t.exist()) {
      cout << t.minx << ' ' << t.miny;
      return 0;
    }
  }
  assert(false);

  return 0;
}