#include <bits/stdc++.h>

using namespace std;

int rep(int x, int mod) {
  x %= mod;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        x--;
        v.push_back({i, j, x});
      }
    }
    vector<int> shift = {0, 0, 0}, ord = {0, 1, 2};
    string s;
    cin >> s;
    for (auto &ch : s) {
      if (ch == 'R') shift[1]++;
      if (ch == 'L') shift[1]--;
      if (ch == 'U') shift[0]--;
      if (ch == 'D') shift[0]++;
      if (ch == 'I') {
        swap(shift[1], shift[2]);
        swap(ord[1], ord[2]);
      }
      if (ch == 'C') {
        swap(shift[0], shift[2]);
        swap(ord[0], ord[2]);
      }
    }
    vector<vector<int>> ret(n, vector<int> (n, -1));
    for (int i = 0; i < n * n; i++) {
      vector<int> x = v[i];
      vector<int> y(3);
      for (int j = 0; j < 3; j++) {
        y[j] = rep(x[ord[j]] + shift[j], n);
      }
      y[0] = rep(y[0], n);
      y[1] = rep(y[1], n);
      y[2] = rep(y[2], n);
      ret[y[0]][y[1]] = y[2];
    }
    for (auto &v : ret) {
      for (auto &x : v) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    }
    cout << "\n";
  }

}