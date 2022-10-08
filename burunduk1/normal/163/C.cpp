#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<double,int> pnt;
#define x first
#define y second

int main (void) {
  int n, l, v1, v2;
  scanf ("%d%d%d%d", &n, &l, &v1, &v2);
  double d = (double)l * v2 / (v1 + v2);
  vector <pnt> v(n);
  v.push_back (pnt (0., 0));
  v.push_back (pnt (2. * l, 0));
  for (int i = 0; i < n; i++) {
    double a;
    scanf ("%lf", &a);

    double x = a - d;
    if (x < 0) {
      v.push_back (pnt (2 * l + x, +1));
      v.push_back (pnt (2 * l, -1));
      x = 0;
    }
    v.push_back (pnt (x, +1));
    v.push_back (pnt (a, -1));
  }
  sort (v.begin(), v.end());

  double p = 0;
  int cnt = 0;
  vector <double> res(2 * n, 0);
  for (int i = 0; i < (int)v.size(); i++) {
    res[cnt] += v[i].x - p;
    p = v[i].x;
    cnt += v[i].y;
  }
  for (int i = 0; i <= n; i++) {
    printf ("%.20lf\n", res[i] / (2 * l));
  }
  return 0;
}