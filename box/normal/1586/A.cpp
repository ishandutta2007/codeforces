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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    int oddpos = 1;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sum += x;
      if (x % 2)
        oddpos = i;
    }
    bool comp = 0;
    for (int i = 2; i * i <= sum; i++)
      if (sum % i == 0)
        comp = 1;
    if (comp) {
      cout << n << endl;
      for (int i = 1; i <= n; i++)
        cout << i << ' ';
      cout << endl;
    } else {
      cout << n - 1 << endl;
      for (int i = 1; i <= n; i++)
        if (i != oddpos)
          cout << i << ' ';
      cout << endl;
    }
  }
}