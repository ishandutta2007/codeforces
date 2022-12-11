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
vi V;
int r;

void dfs(int x, int p) {
  if (V[x]) return;
  V[x] = 1;
  --r;
  for (auto y : G[x]) {
    if (y == p) continue;
    dfs(y, x);
  }
}

int main() {
  int n;
  cin >> n;
  G = vvi(n);
  V = vi(n, 0);
  r = n;
  for (int i = 0; i < n-1; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  while (r > 2) {
    for (int i = 0; i < n; ++i) {
      if (V[i]) continue;
      int x = -1;
      int y = -1;
      for (auto z : G[i]) {
        if (!V[z]) {
          if (x == -1) x = z;
          else {
            y = z;
            break;
          }
        }
      }
      if (y == -1) continue;
      cout << "? " << x+1 << ' ' << y+1 << endl;
      int s;
      cin >> s;
      --s;
      if (s == x) dfs(i, x);
      else if (s == y) dfs(i, y);
      else {
        dfs(x, i);
        dfs(y, i);
      }
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (V[i]) continue;
    int x = -1;
    for (auto z : G[i]) {
      if (!V[z]) {
        x = z;
        break;
      }
    }
    if (x == -1) {
      cout << "! " << i +1 << endl;
      return 0;
    }
    else {
      cout << "? " << i + 1 << ' ' << x +1 << endl;
      int s;
      cin >> s;
      cout << "! " << s << endl;
      break;
    }
  }
}