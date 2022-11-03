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

int n;
int a[200007];
int b[200007];

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  reverse(a, a + n);
  reverse(b, b + n);

  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
  }

  for (int i = 0; ; ++i) {
    int tot = n + i;
    int need = tot - tot / 4;

    ll res1 = 0, res2 = 0;

    res1 += 100 * (ll)min(need, i);
    int extra = max(0, need - i);
    if (extra > 0) {
      res1 += a[extra - 1];
    }

    extra = need;
    if (extra > 0) {
      res2 += b[min(n - 1, extra - 1)];
    }

   // cout << "====" << res1 << ' ' << res2 << endl;

    if (res1 >= res2) {
      cout << i << "\n";
      return;
    }
  }

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int tt; cin >> tt; // tt = 1;
  while (tt--) {
    solve();
  }
}