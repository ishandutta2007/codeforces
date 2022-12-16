#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

const int N = 200200;
int p[N];
int n, k;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  vector<int> ind;
  ll sum = 0;
  for (int i=1; i<=n; ++i) {
    cin >> p[i];
    if (p[i] > n-k) {
      sum += p[i];
      ind.push_back(i);
    }
  }
  ll ans = 1;
  for (int i=1; i<ind.size(); ++i) {
    ans = (ans*(ind[i]-ind[i-1]))%MOD;
  }
  cout << sum << " " << ans << endl;
  return 0;
}