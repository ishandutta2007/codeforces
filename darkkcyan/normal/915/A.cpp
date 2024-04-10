#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  int a[n];
  rep(i, n) cin >> a[i];
  sort(a, a + n, greater<int>());
  rep(i, n) {
    if (k % a[i]) continue;
    cout << k / a[i];
    break;
  }

  return 0;
}