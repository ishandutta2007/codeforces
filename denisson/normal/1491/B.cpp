#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << ' = ' << (a) << endl; 

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

int n, uu, vv;
int a[111];

ll solve() {
  cin >> n >> uu >> vv;
  for (int i = 0; i < n; ++i) cin >> a[i];

  int v = -1;

  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i - 1]) > 1) {
      v = i;
      break;
    }
  }

  if (v == -1) {
    sort(a, a + n);

    if (a[0] == a[n - 1]) {
      return vv + min(uu, vv);
    } else {
      return min(uu, vv);
    }
  }

  return 0;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    cout << solve() << "\n";
  }

}