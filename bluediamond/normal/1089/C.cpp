#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 7;
const int INF = (int) 1e9;
int n, m, d[N][N], worst[N], cnt[N];
vector<int> g[N];

void algo() {
  vector<int> possible;
  for (int i = 1; i <= n; i++) {
    possible.push_back(i);
  }
  while ((int) possible.size() > 1) {
    int best = (int) 1e9;
    for (auto &ask : possible) {
      for (auto &v : possible) {
        for (auto &x : g[ask]) {
          if (d[x][v] < d[ask][v]) {
            cnt[x]++;
          }
        }
      }
      worst[ask] = 0;
      for (auto &x : g[ask]) {
        worst[ask] = max(worst[ask], cnt[x]);
        cnt[x] = 0;
      }
      best = min(best, worst[ask]);
    }
    for (auto &ask : possible) {
      if (best == worst[ask]) {
        cout << ask << endl;
        string ret;
        cin >> ret;
        if (ret == "FOUND") {
          return;
        }
        assert(ret == "GO");
        int x;
        cin >> x;
        vector<int> possible2;
        for (auto &v : possible) {
          if (d[x][v] < d[ask][v]) {
            possible2.push_back(v);
          }
        }
        possible = possible2;
        break;
      }
    }

  }
  cout << possible[0] << endl;
  string ret;
  cin >> ret;
  assert(ret == "FOUND");
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      d[i][j] = d[j][i] = INF;
    }
  }
  for (int j = 1; j <= m; j++) {
    int k;
    cin >> k;
    vector<int> path(k);
    for (auto &x : path) {
      cin >> x;
    }
    for (int i = 1; i < (int) path.size(); i++) {
      d[path[i - 1]][path[i]] = 1;
      d[path[i]][path[i - 1]] = 1;
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == 1) {
        g[i].push_back(j);
      }
    }
  }
  for (int step = 1; step <= n; step++) {
    algo();
  }
  return 0;
}