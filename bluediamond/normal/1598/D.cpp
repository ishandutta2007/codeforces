#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
int n, a[N], b[N];
map<int, int> ma, mb;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    ma.clear(), mb.clear();
    for (int i = 1; i <= n; i++) ma[a[i]]++, mb[b[i]]++;

    int sol = 0;

    for (int i = 1; i <= n; i++) {
      sol += (ma[a[i]] - 1) * (mb[b[i]] - 1);
    }
    sol = n * (n - 1) * (n - 2) / 6 - sol;
    cout << sol << "\n";
  }

  return 0;
}