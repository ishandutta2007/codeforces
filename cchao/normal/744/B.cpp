#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int A[3][3] = {
  0, 3, 2, 5, 0, 7, 4, 8, 0
};
int n;

vector<int> sim(vector<int> a) {
  vector<int> res;
  REP(i, n) {
    int r = INT_MAX;
    for (int w : a) r = min(r, A[i][w]);
    res.push_back(r);
  }
  printf("query: ");
  for (auto x : a) cout << x << ' ';
  cout << endl;
  printf("ret: ");
  for (auto x : res) cout << x << ' ';
  cout << endl;
  return res;
}

bool g[20][1024];

void dfs(int d, int l, int n) {
  if (n <= 1) {
    return;
  }
  REP(i, n) {
    g[d][l + i] = i >= n / 2;
  }
  dfs(d + 1, l, n / 2);
  dfs(d + 1, l + n / 2, n / 2);
}
int ans[1024];

vector<int> qry(vector<int> &a) {
  printf("%d\n", (int)a.size());
  REP(i, (int)a.size()) printf("%d%c", a[i] + 1, " \n"[i + 1 == a.size()]);
  fflush(stdout);
  vector<int> b(n);
  REP(i, n) scanf("%d", &b[i]);
  return b;
}

int main() {
  dfs(0, 0, 1024);
  for (int i = 10; i < 20; ++i)
    REP(j, 1024)
      g[i][j] = !g[i - 10][j];
  scanf("%d", &n);
  REP(i, n) ans[i] = INT_MAX;
  REP(i, 20) {
    vector<int> a;
    REP(j, n) {
      if (g[i][j]) a.push_back(j);
    }
    if (a.empty()) continue;
    vector<int> b = qry(a);
    REP(j, n) if (!g[i][j]) ans[j] = min(ans[j], b[j]);
  }
  puts("-1");
  REP(i, n) printf("%d%c", ans[i], " \n"[i == n - 1]);
  fflush(stdout);
  return 0;
}