#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n;
int a[maxn];
int du[maxn], dd[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  du[0] = 1;
  rep1(i, n - 1) {
    if (a[i] > a[i - 1]) du[i] = du[i - 1] + 1;
    else du[i] = 1;
  }
  dd[n - 1] = 1;
  for (int i = n - 1; i--; )
    if (a[i] < a[i + 1]) dd[i] = dd[i + 1] + 1;
    else dd[i] = 1;
    
  int ans = 0;
  rep(i, n) {
    ans = max(ans, du[i]);
    int l = i > 0 ? a[i - 1] : INT_MIN;
    int r = i < n - 1 ? a[i + 1] : INT_MAX;
    int tu = i > 0 ? du[i - 1] : 0;
    int td = i < n - 1 ? dd[i + 1] : 0;
    ans = max(ans, max(tu, td) + 1);
    if (l >= r or r - l == 1) continue;
    ans = max(ans, tu + td + 1);
  }
  cout << ans;
  
  return 0;
}