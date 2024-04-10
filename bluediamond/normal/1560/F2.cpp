#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int num, k, digits[100], y;
ll sol;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> num >> k;
    y = 0;
    sol = 1;
    while (num) {
      digits[++y] = num % 10;
      num /= 10;
    }
    reverse(digits + 1, digits + y + 1);
    for (int i = 1; i <= y; i++) {
      sol = 10 * sol + (k == 1);
    }
    set<int> c;
    /// incerc ac. lungime
    for (int pref = 0; pref <= y; pref++) {
      if (pref) {
        c.insert(digits[pref]);
        if ((int) c.size() > k) {
          break;
        }
      }
      if (pref == y) {
        sol = 0;
        for (int j = 1; j <= pref; j++) {
          sol = 10 * sol + digits[j];
        }
        break;
      }
      for (int d = digits[pref + 1] + 1; d <= 9; d++) {
        int newSize = (int) c.size() + (!c.count(d));
        int rem = k - newSize;
        if (rem < 0) continue;

        sol = 0;
        for (int j = 1; j <= pref; j++) {
          sol = 10 * sol + digits[j];
        }
        int append = (rem == 0) ? (c.empty() ? d : min(d, *c.begin())) : 0;
        sol = 10 * sol + d;
        for (int j = pref + 2; j <= y; j++) {
          sol = 10 * sol + append;
        }
        break;
      }
    }
    cout << sol << "\n";
  }

  return 0;
}