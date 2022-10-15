#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
//#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

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

struct point {
  int x;
  int y;
  int i;
};

bool operator < (point a, point b) {
  if (a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

const int N = (int) 1e5 + 7;
int n, x[N], y[N], no;
point p[N];
vector<int> g[N];
bool vis[N];
set<int> sx, sy;

void baga_muchie(int i, int j) {
  g[i].push_back(j);
  g[j].push_back(i);
}

void dfs(int i) {
  no++;
  vis[i] = 1;
  sx.insert(x[i]);
  sy.insert(y[i]);
  for (auto &j : g[i]) {
    if (!vis[j]) {
      dfs(j);
    }
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    p[i] = {x[i], y[i], i};
  }
  for (int step = 1; step <= 2; step++) {
    sort(p + 1, p + n + 1);
    for (int i = 2; i <= n; i++) {
      if (p[i].x == p[i - 1].x) {
        baga_muchie(p[i - 1].i, p[i].i);
      }
    }
    for (int i = 1; i <= n; i++) {
      swap(p[i].x, p[i].y);
    }
  }
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      sx.clear();
      sy.clear();
      no = 0;
      dfs(i);
      int c1 = (int) sx.size(), c2 = (int) sy.size(), val = pw(2, c1 + c2);
      if (no == c1 + c2 - 1) {
        val = add(val, -1);
      }
      ret = mul(ret, val);
    }
  }
  cout << ret << "\n";
  return 0;
}