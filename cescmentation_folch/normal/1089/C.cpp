#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vvi G;
vvi D;
vi V;

void bfs(int x) {
  D[x][x] = 0;
  queue<int> Q;
  Q.push(x);
  while (!Q.empty()) {
    int y = Q.front(); Q.pop();
    for (auto z : G[y]) {
      if (D[x][z] == -1) {
        D[x][z] = D[x][y] + 1;
        Q.push(z);
      }
    }
  }
}

int conta(int x, int y) {
  int n = (int)V.size();
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (!V[i] and D[y][i] < D[x][i])
      ++res;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  G = vvi(n);
  D = vvi(n, vi(n,-1));
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    int x;
    cin >> x;
    --x;
    for (int j = 1; j < k; ++j) {
      int y;
      cin >> y;
      --y;
      G[x].push_back(y);
      G[y].push_back(x);
      x = y;
    }
  }
  for (int i = 0; i < n; ++i) bfs(i);

  for (int cont = 0; cont < n; ++cont) {
    int num = n;
    V = vi(n, 0);
    while (1) {
      int vx = 0;
      for (int x = 0; x < n; ++x) {
        if (V[x]) continue;
        int maxim = 0;
        for (auto y : G[x]) {
          int val = conta(x, y);
          maxim = max(maxim, val);
        }
        if (2*maxim <= num) {
          vx = x;
          break;
        }
      }
      cout << vx + 1 << endl;
      string rr;
      cin >> rr;
      if (rr == "FOUND") break;
      int vy;
      cin >> vy; --vy;
      for (int x = 0; x < n; ++x) {
        if (!V[x] and D[vx][x] <= D[vy][x]) { 
          V[x] = 1;
          --num;
        }
      }
    }
  }
}