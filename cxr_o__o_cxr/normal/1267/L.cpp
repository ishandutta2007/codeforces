#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;

int read() {
  int res = 0, w = 1; char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') c = getchar(), w = -1;
  while (isdigit(c)) res = (res << 1) + (res << 3) + c - '0', c = getchar();
  return res * w;
}

const int N = 1e3 + 10;

int n, l, k, cnt[N];
char s[N * N], ans[N][N];
string res[N];

int main() {
  n = read(), l = read(), k = read();
  scanf("%s", s + 1);
  sort(s + 1, s + n * l + 1);
  for (int i = 1; i <= n * l; i++) cnt[s[i] - 'a']++;
  for (int i = 1; i <= l; i++) {
    int p = k;
    while (p > 1 && ans[p - 1][i - 1] == ans[k][i - 1]) p--;
    int c = 0;
    while (p <= k) {
      while (!cnt[c]) c++;
      cnt[c]--;
      ans[p][i] = c + 'a';
      p++;
    }
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= l; j++) {
      if (!ans[i][j]) {
        while (!cnt[c]) c++;
        cnt[c]--;
        ans[i][j] = c + 'a';
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%s\n", ans[i] + 1);
  return 0;
}