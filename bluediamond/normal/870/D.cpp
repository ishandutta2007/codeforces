#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 7;
int n, a[N], b[N], p[N], inv[N];

int main() {
  cin >> n;
  /**

  pentru fiecare pereche (i, j) vreau sa stiu (pi^bj)
  dar nu vreau sa intrebe efectiv toate cele n^2 posibilitati
  asa ca bag o fenta:
  (pi^bj) = (pi^b0)^(p0^bj)^(b0^p0)

  **/
  for (int i = 0; i < n; i++) {
    cout << "? " << i << " " << 0 << endl;
    cin >> a[i];
    cout << "? " << 0 << " " << i << endl;
    cin >> b[i];
  }
  /**

  cum ar fi sa fixez p0?
  suna bine


  daca fixez b0

  atunci pi = (pi^b0)^b0

  **/
  int cnt = 0;
  vector<int> ret;
  for (int b0 = 0; b0 < n; b0++) {
    for (int i = 0; i < n; i++) {
      p[i] = a[i] ^ b0;
      inv[p[i]] = i;
    }
    bool good = 1;
    for (int i = 0; i < n; i++) {
      good &= ((p[i] ^ inv[0]) == a[i]);
      good &= ((inv[i] ^ p[0]) == b[i]);
    }
    if (good) {
      if (!cnt) {
        for (int i = 0; i < n; i++) {
          ret.push_back(p[i]);
        }
      }
      cnt++;
    }
  }
  cout << "!" << endl;
  cout << cnt << endl;
  for (auto &x : ret) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}