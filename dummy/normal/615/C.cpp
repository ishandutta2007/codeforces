#include <bits/stdc++.h>

using namespace std;

const int inf = 1e7;

char s[3003], t[3003], r[3003];
int dp[3003], last[3003];
pair< int, int > sel[3003];

int b[3003];


int main() {
  scanf("%s%s", s, t);
  int n = strlen(s);
  int m = strlen(t);
  memcpy(r, s, sizeof s);
  reverse(r, r+n);
  for(int i = 0; i<m; i++)
    dp[i] = inf;
  dp[m] = 0;
  for(int off = m-1; off>= 0; off--) {
    int len = m-off;
    int i = 0, j = -1;
    b[0] = -1;
    while(i<len) {
      while(j >= 0 && t[i+off] != t[j + off]) j = b[j];
      i++; j++;
      b[i] = j;
    }
    i = j = 0;
    while(i<n) {
      while(j >= 0 && s[i] != t[j + off]) j = b[j];
      i++; j++;
      if(dp[off+j]+1 < dp[off]) {
        dp[off] = dp[off+j] + 1;
        last[off] = off+j;
        sel[off] = make_pair(i - j + 1, i);
      }
      if(j == len)
        break;
    }

    i = j = 0;
    while(i<n) {
      while(j >= 0 && r[i] != t[j + off]) j = b[j];
      i++; j++;
      if(dp[off+j]+1 < dp[off]) {
        dp[off] = dp[off+j] + 1;
        last[off] = off+j;
        sel[off] = make_pair(n - i + j, n - i + 1);
      }
      if(j == len)
        break;
    }
  }
  if(dp[0] >= inf) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dp[0]);
  int now = 0;
  while(now < m) {
      printf("%d %d\n", sel[now].first, sel[now].second);
    assert(now < last[now]);
    now = last[now];
  }
  return 0;
}