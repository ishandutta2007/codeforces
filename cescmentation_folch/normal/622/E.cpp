#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef pair<int, ppi> pppi;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi V;
vi T;

void dfs(int x, int d) {
  V[x] = 1;
  bool xec = true;
  for (int i = 0; i < G[x].size(); ++i) {
    int y = G[x][i];
    if (!V[y]) {
      dfs(y, d + 1);
      xec = false;
    }
  }
  if (xec) T.push_back(d);
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  G = vvi(n);
  V = vi(n, 0);
  
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int res = 0;
  V[0] = 1;
  for (int i = 0; i < G[0].size(); ++i) {
    T = vi(0);
    dfs(G[0][i], 1);
    sort(T.begin(), T.end());
    int k = 0;
    for (int j = 0; j < T.size(); ++j) k = max(k + 1, T[j]);
    res = max(res, k);
  }
  
  cout << res << endl;
}