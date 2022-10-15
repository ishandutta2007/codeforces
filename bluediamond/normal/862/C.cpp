#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> a;
  for (int i = 0; i <= (int) 1e6; i++) {
    a.push_back(i);
  }
  int n, x;
  cin >> n >> x;
  if (n == 2 && x == 0) {
    cout << "NO\n";
    return 0;
  }
  while (1) {
    shuffle(a.begin(), a.end(), rng);
    int val = x;
    for (int i = 0; i < n - 1; i++) {
      val ^= a[i];
    }
    bool good = 1;
    for (int i = 0; i < n - 1; i++) {
      if (val == a[i]) {
        good = 0;
        break;
      }
    }
    if (good && val <= (int) 1e6) {
      cout << "YES\n";
      a[n - 1] = val;
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
      cout << "\n";
      return 0;
    }
  }
}