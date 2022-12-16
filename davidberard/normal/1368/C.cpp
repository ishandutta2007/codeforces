#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  set<pair<int, int>> st;
  for (int i=0; i<=n; ++i) {
    st.insert(pair<int, int>(i*2, i*2));
    st.insert(pair<int, int>(i*2, i*2+1));
    st.insert(pair<int, int>(i*2, i*2+2));
    st.insert(pair<int, int>(i*2+1, i*2));
    st.insert(pair<int, int>(i*2+1, i*2+2));
    st.insert(pair<int, int>(i*2+2, i*2));
    st.insert(pair<int, int>(i*2+2, i*2+1));
    st.insert(pair<int, int>(i*2+2, i*2+2));
  }
  cout << st.size() << "\n";
  for (auto& p : st) {
    cout << p.first << " " << p.second << "\n";
  }
  return 0;
}