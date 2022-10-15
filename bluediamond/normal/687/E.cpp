#include <bits/stdc++.h>

using namespace std;

/**
solution = 999 * (number of vertexes in a cycle) + number of vertexes not in a cycle + number of cycles
solution = 998 * (number of vertexes in a cycle) + n + number of cycles
minimize solution
<=>
minimize X = 998 * (number of vertexes in a cycle) + number of cycles
         X = 998 * a + b

it is possible to minimize both a and b at the same time
how?

well (number of cycles = ) b >= number of sinks components with size >= 2
     (number of vertexes in a cycle) >= sum for each sink component with size >= 2 of the minimum length of a cycle inside it

      both the equalities are achievable

**/



const int N = 5000 + 7;
int n, m, ct[N];
vector<int> ord;
bool vis[N];
vector<int> g[N], ginv[N];

bool sink[N];
int sz[N];

void dfs(int a) {
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (!vis[b]) {
      dfs(b);
    }
  }
  ord.push_back(a);
}

void place(int a, int x) {
  sz[x]++;
  ct[a] = x;
  for (auto &b : ginv[a]) {
    if (!ct[b]) {
      place(b, x);
    }
  }
}

bool donec[N];
int dist[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int foo, bar;
    cin >> foo >> bar;
    g[foo].push_back(bar);
    ginv[bar].push_back(foo);
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  reverse(ord.begin(), ord.end());



  int cts = 0;

  for (auto &i : ord) {
    if (ct[i] == 0) {
      place(i, ++cts);
      sink[cts] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    vector<int> kol;
    for (auto &j : g[i]) {
      if (ct[i] != ct[j]) {
       // cout << "muchie " << i << " -> " << j << "\n";
        sink[ct[i]] = 0;
      } else {
        kol.push_back(j);
      }
    }
    g[i] = kol;
  }

  int sol = n;
  for (int no = 1; no <= n; no++) {
    int x = ct[no];
    if (donec[x] || sz[x] == 1 || !sink[x]) continue;
    donec[x] = 1;
    vector<int> guys;
    for (int i = 1; i <= n; i++) {
      if (ct[i] == x) guys.push_back(i);
    }
    int kek = (int) 1e9;
    /// find the min cycle
    for (auto &i : guys) {
      for (auto &j : guys) dist[j] = -1;
      dist[i] = 0;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int a = q.front();
        assert(ct[a] == x);
        q.pop();
        for (auto &b : g[a]) {
          if (dist[b] == -1) {
            dist[b] = 1 + dist[a];
            q.push(b);
          }
        }
      }
      for (auto &j : guys) {
        assert(dist[j] != -1);
      }
      for (auto &j : ginv[i]) {
        if (ct[j] != x) continue;
        kek = min(kek, dist[j] + 1);
      }
    }
    sol += 998 * kek + 1;
  }
  cout << sol << "\n";


  return 0;
  for (int i = 1; i <= n; i++) {
    cout << i << " -> " << ct[i] << "\n";
  }

  return 0;
}