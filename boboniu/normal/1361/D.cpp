#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int n, k;
map<pair<int, int>, vector<double>> point;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 0 && y == 0)
      continue;
    int d = gcd(x, y);
    if (d < 0)
      d = -d;
    point[make_pair(x / d, y / d)].push_back(sqrt(1. * x * x + 1. * y * y));
  }
  vector<double> delta;
  delta.push_back(0);
  for (auto points : point) {
    auto dis = points.second;
    sort(dis.begin(), dis.end());
    int pl = 0, pr = dis.size();
    double dl = 0, dr = 0;
    double tdis = 0;
    double pdis = 0;
    for (int p = 1; p <= dis.size(); p++) {
      if (p <= k / 2) {
        tdis += dr - (p - 1) * dis[pr - 1];
        dr += dis[pr - 1];
        pr -= 1;
      } else {
        tdis += dr - (k / 2) * dis[pl] + dis[pl] * (p - k / 2 - 1) - dl;
        dl += dis[pl];
        pl += 1;
      }
      double cdis = tdis + (dl + dr) * (k - p);
      delta.push_back(cdis - pdis);
      pdis = cdis;
    }
  }
  sort(delta.begin(), delta.end());
  reverse(delta.begin(), delta.end());
  double ans = 0;
  for (int i = 0; i < k; i++)
    ans += delta[i];
  printf("%.10f\n", ans);
}