#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int x[305], y[305], n;

int cross(int x1, int x2, int y1, int y2) {
  return x1*y2 - x2*y1;
}

double tri_area(int a, int b, int c) {
  return 0.5 * ( (x[a]+x[b])*(y[a] - y[b]) + (x[b]+x[c])*(y[b] - y[c]) + (x[c]+x[a])*(y[c] - y[a]) );
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> x[i] >> y[i];
  cout << setprecision(12) << fixed;
  double ans = 0;
  for(int i = 1; i < n; ++i) {
    for(int j = 0; j < i; ++j) {
      bool p[2] = {0, 0};
      double mx[2] = {0, 0};
      for(int k = 0; k < n; ++k) {
        if(k == i || k == j) continue;
        int c = cross(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i]);
        int r = c < 0;
        p[r] = 1;
        double a = abs(tri_area(i, j, k));
        if(a > mx[r])
          mx[r] = a;
      }
      if(!p[0] || !p[1]) continue;
      ans = max(ans, mx[0] + mx[1]);
    }
  }
      cout << ans << "\n";


  return 0;
}