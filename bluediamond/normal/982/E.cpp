#include <bits/stdc++.h>
using namespace std;
#define int long long
int dimx, dimy, x, y, dx, dy, d, invx, invy, k, jump;
void print(int a, int b = -1) {
  if (b == -1) cout << "-1\n";
  else cout << ((invx) ? (dimx - a) : a) << " " << ((invy) ? (dimy - b) : b) << "\n";
  exit(0);
}
pair<int, int> gcd(int a, int b) {
  if (b == 0) {d = a; return {1, 0};}
  auto it = gcd(b, a % b);
  return {it.second, it.first - a / b * it.second};
}
signed main() {
  cin >> dimx >> dimy >> x >> y >> dx >> dy;
  if (dx == 0) {
    if (x == 0 || x == dimx) print(x, (dy == +1) ? dimy : 0);
    print(-1);
  }
  if (dy == 0) {
    if (y == 0 || y == dimy) print((dx == +1) ? dimx : 0, y);
    print(-1);
  }
  if (dx == -1) dx *= -1, invx ^= 1, x = dimx - x;
  if (dy == -1) dy *= -1, invy ^= 1, y = dimy - y;
  if (abs(x - y) % __gcd(dimx, dimy) != 0) print(-1);
  k = gcd(dimx, dimy).first * (x - y) / d, jump = abs(dimy / d);
  if (k <= (x - 1) / dimx) k += (((x - 1) / dimx - k) / jump + 1) * jump;
  if ((k - jump) >= (x + dimx - 1) / dimx) k -= (k - (x + dimx - 1) / dimx) / jump * jump;
  print((k & 1) ? dimx : 0, (((k * dimx - x + y) / dimy) & 1) ? dimy : 0);
  return 0;
}