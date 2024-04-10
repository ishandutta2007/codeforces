#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;




const int N = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;
int n, from, to, p[N], dp[N];
pair<int, int> treeMax[4 * N];
pair<int, int> treeMin[4 * N];

void updMax(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    assert(tl == i);
    assert(tr == i);
    treeMax[v] = {x, tl};
    return;
  }
  int tm = (tl + tr) / 2;
  updMax(2 * v, tl, tm, i, x);
  updMax(2 * v + 1, tm + 1, tr, i, x);
  treeMax[v] = max(treeMax[2 * v], treeMax[2 * v + 1]);
}

pair<int, int> getMax(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return {-INF, -INF};
  }
  if (l <= tl && tr <= r) {
    return treeMax[v];
  }
  int tm = (tl + tr) / 2;
  return max(getMax(2 * v, tl, tm, l, r), getMax(2 * v + 1, tm + 1, tr, l, r));
}


void updMin(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    assert(tl == i);
    assert(tr == i);
    treeMin[v] = {x, tl};
    return;
  }
  int tm = (tl + tr) / 2;
  updMin(2 * v, tl, tm, i, x);
  updMin(2 * v + 1, tm + 1, tr, i, x);
  treeMin[v] = min(treeMin[2 * v], treeMin[2 * v + 1]);
}

pair<int, int> getMin(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return {+INF, +INF};
  }
  if (l <= tl && tr <= r) {
    return treeMin[v];
  }
  int tm = (tl + tr) / 2;
  return min(getMin(2 * v, tl, tm, l, r), getMin(2 * v + 1, tm + 1, tr, l, r));
}


void Delete(int Vertex) {
  updMax(1, 1, n, Vertex, -INF);
  updMin(1, 1, n, Vertex, +INF);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    cin >> n >> from >> to;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      dp[i] = -1;
      updMax(1, 1, n, i, i + p[i]);
      updMin(1, 1, n, i, i - p[i]);
    }
    dp[from] = 0;
    queue<int> Q;
    Q.push(from);
    Delete(from);
    while (!Q.empty()) {
      int a = Q.front();
      Q.pop();

      int L = max(1, a - p[a]);
      int R = min(n, a + p[a]);

      if (L < a) {
        while (1) {
          auto Pair = getMax(1, 1, n, L, a - 1);
          if (Pair.first < a) break;
          int b = Pair.second;
          assert(dp[b] == -1 && a <= b + p[b]);
          dp[b] = dp[a] + 1;
          Q.push(b);
          Delete(b);
        }
      }
      if (a < R) {
        while (1) {
          auto Pair = getMin(1, 1, n, a + 1, R);
          if (Pair.first > a) break;
          int b = Pair.second;
          assert(dp[b] == -1 && b - p[b] <= a);
          dp[b] = dp[a] + 1;
          Q.push(b);
          Delete(b);
        }
      }
    }
    cout << dp[to] << "\n";
  }


}
/**
-p(i) <= j - i <= +p(i)
i - p(i) <= j <= i + p(i)

-p(j) <= j - i <= +p(j)
i <= j + p(j)

j - p(j) <= i <= j + p(j)
**/