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

const int maxn = 10010;

template <size_t maxn> struct SuffixArray {
  const char *s;
  int n, sa[maxn], rank[maxn], height[maxn];
  int t[maxn], t2[maxn], c[maxn];
  void build(char *s) {
    this->s = s;
    n = strlen(s) + 1;
    build_sa(128);
    build_height();
  }
  SuffixArray() {}
  void build_sa(int m) {
    int i, *x = t, *y = t2;
    REP(i, m) c[i] = 0;
    REP(i, n) c[x[i] = s[i]]++;
    REP(i, m) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--)
      sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for (i = n - k; i < n; i++)
        y[p++] = i;
      REP(i, n) if (sa[i] >= k) y[p++] = sa[i] - k;
      REP(i, m) c[i] = 0;
      REP(i, n) c[x[y[i]]]++;
      REP(i, m) c[i] += c[i - 1];
      for (i = n - 1; i >= 0; i--)
        sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1;
      x[sa[0]] = 0;
      for (i = 1; i < n; i++)
        x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]
                       ? p - 1
                       : p++;
      if (p >= n)
        break;
      m = p;
    }
  }
  void build_height() {
    int i, k = 0;
    for (i = 0; i < n; i++)
      rank[sa[i]] = i;
    height[0] = 0;
    for (i = 0; i < n; i++) {
      if (rank[i] == 0)
        continue;
      if (k)
        k--;
      int j = sa[rank[i] - 1];
      while (s[i + k] == s[j + k])
        k++;
      height[rank[i]] = k;
    }
  }
};

template<size_t maxn> struct Segment {
  int n, t[maxn * 2];
  void build() {
    for (int i = n - 1; i; --i)
      t[i] = min(t[i<<1], t[i<<1|1]);
  }
  int query(int l, int r) {
    int ret = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) ret = min(ret, t[l++]);
      if (r&1) ret = min(ret, t[--r]);
    }
    return ret;
  }
};
SuffixArray<maxn> sa;
Segment<maxn> seg;
int n, q;
char s[maxn];

int lcp(int a, int b) {
  if (a == b) return n - a;
  a = sa.rank[a];
  b = sa.rank[b];
  if (a > b)
    swap(a, b);
  return seg.query(a + 1, b + 1);
}

int d[5010][5010];

int ans[5010];

int main() {
  scanf("%s", s);
  sa.build(s);
  seg.n = sa.n;
  for (int i = 0; i < sa.n; ++i)
    seg.t[i + seg.n] = sa.height[i];
  seg.build();
  const int n = strlen(s);
  REPE(l, 1, n) REP(i, n) {
    int j = i + l - 1;
    if (j >= n) break;
    if (l == 1) {
      d[i][j] = 1;
    }
    else if (l == 2) {
      if (s[i] == s[j]) d[i][j] = 2;
    }
    else {
      if (s[i] == s[j] && d[i+1][j-1]) d[i][j] = 1;
      int hl = l / 2;
      if (lcp(i, j - hl + 1) >= hl && d[i][i+hl-1]) d[i][j] = d[i][i+hl-1] + 1;
    }
    ans[d[i][j]]++;
  }
  for (int i = n; i >= 1; --i) ans[i] += ans[i + 1];
  REPE(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}