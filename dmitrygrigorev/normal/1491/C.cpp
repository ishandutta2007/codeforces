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
  vector<ll> a(n);

  for (auto &x : a) cin >> x;

  ll ans = 0;

  vector<ll> jump(n, 0);
  for (int i = 0; i < n; ++i) {

    ll finish = max(1LL, a[i] - jump[i]);
    ans += max(0LL, finish - 1);
    jump[i] += max(0LL, finish - 1);

    int q = min(a[i], (ll)n-i-1);

    //cout << a[i] << " " << jump[i] << " " << ans << " " << q << endl;

    if (a[i] > q) {
      jump[i] -= (a[i] - q);
    }

    while (q > 1 && jump[i] > 0) {
      jump[i + q]++;
      jump[i]--;
      q--;
    }

    if (i + 1 < n && jump[i] > 0) jump[i + 1] += jump[i];
    //cout << i << endl;
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

  for (int i = 0; i < t; ++i) {
    solve();
  }

}