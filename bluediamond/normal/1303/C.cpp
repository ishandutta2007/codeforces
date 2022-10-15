#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool adj[26][26];
vector<int> g[26];

char f(int x) {
  return (char) (x + 'a');
}
bool se[26];

void dfs(int i) {
  se[i] = 1;
  cout << f(i);
  for (auto &j : g[i]) {
    if (se[j] == 0) {
      dfs(j);
    }
  }
}

int nn;

void solve() {
  if (nn == 1) {
    cout << "YES\n";
    for (int i = 0; i < 26; i++) cout << f(i);
    cout << "\n";
    return;
  }
  int c0 = 0, c1 = 0, c2 = 0;
  for (int i = 0; i < 26; i++) {
    se[i] = 0;
    int s = (int) g[i].size();
    c0 += (s == 0);
    c1 += (s == 1);
    c2 += (s == 2);
  }
  if (c1 >= 3) {
    cout << "NO\n";
    return;
  }
  int sum = c0 + c1 + c2;
  if (sum != 26) {
    cout << "NO\n";
    return;
  }
  vector<int> a, b;
  for (int i = 0; i < 26; i++) {
    int s = (int) g[i].size();
    if (s == 1) {
      a.push_back(i);
    }
    if (s == 2) {
      b.push_back(i);
    }
  }
  if (c1 == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  dfs(a[0]);
  for (int i = 0; i < 26; i++) {
    if ((int) g[i].size() == 0) {
      cout << f(i);
    }
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 26; i++) {
      g[i].clear();
      for (int j = 0; j < 26; j++) {
        adj[i][j] = 0;
      }
    }
    string s;
    cin >> s;
    int n = (int) s.size();
    nn = n;
    for (int i = 1; i < n; i++) {
      int x = s[i] - 'a';
      int y = s[i - 1] - 'a';
      adj[x][y] = adj[y][x] = 1;
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (adj[i][j]) {
          g[i].push_back(j);
        }
      }
    }
    solve();
  }

}