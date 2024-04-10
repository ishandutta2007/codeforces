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

ll a[6], n, k[6], p[6];
vector<string> ans;
vector<int> q[6];
string qqq[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	forn (i, 6)
		cin >> a[i];
	cin >> n;
	ans.resize(n);
	forn (i, n) {
		string s;
		cin >> s;
		ans[i] = s;
		if (s == "S,M") {
			q[0].push_back(i);
			p[0]++;
		}
		if (s == "M,L") {
			q[1].push_back(i);
			p[1]++;
		}
		if (s == "L,XL") {
			q[2].push_back(i);
			p[2]++;
		}
		if (s == "XL,XXL") {
			q[3].push_back(i);
			p[3]++;
		}
		if (s == "XXL,XXXL") {
			q[4].push_back(i);
			p[4]++;
		}
		if (s == "S")
			a[0]--;
		if (s == "M")
			a[1]--;
		if (s == "L")
			a[2]--;
		if (s == "XL")
			a[3]--;
		if (s == "XXL")
			a[4]--;
		if (s == "XXXL")
			a[5]--;
	}
	forn (i, 5) {
		int k1 = max(min(a[i], p[i]), 0LL);
		forn (j, k1) {
			ans[q[i][j]] = qqq[i];
		}
		for (int j = k1; j < sz(q[i]); j++)
			ans[q[i][j]] = qqq[i + 1];
		a[i] -= k1;
		a[i + 1] -= p[i] - k1;
	}
	forn (i, 6) {
		if (a[i] < 0) {
			cout << "NO\n";
			re 0;
		}
	}
	cout << "YES\n";
	forn (i, n)
		cout << ans[i] << "\n";
	re 0;
}