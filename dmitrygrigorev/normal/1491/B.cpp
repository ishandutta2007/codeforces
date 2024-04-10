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
  int n, u, v;
  cin >> n >> u >> v;
  vector<int> a(n);

  for (auto &x : a) cin >> x;

  bool good = false;
  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i-1]) > 1) good = true;
  }

  if (good) {
    cout << 0 << '\n';
    return;
  }

  good = false;
  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i-1]) > 0) good = true;
  }

  if (good) {
    cout << min(u, v) << '\n';
    return;
  }

  cout << v + min(u, v) << '\n';
  return;

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