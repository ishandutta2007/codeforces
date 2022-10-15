#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = (int) 3e5 + 7;
int n;
int m;
int c[N];
int cnt[2];
bool error;
vector<int> g[N];

void dfs(int a) {
  cnt[c[a]]++;
  for (auto &b : g[a]) {
    if (c[b] == -1) {
      c[b] = c[a] ^ 1;
      dfs(b);
    } else {
      if (c[b] != (c[a] ^ 1)) {
        error = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear(), c[i] = -1;
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int sol = 1;
    error = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i] == -1) {
        cnt[0] = cnt[1] = 0;
        c[i] = 0;
        dfs(i);
        sol = mul(sol, add(pw(2, cnt[0]), pw(2, cnt[1])));
      }
    }
    if (error) {
      cout << "0\n";
    } else {
      cout << sol << "\n";
    }
  }





}