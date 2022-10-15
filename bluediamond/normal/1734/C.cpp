#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
int n;
int want[N];
int have[N];

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ///freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    assert((int) s.size() == n);
    for (int i = 1; i <= n; i++) {
      char ch = s[i - 1];
      assert(ch == '0' || ch == '1');
      want[i] = ch - '0';
      assert(want[i] == 0 || want[i] == 1);
      have[i] = 1;
    }
    ll sol = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        if (have[j] == 0) {
          continue;
        }
        assert(have[j]);
        if (want[j]) {
          break;
        }
        have[j] = 0;
        sol += i;
      }
      assert(have[i] == want[i]);
    }
    cout << sol << "\n";
  }

  return 0;
}