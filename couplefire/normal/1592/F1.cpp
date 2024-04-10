#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  bool ops[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ops[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'B') {
        ops[i][j] = 1-ops[i][j];
        if (j > 0) ops[i][j-1] = 1-ops[i][j-1];
        if (i > 0) ops[i-1][j] = 1-ops[i-1][j];
        if (i > 0 && j > 0) ops[i-1][j-1] = 1-ops[i-1][j-1];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ops[i][j]) {
        ans++;
      }
    }
  }
  int smallsave = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m-1; j++) {
      if (ops[i][j] && ops[n-1][j] && ops[i][m-1] && ops[n-1][m-1]) {
        smallsave = 1;
      }
    }
  }
  cout << ans-smallsave << endl;
}