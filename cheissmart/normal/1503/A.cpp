#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	assert(int(s.size()) == n);
	vi a, b;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') b.PB(i);
		else a.PB(i);
	}
	if(b.size() & 1) {
		cout << "NO\n";
		return;
	}
	string x(n, ' '), y(n, ' ');
	for(int i = 0; i < int(a.size()) / 2; i++) x[a[i]] = y[a[i]] = '(';
	for(int i = int(a.size()) / 2; i < int(a.size()); i++) x[a[i]] = y[a[i]] = ')';
	for(int i = 0; i < int(b.size()); i++) {
		x[b[i]] = '(';
		y[b[i]] = ')';
		if(i & 1) swap(x[b[i]], y[b[i]]);
	}
	auto ok = [&] (string s) {
		int bal = 0;
		for(char c:s) {
			if(c == '(') bal++;
			else bal--;
			if(bal < 0) return false;
		}
		return bal == 0;
	};
	if(ok(x) && ok(y)) {
		cout << "YES\n";
		cout << x << '\n';
		cout << y << '\n';
	} else {
		cout << "NO\n";
	}
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();

}