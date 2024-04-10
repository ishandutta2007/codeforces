#include <bits/stdc++.h>

using namespace std;

bool home = 1;
const int inf = (int)1e9 + 7;

struct Node {
  int l, r, i;
};


bool operator < (Node a, Node b) {
  if (a.l != b.l) return a.l < b.l;
  return a.i < b.i;
}

const int N = (int)1e5 + 7;
Node g[N][4];

void solve(set<Node>* s) {
  int n = (int)s[0].size();
  if (n <= 2)return;
  set<Node>::iterator it[4];
  vector<int> mx(4);

  int steps = 1;
  for (int i = 0; i < 4; i++) {
    it[i] = s[i].begin();
    mx[i] = it[i]++->r;

  }
  while (it[0] != s[0].end()) {
    for (int i = 0; i < 4; i++) {
      if (mx[i] <= it[i]->l) {
        set<Node> small[4];
        it[i] = s[i].begin();
        for (int ITER = 1; ITER <= steps; ITER++) {
          int ind = it[i]++->i;
          for (int j = 0; j < 4; j++) {
            s[j].erase(g[ind][j]);
            small[j].insert(g[ind][j]);
          }
        }
        solve(small);
        solve(s);
        return;
      }
    }

    steps++;
    for (int i = 0; i < 4; i++) {
      mx[i] = max(mx[i], it[i]++->r);
    }
  }

  cout << "NO\n";
  exit(0);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int n;
  cin >> n;
  set<Node> s[4];

  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    g[i][0] = { x1, x2, i };
    g[i][1] = { y1, y2, i };
    g[i][2] = { -x2, -x1, i };
    g[i][3] = { -y2, -y1, i };
    for (int j = 0; j < 4; j++) {
      s[j].insert(g[i][j]);
    }
  }

  solve(s);

  cout << "YES\n";


}