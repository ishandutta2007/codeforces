#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int x[N];
int y[N];
int sol[N];
vector<int> g[N];
int poo;

void dfs(int a, int vin) {
  int vecs = 0;
  for (auto &i : g[a]) {
    if (i != vin) {
      int b = x[i] + y[i] - a;
      dfs(b, i);
      vecs++;
    }
  }
  if (vecs) {
    return;
  }
  if (poo == 0) {
    sol[vin] = 0;
    poo = 1;
    return;
  }
  if (poo == 1) {
    sol[vin] = 1;
    poo = 2;
    return;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    sol[i] = -1;
    cin >> x[i] >> y[i];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
  }
  sol[n] = -1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += ((int) g[i].size() == 1);
  }
  if (cnt == 2) {
    for (int i = 1; i < n; i++) {
      sol[i] = i - 1;
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if ((int) g[i].size() >= 3) {
        sol[g[i][0]] = 2;
        dfs(i, g[i][0]);
        break;
      }
    }
    int cur = 3;
    for (int i = 1; i < n; i++) {
      if (sol[i] == -1) {
        sol[i] = cur++;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    cout << sol[i] << "\n";
  }
}