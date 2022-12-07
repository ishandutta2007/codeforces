#include <cstdio>
#include <cstring>
#define M 1000000007
#define ll long long

int n, q, k, m;
char s0[105], t[100005], s[1000005];

int two[100005];

int cnt[100005][26];

char ss[26][1000005];

int check(int w, int len, char* s);

int solve(int w, int len, char* s) {
  if (w > k) return 0;
  int next_len = 0;
  for (int i = 0; i < len; ++i) {
    ss[w + 1][next_len++] = s[i];
    ++i;
    if (i < len && s[i] != t[w]) return 0;
  }
  if (next_len == 0) {
    return two[k - w];
  }
  if (next_len == 1) {
    int p = ss[w + 1][0] - 'a';
    return (cnt[k][p] - (ll)cnt[w][p] * two[k - w] % M + M) % M;
  }
  return check(w + 1, next_len, ss[w + 1]);
}

int check(int w, int len, char* s) {
  // printf("check %d %d\n", w, len);
  // first place is 0
  int ret = 0;
  if (s[0] == t[w]) ret = solve(w, len - 1, s + 1);
  ret += solve(w, len, s);
  return ret % M;
}

int check_s0(int base_w, int len) {
  int j = 0;
  for (int i = base_w; i < m && j < len; ++i, ++j) {
    if (s0[i] != s[j]) return 0;
  }
  int next_len = 0;
  for (; j < len;) {
    ss[1][next_len++] = s[j];
    j++;
    for (int i = 0; i < m && j < len; ++i, ++j) {
      if (s0[i] != s[j]) return 0;
    }
  }
  
  if (next_len == 0) {
    return two[k];
  }

  //printf("ok %d\n", base_w);

  return check(1, next_len, ss[1]);
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s0);
  m = strlen(s0);
  scanf("%s", t + 1);

  two[0] = 1;
  for (int i = 1; i <= n; ++i)
    two[i] = two[i - 1] * 2 % M;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j)
       cnt[i][j] = cnt[i - 1][j] * 2 % M;
    cnt[i][t[i] - 'a'] = (cnt[i][t[i] - 'a'] + 1) % M;
  }

  int ans = 0;
  while(q--) {
    scanf("%d", &k);
    scanf("%s", s);
    int len = strlen(s);

    ans = 0;
    for(int w = 0; w <= m; ++w) {
      ans = (ans + check_s0(w, len)) % M;
    }
    printf("%d\n", ans);
  }
}