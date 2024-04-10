#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i)
      cin >> board[i];

    
    bool bad = false, mortal = true;
    vector<int> badr(n, 0), badc(m, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'P') {
          badr[i] += 1; badc[j] += 1; 
          bad = true;
        } else { mortal = false; }
      }
    }

    bool can_2 = false;
    for (int i = 0; i < n; ++i) {
      if (!badr[i]) can_2 = true;
    }
    for (int i = 0; i < m; ++i) {
      if (!badc[i]) can_2 = true;
    }
    
    if (mortal) {
      cout << "MORTAL\n";
    } else if (!bad) {
      cout << 0 << '\n';
    } else if (!badr[0] || !badr[n - 1] || !badc[0] || !badc[m - 1]) {
      cout << 1 << '\n';
    } else if (can_2 || board[0][0] == 'A' || 
        board[n - 1][m - 1] == 'A' || 
        board[0][m - 1] == 'A' || board[n - 1][0] == 'A') {
      cout << 2 << '\n';
    } else if (badr[0] != m || badr[n - 1] != m 
        || badc[0] != n || badc[m - 1] != n) {
      cout << 3 << '\n';
    } else {
      cout << 4 << '\n';
    }
  }
  return 0;
}