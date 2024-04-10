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

ll code(pair<int, int> &a) {
	ll x = a.x, y = a.y;
	return x*x+y*y;
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	ll A = code(a), B = code(b);
	return (A<B);
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int> > a(n), b(n);
	int u1 = 0, u2 = 0;
	for (int i = 0; i < 2*n; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == 0) a[u1++] = mp(x, y);
		else b[u2++] = mp(x, y);
	}

	sort(all(a), cmp);
	sort(all(b), cmp);

	db ans = 0;
	for (int i = 0; i < n; ++i) {
		ll dx = a[i].x - b[i].x;
		ll dy = a[i].y - b[i].y;
		ll S = dx*dx + dy*dy;
		//cout << a[i].x << " " << a[i].y << endl;
		ans += sqrt(S);
	}

	cout << fixed << ans << '\n';
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

	cout.precision(10);

	for (int i = 0; i < t; ++i) solve();

}