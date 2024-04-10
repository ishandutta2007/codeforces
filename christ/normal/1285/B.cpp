#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
char s[MN];
void solve () {
  int n;
  scanf ("%d",&n);
  vector<int> a(n+1); ll sum = 0;
  for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), sum += a[i];
  ll cur = 0, mx = LLONG_MIN;
  for (int i = 2; i <= n; i++) {
    cur += a[i];
    mx = max(mx,cur);
    cur = max(cur,0LL);
  }
  ll ret = mx;
  cur = 0, mx = INT_MIN;
  for (int i = 1; i < n; i++) {
    cur += a[i];
    mx = max(mx,cur);
    cur = max(cur,0LL);
  }
  ret = max(ret,mx);
  printf (sum > ret ? "YES\n" : "NO\n");
}
int main () {
  int t;
  scanf ("%d",&t);
  while (t--) solve(); 
  return 0;
}