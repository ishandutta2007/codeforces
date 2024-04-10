#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 10;
const int M = (int) 2e5 + 7;
int n, cnt[N], a[N][M], m;
set<vector<int>> all;
set<pair<int, vector<int>>> st;

int eval(vector<int> v) {
  int sol = 0;
  for (int i = 0; i < n; i++) {
    sol += a[i][v[i]];
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cnt[i];
    for (int j = 0; j < cnt[i]; j++) {
      cin >> a[i][j];
    }
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    vector<int> v(n);
    for (auto &x : v) {
      cin >> x;
      x--;
    }
    all.insert(v);
  }
  vector<int> base(n);
  for (int i = 0; i < n; i++) {
    base[i] = cnt[i] - 1;
  }
  st.insert({eval(base), base});
  while (1) {
    assert(!st.empty());
    auto it = st.end();
    it--;
    int now = it->first;
    vector<int> v = it->second;
    st.erase(it);
    if (!all.count(v)) {
      for (auto &it : v) {
        cout << it + 1 << " ";
      }
      cout << "\n";
      return 0;
    }
    for (int i = 0; i < n; i++) {
      vector<int> variant = v;
      if (variant[i] >= 1) {
        variant[i]--;
        st.insert({now - a[i][v[i]] + a[i][v[i] - 1], variant});
      }
    }
  }
  assert(0);



  return 0;
}