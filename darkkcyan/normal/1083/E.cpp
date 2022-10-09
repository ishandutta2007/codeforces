#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }

template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

template<typename T> 
struct p3 {
  T x, y, z;
  p3() {}
  p3(T _x, T _y, T _z): x(_x), y(_y), z(_z) {}

  T dot(const p3& other) {
    return x * other.x + y * other.y + z * other.z;
  }

  p3 cross(const p3& other) {
    return p3(
      y * other.z - z * other.y,
      z * other.x - x * other.z,
      x * other.y - y * other.x
    );
  }

  T getY(T arg) {
    return (x * arg + z) / -y;
  }

  p3<T>& normalize() {
    x /= z;
    y /= z;
    z = 1;
    return *this;
  }
};

ostream& operator<< (ostream& cout, const p3<llong> a) {
  return cout << "[" << a.x << ", " << a.y << ", " << a.z << "]";
}

#define sgn(x) ((x) < 0 ? -1 : (x) > 0)
#define line p3<long double>
#define point p3<long double>
#define makeline(k, b) p3<long double>(k, -1, b)
#define intersect(line1, line2) line1.cross(line2).normalize()
#define pointIsUnderLine(point, line) ((point).dot(line) <= 0)

#define maxn 1010101
int n;
pair<pair<llong, llong>, llong> a[maxn];
llong dp[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i].xx.xx >> a[i].xx.yy >> a[i].yy;
  sort(a, a + n);
  //clog << tovec(a, a + n) << endl;
  deque<line> hull;

  hull.push_front(makeline(0, 0));
  llong ans = 0;
  rep(i, n) {
    //clog << i << endl;
    llong arg = -a[i].xx.yy;
    while (len(hull) > 1 and hull[0].getY(arg) >= hull[1].getY(arg))
      hull.pop_front();
    dp[i] = (llong)(a[i].xx.xx * a[i].xx.yy - a[i].yy - hull.front().getY(arg));
    //clog << tovec(hull) << ' ' << hull.front().getY(arg) << endl;
    ans = max(ans, dp[i]);
    line nl = makeline(-a[i].xx.xx, -dp[i]);
    while (len(hull) > 1 and pointIsUnderLine(intersect(hull[len(hull) - 2], hull.back()), nl)) {
      hull.pop_back();
    }
    hull.push_back(nl);
    //clog << tovec(hull) << endl;
  }
  //clog << tovec(dp, dp + n) << endl;
  cout << ans;

  return 0;
}