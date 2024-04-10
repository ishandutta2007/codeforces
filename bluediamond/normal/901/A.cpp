#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int m;
vector<int> nodes[N];
int par[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  m = 0;
  for (int i = 0; i <= n; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 1; j <= cnt; j++) {
      nodes[i].push_back(++m);
      if (i) {
        par[m] = nodes[i - 1][0];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if ((int) nodes[i].size() >= 2 && (int) nodes[i - 1].size() >= 2) {
      cout << "ambiguous\n";
      for (int it = 0; it <= 1; it++) {
        for (int i = 1; i <= m; i++) {
          cout << par[i] << " ";
        }
        cout << "\n";
        par[nodes[i][0]] = nodes[i - 1][1];
      }
      return 0;
    }
  }
  cout << "perfect\n";
  return 0;
}