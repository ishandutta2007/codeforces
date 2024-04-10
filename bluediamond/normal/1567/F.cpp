#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N = 500 + 7;
int n, m, a[N][N], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}, color[N * N], sol[N][N];
vector<int> g[N * N];

void addEdge(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}

int id(pair<int, int> a) {
  return (a.first - 1) * m + a.second;
}

void dfs(int a) {
  for (auto &b : g[a]) {
    if (color[b] == 0) {
      color[b] = 5 - color[a];
      dfs(b);
    } else {
      if (color[b] != 5 - color[a]) {
        cout << "NO\n";
        exit(0);
      }
      ///assert(color[b] == 5 - color[a]);
    }
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  cin >> n >> m;

  bool tot = 1;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    assert((int) s.size() == m);
    for (int j = 1; j <= m; j++) {
      char ch = s[j - 1];
      assert(ch == '.' || ch == 'X');
      a[i][j] = (ch == 'X');
      tot &= (ch == '.');
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        vector<pair<int, int>> v;

        for (int k = 0; k < 4; k++) {
          int in = i + dr[k], jn = j + dc[k];
          assert(1 <= in && in <= n);
          assert(1 <= jn && jn <= m);
          if (a[in][jn] == 0) {
            v.push_back({in, jn});
          }
        }
        if ((int) v.size() % 2 == 1) {
          cout << "NO\n";
          exit(0);
        }
        if ((int) v.size() == 2) {
          addEdge(id(v[0]), id(v[1]));
        }
        if ((int) v.size() == 4) {
          addEdge(id(v[0]), id(v[3]));
          addEdge(id(v[2]), id(v[1]));
        }
      }
    }
  }
  for (int i = 1; i <= n * m; i++) {
    if (color[i] == 0) {
      color[i] = 1;
      dfs(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        auto it = make_pair(i, j);
        sol[i][j] = color[id(it)];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) {
        sol[i][j] += a[i][j] * (1 - a[i + dr[k]][j + dc[k]]) * sol[i + dr[k]][j + dc[k]];
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << sol[i][j] << " ";
    }
    cout << "\n";
  }
}