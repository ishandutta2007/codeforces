#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
template <size_t maxn> struct SuffixArray {
  const char *s;
  int n, sa[maxn], rank[maxn], height[maxn];
  int t[maxn], t2[maxn], c[maxn];
  SuffixArray(const char *s) : s(s) {
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

const int maxn = 1e5 + 10;
char s[maxn];
int k;
int main() {
  scanf("%s%d", s, &k);
  SuffixArray<maxn> sa(s);
  for (int i = 1; i <= sa.n; ++i) {
    char *t = s + sa.sa[i];
    for (int j = sa.height[i]; t[j]; ++j) {
      k--;
      for (int l = i + 1; l <= sa.n; ++l) {
        if (sa.height[l] <= j) {
          break;
        }
        else {
          k--;
        }
      }
      if (k <= 0) {
        t[j + 1] = 0;
        puts(t);
        return 0;
      }
    }
  }
  puts("No such line.");
  return 0;
}