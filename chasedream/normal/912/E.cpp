// zzfy003
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 35;
ll a[N], adj[N], k;
vector <ll> s[2];
int n, cnt;

void dfs(int id, int x, ll now) {
  s[id].push_back(now);
  for (int i = x; i <= cnt; i++) {
    if (1e18 / adj[i] >= now)
      dfs(id, i, now * adj[i]);
  }
}

ll check(ll mid) {
  int j = 0;
  ll ret = 0LL;
  for (int i = (int)s[0].size() - 1; i >= 0; i--) {
    //printf("%d %d\n", i, j);
    while (j < (int)s[1].size() && s[1][j] <= mid / s[0][i]) j++;
    ret += j;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  scanf("%lld", &k);
  
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1)
      adj[++cnt] = a[i];
  }
  dfs(0, 1, 1);
  
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!(i & 1))
      adj[++cnt] = a[i];
  }
  dfs(1, 1, 1);
  
  sort(s[0].begin(), s[0].end());
  sort(s[1].begin(), s[1].end());
  
  //printf("%d %d\n", s[0].size(), s[1].size());
  /*
  for (int i = 0; i < s[0].size(); i++)
    printf("%lld ", s[0][i]);
  for (int i = 0; i < s[1].size(); i++)
    printf("%lld ", s[1][i]);
  */
  
  ll l = 1, r = 1e18;
  while (l < r) {
    //printf("%lld %lld\n", l, r);
    ll mid = (l + r) >> 1;
    //printf("%lld\n", check(mid));
    if (check(mid) >= k) r = mid;
    else l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}