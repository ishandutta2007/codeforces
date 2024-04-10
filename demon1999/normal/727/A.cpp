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

ll a, b;
vector<int> ch;

map<int, int> use;
void out() {
	cout << "YES\n";
	cout << sz(ch) << "\n";
	forn (i, sz(ch))
		cout << ch[i] << " ";
	exit(0);
}

void pr(ll k) {
	if (k > b)
		re;
	if (use[k])
		re;
	use[k] = 1;
	ch.push_back(k);
	if (k == b)
		out();
	pr(2LL * k);
	pr(10LL * k + 1LL);
	ch.pop_back();
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> a >> b;
	pr(a);
	cout << "NO\n";
	re 0;
}