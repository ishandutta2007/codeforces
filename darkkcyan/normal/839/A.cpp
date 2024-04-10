#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  int s = 0;
  rep1(i, n) {
    int a; cin >> a;
    s += a;
    int t = min(s, 8);
    s -= t;
    k -= t;
    if (k <= 0) {
      cout << i;
      exit(0);
    }
  }
  cout << -1;

  return 0;
}