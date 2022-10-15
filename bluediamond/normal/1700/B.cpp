#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    assert((int) s.size() == n);

    if (s[0] != '9') {
      for (int i = 0; i < n; i++) {
        cout << 9 - (s[i] - '0');
      }
      cout << "\n";
      continue;
    }
   /// cout << "???\n";
    vector<int> digits;
    for (int i = n - 1; i >= 0; i--) {
      int digit = s[i] - '0';
      assert(0 <= digit && digit <= 9);
      digits.push_back(1 - digit);
    }
    digits.push_back(1);
    for (int i = 0; i < (int) digits.size(); i++) {
      if (digits[i] < 0) {
        assert(i + 1 < (int) digits.size());
        digits[i + 1]--;
        digits[i] += 10;
      }
      assert(0 <= digits[i] && digits[i] <= 9);
    }
    assert(digits.back() == 0);
    for (int i = (int) digits.size() - 2; i >= 0; i--) {
      cout << digits[i];
    }
    cout << "\n";
  }
}