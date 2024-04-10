#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 100 + 7;
int n, vb, vs, x[N], sx, sy;

ld dist(int i) {
  ld dx = sx - x[i];
  ld dy = sy;
  return sqrt(dx * dx + dy * dy);
}

ld tt(int i) {
  ld t1 = (ld) x[i] / vb;
  ld t2 = (ld) dist(i) / vs;
  return t1 + t2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> vb >> vs;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  cin >> sx >> sy;
  int i = 2;
  for (int j = 3; j <= n; j++) {
    if (tt(j) - tt(i) < 1e-14) {
      i = j;
    }
  }
  cout << i << "\n";
}