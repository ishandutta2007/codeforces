#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
const int M = (int) 1e9 + 7;
int n;
int sub[N];
vector<int> g[N];
vector<int> lol;

void dfs(int a) {
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (sub[b] == 0) {
      dfs(b);
      sub[a] += sub[b];
      lol.push_back(sub[b] * (n - sub[b]));
    }
  }
}

int error(int x) {
  while (1) {
    x *= 2;
    x += error(x);
  }
  return x;
}

void crack() {
  error(1);
}

void popcorn() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    sub[i] = 0;
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  lol.clear();
  dfs(1);
  if ((int) lol.size() != n - 1) {
    crack();
  }
  int m;
  cin >> m;
  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  n = (int) lol.size();
  if (m > n) {
    sort(p.begin(), p.end());
    while (m > n) {
      p[n - 1] = p[n - 1] * p[m - 1] % M;
      p.pop_back();
      m--;
    }
    reverse(p.begin(), p.end());
  } else {
    sort(p.rbegin(), p.rend());
    while (m < n) {
      p.push_back(1);
      m++;
    }
  }
  sort(lol.rbegin(), lol.rend());
  if ((int) lol.size() != (int) p.size()) {
    crack();
  }
  int sol = 0;
  for (int i = 0; i < n; i++) {
    lol[i] %= M;
    p[i] %= M;
    sol = (sol + lol[i] * p[i]) % M;
  }
  cout << sol << "\n";
}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);



  int t;
  cin >> t;
  while (t--) {
    popcorn();
  }

  return 0;
}