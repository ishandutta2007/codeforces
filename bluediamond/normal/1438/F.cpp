#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));
int n;
int f[1 << 18];

signed main() {
  cin >> n;
  n = (1 << n) - 1;
  for (int i = 1; i <= 422; i++) {
    int x, y, z;
    do {
      x = rng() % n + 1;
      y = rng() % n + 1;
      z = rng() % n + 1;
    } while (x == y || x == z || y == z);
    cout << "? " << x << " " << y << " " << z << endl;
    cin >> x;
    f[x]++;
  }
  vector<pair<int, int>> p;
  for (int i = 1; i <= n; i++) {
    p.push_back({f[i], i});
  }
  sort(p.rbegin(), p.rend());
  int x = p[0].second, y = p[1].second;
  vector<int> rem;
  for (int i = 1; i <= n; i++) {
    if (x != i && y != i) {
      rem.push_back(i);
    }
  }
  shuffle(rem.begin(), rem.end(), rng);
  for (int i = 0; i < (int) rem.size() - 1; i++) {
    int z = rem[i], t;
    cout << "? " << x << " " << y << " " << z << endl;
    cin >> t;
    if (t == z) {
      cout << "! " << t << endl;
      return 0;
    }
  }
  cout << "! " << rem.back() << endl;
}