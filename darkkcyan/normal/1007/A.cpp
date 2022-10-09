#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define llong long long 
#define clog cerr << __LINE__ << ": "
#define _(x) << #x << " = " << (x) << "; "

#define maxn 101010
int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  int f = 0;
  int ans = 0;
  rep(i, n) {
    while (f < n and a[f] == a[i]) ++f;
    if (f >= n) break;
    ++ans;
    ++f;
  }
  cout << ans;

  return 0;
}