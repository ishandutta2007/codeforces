#include <bits/stdc++.h>

using namespace std;

void Solve(vector<int> in) {
  int n = in.size();
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    v[i].first = in[i];
    v[i].second = i;
  }
  sort(v.rbegin(), v.rend());
  int m = v[0].first;
  vector<string> ops(m + 1, string(n, '0'));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < v[i].first; ++j) {
      ops[j][i] = '1';
    }
  }

  for (int i = 1; i < m; ++i) {
    if (ops[i][m - i - 1] == '0') {
      swap(ops[i][m - i - 1], ops[0][m - i - 1]);
    }
    if (ops[i][m - i] == '1') {
      swap(ops[i][m - i], ops[m][m - i]);
    }
  }

  vector<string> out;
  for (int i = 0; i <= m; ++i) {
    bool noop = true;
    for (int j = 0; j < n; ++j) {
      if (ops[i][j] == '1') {
        noop = false;
      }
    }
    if (!noop) {
      out.push_back(string(n, '0'));
      for (int j = 0; j < n; ++j) {
        out.back()[v[j].second] = ops[i][j];
      }
    }
  }
  
  cout << out.size() << '\n';
  for (auto x : out) cout << x << '\n';
}

int main() {
  /*while (true) {
    int n = rand() % 5 + 2;
    vector<int> in;
    for (int i = 1; i <= n; ++i) {
      in.push_back(rand() % n + 1);
    }
    Solve(in);
  }*/

  int n; cin >> n;
  vector<int> in(n);
  for (int i = 0; i < n; ++i) {
    cin >> in[i];
  }
  Solve(in);
  return 0;
}