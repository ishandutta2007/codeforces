#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int) s.size(), p1, p2, cnt = 0;
    for (int i = 0; i < n; i++) if (s[i] == '1') p2 = i;
    for (int i = n - 1; i >= 0; i--) if (s[i] == '1') p1 = i, cnt++;
    if (cnt == 0) {
      cout << "0\n";
    } else {
      cout << p2 - p1 + 1 - cnt << "\n";
    }
  }

}