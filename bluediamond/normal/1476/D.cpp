#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 3e5 + 7;
int n, lft[N], rgh[N], p1[N], p2[N];
string s;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
      rgh[i] = (s[i] == 'R');
    }
    for (int i = 1; i <= n; i++) {
      lft[i] = (s[i - 1] == 'L');
    }
    for (int i = n; i >= 0; i--) {
      int j = i;
      while (j < n) {
        if (abs(i - j) == 2) {
          j = p2[j];
          break;
        }
        if (rgh[j] == (j - i + 1) % 2) {
          j++;
        } else {
          break;
        }
      }
      p2[i] = j;
    }
    for (int i = 0; i <= n; i++) {
      int j = i;
      while (j) {
        if (abs(i - j) == 2) {
          j = p1[j];
          break;
        }
        if (lft[j] == (i - j + 1) % 2) {
          j--;
        } else {
          break;
        }
      }
      p1[i] = j;
      cout << p2[i] - p1[i] + 1 << " ";
    }
    cout << "\n";
  }
}