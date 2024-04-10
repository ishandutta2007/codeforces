#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong n, m, a, b; cin >> n >> m >> a >> b;
  --a, --b;
  llong ra = a / m, ca = a % m;
  llong rb = b / m, cb = b % m;
  clog << ra << ' ' << ca << ' ' << rb << ' ' << cb << endl;
  llong lr = (n - 1) / m, lc = (n - 1) % m;
  if (ra == rb) cout << 1, exit(0);
  if (ca == cb + 1) cout << 2, exit(0);
  if (rb == lr and cb == lc) cb = m - 1;
  if (rb == ra + 1) {
    if (ca == 0 and cb == m  - 1) cout << 1;
    else cout << 2;
    exit(0);
  }
  llong ans = 1;
  if (ca != 0) ++ans;
  if (cb != m - 1) ++ans;
  ans = max(ans, 1LL);
  cout << ans;
  
  return 0;
}