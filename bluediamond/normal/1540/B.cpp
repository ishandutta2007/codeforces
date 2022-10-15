#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 200 + 7;
int n;
bool vis[N];
vector<int> cur;
vector<int> paths[N];
vector<int> g[N];

void ulala(int a, int p = -1) {
  cur.push_back(a);
  paths[a] = cur;
  for (auto &b : g[a]) {
    if (b != p) {
      ulala(b, a);
    }
  }
  cur.pop_back();
}

int memo[N][N];

int compute(int d1, int d2) {
  assert(d1 + d2 > 0);
  if (d1 == 0) return 0;
  if (d2 == 0) return 1;
  if (memo[d1][d2] != -1) return memo[d1][d2];
  int p1 = dv(1, 2), p2 = p1;
  int sol = add(mul(p1, compute(d1 - 1, d2)), mul(p2, compute(d1, d2 - 1)));
  memo[d1][d2] = sol;
  return sol;
}

int get_prob(int r, int i, int j) {
  /// probability that i comes before j
  int pos = 0;
  {
    int l = 0, r = min((int) paths[i].size(), (int) paths[j].size()) - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (paths[i][mid] == paths[j][mid]) {
        pos = mid + 1;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  int d1 = (int) paths[i].size() - pos;
  int d2 = (int) paths[j].size() - pos;
  return compute(d2, d1);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      memo[i][j] = -1;
    }
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int sol = 0;
  for (int r = 1; r <= n; r++) {
    ulala(r);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        sol = add(sol, get_prob(r, i, j));
      }
    }
  }
  sol = dv(sol, n);
  cout << sol << "\n";

  return 0;
}