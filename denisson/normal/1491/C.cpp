#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << " = " << a << endl; 
#define forn(i, n) for (int i = 0; i < (n); ++i)

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
ll a[5555];
ll b[5555];

void solve() {

  cin >> n;
  forn(i, n) cin >> a[i], b[i] = 0;
  ll ans = 0;

  ll now = 0;

  forn(i, n) {
    now += b[i];

    ans += max((ll)0, a[i] - 1 - now);

   // cout << i << ' ' << max((ll)0, a[i] - 1 - now) << endl;

    if (a[i] > 1) {

    //  cout << i << ' ' << i + 2 << ' ' << i + a[i] << endl;

      b[i + 2]++;
      b[min((ll)5554, i + a[i] + 1)]--;
    }

    if (now > a[i] - 1) {
      b[i + 1] += now - a[i] + 1;
      b[i + 2] -= now - a[i] + 1;
    }
  }

  cout << ans << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }

}