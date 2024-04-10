#include <bits/stdc++.h>

using namespace std;

map<char, int> dx = {{'U', -1}, {'D', 1}};
map<char, int> dy = {{'L', -1}, {'R', 1}};

int main() {

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> pref(n);
    for (int i = 0; i < n; ++i) {
      cin >> pref[i];
    }

    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
      cin >> mat[i];
    }

    vector<int> nxt(n * m, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int ni = i + dx[mat[i][j]];
        int nj = j + dy[mat[i][j]];
        nxt[i * m + j] = ni * m + nj;
      }
    }
    
    for (int i = 0; i < n * m; ++i) 
      assert(nxt[i] != -1);
    
    vector<int> nnxt = nxt;
    vector<int> rnxt(n * m);
    for (int i = 0; i < n * m; ++i)
      rnxt[i] = i;

    int e = n * m;
    while (e) {
      if (e % 2) {
        for (int i = 0; i < n * m; ++i) 
          nnxt[i] = rnxt[nxt[i]];
        swap(nnxt, rnxt);
      }
      for (int i = 0; i < n * m; ++i) 
        nnxt[i] = nxt[nxt[i]];
      swap(nxt, nnxt);
      e /= 2;
    } 
    
    auto gpref = [&](int node) { 
      return pref[node / m][node % m] == '0'; };

    vector<int> choice(n * m, -1);
    for (int i = 0; i < n * m; ++i) {
      if (choice[rnxt[i]] == -1 || 
          gpref(choice[rnxt[i]]) < gpref(i))
        choice[rnxt[i]] = i;
    }
    
    int a = 0, b = 0;
    for (int i = 0; i < n * m; ++i) {
      if (choice[i] != -1) {
        a += 1;
        b += gpref(choice[i]);
      }
    }
    cout << a << " " << b << '\n';
  }
  return 0;
}