%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

char s[55];
int n, ans;

bool ok(int l, int r) {
  for (; l < r; l++, r--)
    if (s[l] != s[r]) return 1;
  return 0; 
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (ok(i, j)) ans = max(ans, j - i + 1);
  printf("%d\n", ans);
  return 0;
}

// wlzhouzhuan, 233