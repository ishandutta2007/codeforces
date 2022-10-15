#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n;
    string s;
    cin >> n >> s;
    assert((int) s.size() == n);
    /// 00 => cost += 2
    /// 010 => cost += 1
    int cost = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (s[i] == '0' && s[i + 1] == '0') {
        cost += 2;
      }
    }
    for (int i = 0; i + 2 < n; i++) {
      if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') {
        cost += 1;
      }
    }
    cout << cost << "\n";
  }


  return 0;
}