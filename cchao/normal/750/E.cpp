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
char s[maxn];
int n, q;
const int inf = 1e9;

typedef array<array<int, 5>, 5> M;

M op(const M &a, const M &b) {
  M ret = {{}};
  REP(i, 5) REP(j, 5) REP(k, 5) {
    int t = a[i][k] + b[k][j];
    if (t > inf) t = inf;
    ret[i][j] = k == 0 ? t : min(ret[i][j], t);
  }
  return ret;
}

M a[maxn << 2];
#define LC o<<1,l,m
#define RC o<<1|1,m+1,r
void build(int o, int l, int r) {
  if (l == r) {
    char c = s[l];
    M &m = a[o];
    REP(i, 5) REP(j, 5) {
      m[i][j] = i != j ? inf : 0;
    }
    if (c == '2') {
      m[0][0]++;
      m[0][1] = 0;
    }
    else if (c == '0') {
      m[1][1]++;
      m[1][2] = 0;
    }
    else if (c == '1') {
      m[2][2]++;
      m[2][3] = 0;
    }
    else if (c == '7') {
      m[3][3]++;
      m[3][4] = 0;
    }
    else if (c == '6') {
      m[3][3]++;
      m[4][4]++;
    }
    return;
  }
  int m = (l + r) >> 1;
  build(LC);
  build(RC);
  a[o] = op(a[o<<1], a[o<<1|1]);
}

int ql, qr;
M query(int o, int l, int r) {
  if (ql <= l && r <= qr) {
    return a[o];
  }
  int m = (l + r) >> 1;
  if (ql > m) return query(RC);
  if (qr <= m) return query(LC);
  return op(query(LC), query(RC));
}

int main() {
  scanf("%d%d%s", &n, &q, s);
  build(1, 0, n - 1);
  REP(tt, q) {
    scanf("%d%d", &ql, &qr);
    --ql, --qr;
    M ans = query(1, 0, n - 1);
    printf("%d\n", ans[0][4] == inf ? -1 : ans[0][4]);
  }
  return 0;
}