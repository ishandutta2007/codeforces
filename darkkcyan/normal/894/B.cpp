#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define rem ((llong)1e9 + 7)

llong mpow(llong b, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1, (b *= b) %= rem)
    if (m & 1) (ans *= b) %= rem;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  llong n, m, k; cin >> n >> m >> k;
  if (n > m) swap(n, m);
  if (k == -1) {
    if ((n & 1) and (~m & 1)) cout << 0, exit(0);
    if ((~n & 1) and (m & 1)) cout << 0, exit(0); 
  }
  --n, --m;
  cout << mpow(mpow(2, n), m);

  return 0;
}