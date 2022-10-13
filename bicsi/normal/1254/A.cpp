#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i)
      cin >> mat[i];
    
    int rice = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 'R')
          rice += 1;
      }
    }

    vector<int> target(k, 0);
    for (int i = 0; i < k; ++i)
      target[i] = rice / k;
    for (int i = 0; i < rice % k; ++i)
      target[i] += 1;

    int chk = 0;
    for (int i = 0; i < k; ++i)
      chk += target[i];
    assert(chk == rice);
    
    vector<string> sol(n, string(m, '.'));

    // Traverse the matrix in snake order and assign stuff to sol
    string alphabet;
    for (char i = 'a'; i <= 'z'; ++i)
      alphabet += i;
    for (char i = 'A'; i <= 'Z'; ++i)
      alphabet += i;
    for (char i = '0'; i <= '9'; ++i)
      alphabet += i;
    alphabet.resize(k);
    
    target.back() += 1;
    int at = 0; int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        for (int j = 0; j < m; ++j) {
          sol[i][j] = alphabet[at];
          if (mat[i][j] == 'R') {
            cnt += 1;
            if (cnt == target[at]) {
              ++at;
              cnt = 0;
            }
          }
        }
      } else {
        for (int j = m - 1; j >= 0; --j) {
          sol[i][j] = alphabet[at];
          if (mat[i][j] == 'R') {
            cnt += 1;
            if (cnt == target[at]) {
              ++at;
              cnt = 0;
            }
          } 
        }
      }
    }

    for (int i = 0; i < n; ++i)
      cout << sol[i] << '\n';
  }
  return 0;
}