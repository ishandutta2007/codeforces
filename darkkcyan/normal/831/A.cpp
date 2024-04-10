#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i =-1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)

int n;
int a[111], b[111];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n - 1) b[i] = sgn(a[i] - a[i + 1]);
  rep(i, n - 2) {
    if (b[i + 1] < b[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";

  return 0;
}