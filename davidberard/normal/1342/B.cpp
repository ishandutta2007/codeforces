#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    string t;
    cin >> t;
    set<char> st;
    for (auto& c : t) {
      st.insert(c);
    }
    if (st.size() == 1) {
      cout << t << endl;
      continue;
    }
    for (int i=0; i<t.size(); ++i) {
      if (t[0] == 0) {
        cout << "01";
      } else {
        cout << "10";
      }
    }
    cout << endl;
  }
  return 0;
}