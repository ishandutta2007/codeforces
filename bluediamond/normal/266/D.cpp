#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct Edge {
  int x;
  int y;
  int w;
};

const int N = 200 + 7;
const int INF = (int) 1e9;
int n;
int m;
int d[N][N];

struct T {
  int f;
  int s;
};

bool operator < (T a, T b) {
  return a.s - a.f < b.s - b.f;
}

int solve(int x, int y, int w) {
  vector<T> pts;
  for (int i = 1; i <= n; i++) {
    pts.push_back({d[x][i], d[y][i] + w});
  }
  sort(pts.begin(), pts.end());
  vector<int> pre(n), suf(n);
  pre[0] = pts[0].s;
  for (int i = 1; i < n; i++) {
    pre[i] = max(pre[i - 1], pts[i].s);
  }
  suf[n - 1] = pts[n - 1].f;
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = max(suf[i + 1], pts[i].f);
  }
  vector<int> tt(n);
  for (int i = 0; i < n; i++) {
    tt[i] = (pts[i].s - pts[i].f) / 2;
  }

  int ret = INF;
  for (int last = -1; last < n; last++) {
    if (last == -1) {
      int m_suf = suf[last + 1];
      int t = tt[last + 1];
      ret = min(ret, m_suf + t);
      continue;
    }
    if (last == n - 1) {
      int m_pre = pre[last];
      int t = tt[last];
      ret = min(ret, m_pre - t);
      continue;
    }
    int t1 = tt[last];
    int t2 = tt[last + 1];
    int m_pre = pre[last];
    int m_suf = suf[last + 1];
    ret = min(ret, max(m_suf + t1, m_pre - t1));
    ret = min(ret, max(m_suf + t2, m_pre - t2));
    int t = (m_pre - m_suf) / 2;
    if (t1 <= t && t <= t2) {
      ret = min(ret, max(m_suf + t, m_pre - t));
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }
  vector<Edge> e(m);
  for (int i = 0; i < m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].w;
    e[i].w *= 2;
    d[e[i].x][e[i].y] = d[e[i].y][e[i].x] = e[i].w;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  solve(e[0].x, e[0].y, e[0].w);
  int ret = INF;
  for (auto &it : e) {
    ret = min(ret, solve(it.x, it.y, it.w));
  }
  if (ret % 2 == 0) {
    cout << ret / 2 << ".0\n";
  } else {
    cout << ret / 2 << ".5\n";
  }

}