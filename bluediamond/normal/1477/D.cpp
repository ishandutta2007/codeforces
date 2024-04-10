/// problema gen atcoder
#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
int m;
vector<pair<int, int>> check;

/**
void assert(bool ok) {
  if (!ok) {
    cout << "durere mare pe testul " << tc << "\n";
    cout << n << " " << m << "\n";
    for (auto &it : check) {
      cout << it.first << " " << it.second << "\n";
    }
    exit(0);
  }
}
**/
const int N = (int) 5e5 + 7;
int ret, fi[N], sc[N], sub[N], y = 0, radacina, afara;
bool vis[N];
set<pair<int, int>> nodes;
set<int> sg[N];
vector<int> g2[N];
vector<int> g[N];

void build(int a) {
  sub[a] = 1;
  vis[a] = 1;
  for (auto &b : g2[a]) {
    if (!vis[b]) {
      build(b);
      g[a].push_back(b);
      sub[a] += sub[b];
    }
  }
}

void Etil_xantat_de_sodiu(int a, vector<int> langa) {
  assert(fi[a] == -1);
  for (auto &b : langa) {
    assert(fi[b] == -1);
  }
  assert(!langa.empty());
  int l = y + 1;
  int r = y + 1 + (int) langa.size();
  y = r;
  fi[a] = l;
  sc[a] = r;
  for (auto &b : langa) {
    fi[b] = l + 1;
    sc[b] = l;
    l++;
  }
}

bool dfs(int a) {
  int interior = 1;
  vector<int> langa;
  for (auto &b : g[a]) {
    if (!dfs(b)) {
      langa.push_back(b);
      interior++;
    }
  }
  if (a != radacina && interior >= 2 && (afara - interior >= 2 || afara - interior == 0)) {
    Etil_xantat_de_sodiu(a, langa);
    afara -= interior;
    return 1;
  }
  if (a == radacina) {
    if ((int) langa.size() >= 2) {
      Etil_xantat_de_sodiu(a, langa);
      afara -= interior;
      return 1;
    }
    assert((int) langa.size() == 1);
    vector<int> langa2 = {a};
    for (auto &b : g[langa[0]]) {
      if (fi[b] == -1) {
        langa2.push_back(b);
      }
    }
    Etil_xantat_de_sodiu(langa[0], langa2);
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  for (tc = 1; tc <= t; tc++) {
    cin >> n >> m;
    nodes.clear();
    for (int i = 1; i <= n; i++) {
      sg[i].clear();
      g2[i].clear();
      g[i].clear();
      fi[i] = sc[i] = -1;
      vis[i] = 0;
    }
    check.clear();
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      check.push_back({x, y});
      sg[x].insert(y);
      sg[y].insert(x);
    }
    for (int i = 1; i <= n; i++) {
      nodes.insert({(int) sg[i].size(), i});
    }
    y = 0;
    while (!nodes.empty()) {
      auto it = nodes.end();
      it--;
      if (it->first == (int) nodes.size() - 1) {
        int node = it->second;
        nodes.erase({(int) sg[node].size(), node});
        for (auto &x : sg[node]) {
          nodes.erase({(int) sg[x].size(), x});
          sg[x].erase(node);
          nodes.insert({(int) sg[x].size(), x});
        }
        y++;
        fi[node] = sc[node] = y;
        sg[node].clear();
      } else {
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (nodes.count({(int) sg[i].size(), i})) {
        int j = 1;
        while (sg[i].count(j) || i == j || !nodes.count({(int) sg[j].size(), j})) {
          j++;
        }
       /// cout << " edge " << i << " " << j << "\n";
        g2[i].push_back(j);
        g2[j].push_back(i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && nodes.count({(int) sg[i].size(), i})) {
        build(i);
        afara = sub[i];
        //cout << " => " << afara << "\n";
        assert(sub[i] >= 2);
        radacina = i;
        assert(dfs(i));
      }
    }

    //for (int i = 1; i <= n; i++) {
    //  cout << i << " : " << fi[i] << ", " << sc[i] << "\n";
    //}
    //continue;
    //return 0;

    for (int i = 1; i <= n; i++) {
      assert(fi[i] != -1);
      assert(sc[i] != -1);
    }
    for (auto &it : check) {
      int v1 = (fi[it.first] > fi[it.second]), v2 = (sc[it.first] > sc[it.second]);
      assert(v1 == v2);
    }
    for (int i = 1; i <= n; i++) {
      cout << fi[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
      cout << sc[i] << " ";
    }
    cout << "\n";
    sort(fi + 1, fi + n + 1);
    sort(sc + 1, sc + n + 1);
    for (int i = 1; i <= n; i++) {
      assert(fi[i] == i);
      assert(sc[i] == i);
    }
    ///cout << (int) nodes.size() << "\n";
  }

}