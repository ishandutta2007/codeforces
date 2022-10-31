%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 50;
long long fac[21];
ll a[N];
int n, k, half;
long long S, ans = 0LL;

void pre() {
  fac[0] = 1LL;
  for (int i = 1; i <= 20; i++)
    fac[i] = (long long)i * fac[i - 1];
  return ; 
}

unordered_map <ll, ll> cnt[N];

void dfs1(int x, ll tot, int used) {
  if (used > k || tot > S) return ;
  if (x == half + 1) {
    cnt[used][tot]++;
    return ;
  }
  dfs1(x + 1, tot, used);
  dfs1(x + 1, tot + a[x], used);
  if (a[x] <= 20)
    dfs1(x + 1, tot + fac[a[x]], used + 1);
}

void dfs2(int x, ll tot, int used) {
  if (used > k || tot > S) return ;
  if (x == n + 1) {
    for (int i = 0; i <= k - used; i++)
      ans += cnt[i][S - tot];
    return ;
  }
  
  dfs2(x + 1, tot, used);
  dfs2(x + 1, tot + a[x], used);
  if (a[x] <= 20)
    dfs2(x + 1, tot + fac[a[x]], used + 1); 
}

int main() {
  pre();
  
  scanf("%d%d%lld", &n, &k, &S);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[i]);
  
  half = (n + 1) >> 1;
  
  dfs1(1, 0LL, 0);
  dfs2(half + 1, 0LL, 0);
  printf("%lld\n", ans);
  return 0;
}