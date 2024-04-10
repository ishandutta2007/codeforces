#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
const int INF = (int) 1e9;
int n;
int m;
int s;
int d;
int cap[N][N];
int cost[N][N];
vector<int> g[N];
int best[N];
int par[N];
bool act[N];

void add(int a, int b, int cp, int cst) {
  a--;
  b--;
  g[a].push_back(b);
  g[b].push_back(a);
  cap[a][b] = cp;
  cost[a][b] = cst;
  cost[b][a] = -cost[a][b];
}

int players, games, cine[100][100];
vector<int> wins, lft;
set<pair<int, int>> is_game;
map<pair<int, int>, int> who;

void prep() {


  cin >> players >> games;
  wins.resize(players + 1, 0);
  lft.resize(players + 1, players - 1);
  for (int i = 1; i <= games; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    lft[t1]--;
    lft[t2]--;
    who[{t1, t2}] = t1;
    who[{t2, t1}] = t1;
    is_game.insert({t1, t2});
    is_game.insert({t2, t1});
    wins[t1]++;
  }
  n = 1 + players * (players - 1) / 2 - games + players + 1;
  s = 1;
  d = n;
  int id = 0;
  for (int i = 1; i <= players; i++) {
    for (int j = i + 1; j <= players; j++) {
      if (is_game.count({i, j})) continue;
      id++;
      cine[i][j] = cine[j][i] = id;
      add(1, 1 + id, 1, 0);
      add(1 + id, 1 + players * (players - 1) / 2 - games + i, 1, 0);
      add(1 + id, 1 + players * (players - 1) / 2 - games + j, 1, 0);
    }
  }
  for (int i = 1; i <= players; i++) {
    if (!lft[i]) continue;
    int o = 1 + players * (players - 1) / 2 - games + i;
    n++;
    add(o, n, 1000, 2 * wins[i] + 1);
    add(n, d, 1, 0);
    for (int j = 2; j <= lft[i]; j++) {
      n++;
      add(n - 1, n, 1000, 2);
      add(n, d, 1, 0);
    }
  }
  assert(id == players * (players - 1) / 2 - games);
}

int main() {
  prep();

  s--;
  d--;

  int fl = 0;
  ll ans = 0;
  while (1) {
    for (int i = 0; i < n; i++) {
      best[i] = INF;
    }
    act[s] = 1;
    best[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      act[a] = 0;
      for (auto &b : g[a]) {
        if (cap[a][b] > 0 && best[a] + cost[a][b] < best[b]) {
          best[b] = best[a] + cost[a][b];
          par[b] = a;
          if (act[b] == 0) {
            act[b] = 1;
            q.push(b);
          }
        }
      }
    }
    if (best[d] == INF) {
      break;
    }
    int mn = INF, now = d;
    while (now != s) {
      int a = par[now];
      int b = now;
      mn = min(mn, cap[a][b]);
      now = par[now];
    }
    ans += (ll) best[d] * mn;
    fl += mn;
    now = d;
    vector<int> way = {d};
    while (now != s) {
      int a = par[now];
      int b = now;
      way.push_back(a);
      cap[a][b] -= mn;
      cap[b][a] += mn;
      now = par[now];
    }
    reverse(way.begin(), way.end());
  }
  for (int i = 1; i <= players; i++) {
    for (int j = 1; j <= players; j++) {
      if (is_game.count({i, j})) {
        cout << (who[{i, j}] == i);
      } else {
        if (i == j) {
          cout << "0";
          continue;
        }
        int id = cine[i][j];
        int x = 1 + id;
        int y = 1 + players * (players - 1) / 2 - games + i;
        x--;
        y--;
        cout << (cap[x][y] == 0);
      }
    }
    cout << "\n";
  }

}