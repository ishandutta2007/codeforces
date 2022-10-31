%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 5005;
int a[N], s[N];
int ans[N], cnt[N], n, k;
int mx;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[a[i]]++; ans[i] = s[a[i]];
    mx = max(mx, s[a[i]]);
    cnt[ans[i]]++;
    if (s[a[i]]> k) {
      puts("NO"); exit(0);
    }
  }
  
  puts("YES");
  for (int i = 1, j = mx + 1; j <= k; i++) {
    if (cnt[ans[i]] >= 2) {
      cnt[ans[i]]--;
      ans[i] = j++;
      cnt[ans[i]]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  putchar('\n'); return 0;
}
// wlzhouzhuan, 233