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
int a[maxn], b[maxn], ans[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  rep1(i, n) cin >> b[i];
  rep1(i, n) ans[a[i]] = b[i];
  rep1(i, n) cout << ans[i] << ' ';
  
  return 0;
}