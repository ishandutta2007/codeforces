#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;

stack<pair<int, int>> st;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void nbrs(int i, int j) {
  for (int r=0; r<4; ++r) {
    int ii = i+dx[r];
    int jj = j+dy[r];
    if (ii < 0 || jj < 0 || ii >= n || jj >= n) {
      continue;
    }
    st.push({ii, jj});
  }
}

void solve() {
  cin >> n;
  vector<vector<int>> take(n, vector<int>(n, 0));
  vector<vector<int>> amt(n, vector<int>(n, 0));
  for (int i=1; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      if (!amt[i-1][j]) {
        nbrs(i, j);
        take[i][j] ^= 1;
        while (!st.empty()) {
          auto [ii, jj] = st.top(); st.pop();
          amt[ii][jj] ^= 1;
        }
      }
    }
  }
  int ans = 0;
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      int x;
      cin >> x;
      ans ^= x * take[i][j];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    solve();
  }
  return 0;
}