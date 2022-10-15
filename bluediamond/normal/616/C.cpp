#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 7;
int n, m, a[N][N], t[N * N], id[N][N], sz[N * N], y;

int root(int a) {
  if (t[a] == a) return a;
  return t[a] = root(t[a]);
}

void unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return;
  t[a] = b;
  sz[b] += sz[a];
}

int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      if (s[j - 1] == '.') {
        id[i][j] = ++y;
        t[id[i][j]] = id[i][j];
        sz[id[i][j]] = 1;
        a[i][j] = 1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        if (a[i - 1][j]) unite(id[i][j], id[i - 1][j]);
        if (a[i][j - 1]) unite(id[i][j], id[i][j - 1]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        cout << ".";
      } else {
        int sol = 1;
        set<int> s;
        for (int k = 0; k < 4; k++) {
          int r = i + dr[k], c = j + dc[k];
          if (a[r][c]) {
            if (!s.count(root(id[r][c]))) {
              s.insert(root(id[r][c]));
              sol += sz[root(id[r][c])];
            }
          }
        }
        cout << sol % 10;
      }
    }
    cout << "\n";
  }


  return 0;
}