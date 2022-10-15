#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = (int) 4e5 + 1234 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    multiset<int> st;
    bool ok = 1;
    st.insert(a[1]);
    auto it = st.find(a[1]);
    for (int i = 2; i <= n; i++) {
      int cur = a[i - 1];
      int nw = a[i];
      if (cur == nw) continue;
      if (nw < cur) {
        if (it == st.begin()) {
          st.insert(nw);
          it = st.begin();
          continue;
        }
        it--;
        if (*it > nw) {ok = 0; break;}
        if (*it != nw) {
          st.insert(nw);
          it = st.find(nw);
        }
      } else {
        it++;
        if (it == st.end()) {
          st.insert(nw);
          it = st.end();
          it--;
          continue;
        }
        if (*it < nw) {ok = 0; break;}
        if (*it != nw) {
          st.insert(nw);
          it = st.find(nw);
        }
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}