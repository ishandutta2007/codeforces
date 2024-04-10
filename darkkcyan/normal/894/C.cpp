#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 1111
int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  rep1(i, n - 1) {
    if (a[i] % a[0]) {
      cout << -1;
      return 0;
    }
  }
  if (n == 1)
    cout << "1\n" << a[0];
  else {
    cout << 2 * (n - 1) << '\n';
    rep1(i, n - 1) {
      cout << a[i] << ' ' << a[0] << ' ';
    }
  }

  return 0;
}