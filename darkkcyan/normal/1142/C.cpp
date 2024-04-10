#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 101010
#define point pair<llong, llong>

point operator-(point a, const point& b) {
  a.xx -= b.xx;
  a.yy -= b.yy;
  return a;
}

llong cross(const point& a, const point& b) {
  return a.xx * b.yy - a.yy * b.xx;
}


int n;
point a[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i].xx >> a[i].yy;
    rep(i, n) a[i].yy -= a[i].xx * a[i].xx;

    // rep(i, n) {
      // clog << a[i].xx << ' ' << a[i].yy << endl;
    // }

    sort(a, a + n, [](const point& u, const point& v) {
        if (u.xx == v.xx) return u.yy > v.yy;
        return u.xx < v.xx;
    });
    n = (int)(unique(a, a + n, [](const point& u, const point& v) { return u.xx == v.xx; }) - a);
    vector<point> hull;

    rep(i,n) {
      while (len(hull) > 1 and cross(a[i] - hull.back(), hull[len(hull) - 2] - hull.back()) >= 0) {
        hull.pop_back();
      }
      hull.push_back(a[i]);
    }

    // clog << "Hull" << endl;
    // for (auto i: hull) clog << i.xx << ' ' << i.yy << endl;
    cout << max(len(hull) - 1, 0);

    

    return 0;
}