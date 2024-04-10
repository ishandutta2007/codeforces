#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second


const int maxn = 2e5 + 10;

int n, p[maxn], a[maxn], b[maxn], m, c[maxn];
vector<int> v[3][3];
int cur[3][3];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n) scanf("%d", &b[i]);
  scanf("%d", &m);
  REP(i, m) scanf("%d", &c[i]);
  REP(i, n) v[a[i] - 1][b[i] - 1].push_back(p[i]);
  REP(i, 3) REP(j, 3) sort(ALL(v[i][j]), greater<int>());
  REP(x, m) {
    int t = c[x] - 1;
    int tmp = INT_MAX;
    REP(i, 3) {
      if (v[t][i].size()) tmp = min(tmp, v[t][i].back());
      if (v[i][t].size()) tmp = min(tmp, v[i][t].back());
    }
    REP(i, 3) {
      if (v[t][i].size() && tmp == v[t][i].back()) v[t][i].pop_back();
      if (v[i][t].size() && tmp == v[i][t].back()) v[i][t].pop_back();
    }
    printf("%d%c", tmp == INT_MAX ? -1 : tmp, " \n"[x == m - 1]);
  }
  return 0;
}