#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi G(n), T(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    G[y].push_back(x);
    T[x].push_back(y);
  }
  int k;
  cin >> k;
  vi V(k);
  for (int i = 0; i < k; ++i) {
    cin >> V[i];
    --V[i];
  }
  vi D(n, -1);
  int t = V.back();
  D[t] = 0;
  queue<int> Q;
  Q.push(t);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (auto y : G[x]) {
      if (D[y] == -1) {
        D[y] = D[x] + 1;
        Q.push(y);
      }
    }
  }
  int res0 = 0;
  int res1 = 0;
  for (int i = 0; i < k-2; ++i) {
    int x = V[i];
    int val = D[x];
    int cont = 0;
    for (auto y : T[x]) {
      if (D[y] == val - 1) ++cont;
    }
    int y = V[i+1];
    if (D[y] != val - 1) {
      ++res0;
      ++res1;
    }
    else if (cont > 1) {
      ++res1;
    }
  }
  cout << res0 << ' '<< res1 << '\n';
}