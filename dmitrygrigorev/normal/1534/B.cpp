#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {

  int n;
  cin >> n;

  vector<int> v(n+2, 0);
  for (int i = 1; i <= n; ++i) cin >> v[i];

  ll ans = 0;
  for (int i = 1; i < n+2; ++i) ans += abs(v[i] - v[i-1]);

  for (int i = 1; i <= n; ++i) {
    if (v[i] > v[i-1] && v[i] > v[i+1]) {
      ans -= min(v[i] - v[i-1], v[i] - v[i+1]);
    }
  }

  cout << ans << '\n';





}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}