#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 2e5 + 7;
int n;
int a[N];
int s[N];
int sol;
set<pair<int, int>> st;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    auto it = st.lower_bound({s[i - 1] - a[i], 0});
    while (it != st.end()) {
      int j = it->second;
      it++;
      sol += ((a[i] ^ a[j]) == (s[i - 1] - s[j]));
    }
    if (i >= 2) {
      st.insert({a[i - 1] + s[i - 1], i - 1});
    }
  }
  cout << sol << "\n";
}