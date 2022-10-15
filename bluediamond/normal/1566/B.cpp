/**

48 -> 8:17

**/

#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> t;
  while (t--) {
    cin >> s;
    /// 0 sau 6
    int n = (int) s.size(), first0 = -1, last0 = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        last0 = i;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        first0 = i;
      }
    }
    if (first0 == -1) {
      cout << "0\n";
    } else {
      set<int> st;
      for (int j = first0; j <= last0; j++) {
        st.insert(s[j] - '0');
      }
      int mex = 0;
      while (st.count(mex)) {
        mex++;
      }
      cout << mex << "\n";
    }
  }
  return 0;
}