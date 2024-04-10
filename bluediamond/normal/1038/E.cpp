#include <bits/stdc++.h>

using namespace std;


struct edge {
  int x;
  int y;
  int sum;
};

int pos[4];
vector<edge> edges;
vector<int> ind[4][4]; /// 4 + 3 + 2 + 1 = 10
vector<int> g[4];

int cur;
bool vis[4];
int odd;

void dfs(int a) {
  vis[a] = 1;
  odd += (int) g[a].size() % 2;
  for (auto &ind : g[a]) {
    int other = edges[ind].x + edges[ind].y - a;
    cur += edges[ind].sum;
    if (vis[other]) continue;
    dfs(other);
  }
}

bool CMP(int i, int j) {
  return edges[i].sum > edges[j].sum;
}

int main() {
  ///freopen ("input", "r", stdin);

  int e;
  cin >> e;
  edges.resize(e);

  for (int j = 0; j < e; j++) {
    edge &it = edges[j];
    cin >> it.x >> it.sum >> it.y;
    it.x--;
    it.y--;

    if (it.x > it.y) {
      swap(it.x, it.y);
    }

    ind[it.x][it.y].push_back(j);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4; j++) {
      sort(ind[i][j].begin(), ind[i][j].end(), CMP);
    }
  }

  int sol = 0;
  for (int i = 0; i < 4; i++) {
    for (int mask = 0; mask < (1 << 12); mask++) {
     /// cout << " = " << mask << "\n";
      int bit = 0;

      for (int i = 0; i < 4; i++) {
        g[i].clear();
        pos[i] = 0;
        vis[i] = 0;
      }

      for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
          int sz = (int) ind[i][j].size() - !!(mask & (1 << bit++));
          for (int k = 0; k < sz; k++) {
            int id = ind[i][j][k];
            g[edges[id].x].push_back(id);
            g[edges[id].y].push_back(id);
          }
        }
      }
      cur = 0;
      odd = 0;
      dfs(i);
      if (odd <= 2) {
        sol = max(sol, cur / 2);
      }
    }
  }
  cout << sol << "\n";


}