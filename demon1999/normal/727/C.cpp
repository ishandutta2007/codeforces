#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

ll ans = 0, n;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	vector<double> qq;
	qq.resize(n);
	forn (i, n - 1) {
		cout << "? " << i + 1 << " " << i + 2 << "\n";
		cout.flush();
		cin >> qq[i];
	}
	cout << "? 1 3" << "\n";
	cout.flush();
	cin >> qq[n - 1];
	vector<double> ans(n, 0);
	double sum = (qq[0] + qq[1] + qq[n - 1]);
	ans[0] = sum / 2. - double(qq[1]);
	cout.precision(20);
	cout << "! " << ans[0];
	forn (i, n - 1) {
		ans[i + 1] = qq[i] - ans[i];
		cout << " " << ans[i + 1];
	}
	cout << "\n";
	cout.flush();
	re 0;
}