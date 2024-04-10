#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, a[N], c[N];
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      a[i] = s[i - 1] - '0';
    }

    bool ok = 0;
    for (int pivot = 0; pivot <= 10; pivot++) {
      for (int i = 1; i <= n; i++) {
        c[i] = 2;
      }
      int last = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] < pivot) {
          c[i] = 1;
          last = i;
        }
      }
      for (int i = last + 1; i <= n; i++) {
        if (a[i] == pivot) {
          c[i] = 1;
        }
      }
      vector <int> x, y;
      for (int i = 1; i <= n; i++) {
        if (c[i] == 1) {
          x.push_back(a[i]);
        } else {
          y.push_back(a[i]);
        }
      }
      vector <int> sx = x, sy = y;
      sort(sx.begin(), sx.end());
      sort(sy.begin(), sy.end());
      if (x == sx && y == sy) {
        ok = 1;
        for (int i = 1; i <= n; i++) {
          cout << c[i];
        }
        cout << '\n';
        break;
      }
    }
    if (ok == 0) {
      cout << "-\n";
    }
  }

  return 0;
}