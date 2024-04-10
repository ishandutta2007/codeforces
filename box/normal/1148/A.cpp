#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b)
    cout << 2ll * a + 2 * c << endl;
  else
    cout << 1 + 2ll * min(a, b) + 2 * c << endl;
}