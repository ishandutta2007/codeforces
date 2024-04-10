#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n, q, mod;
	cin >> n >> q >> mod;

	auto add = [&] (int& a, int b) {
		a += b;
		if(a >= mod) a -= mod;
	};

	vi f(n + 1);
	f[1] = 1;
	for(int i = 2; i <= n; i++) {
		add(f[i], f[i - 1]);
		add(f[i], f[i - 2]);
	}

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++) {
		int b; cin >> b;
		add(a[i], mod - b);
	}

	for(int i = n - 1; i >= 0; i--) {
		if(i - 1 >= 0) add(a[i], mod - a[i - 1]);
		if(i - 2 >= 0) add(a[i], mod - a[i - 2]);
	}

	vi b(n), aux(n);

	int cnt = 0;

	auto upd = [&] (int pos) {
		if(pos >= n) return;
		cnt -= aux[pos];
		aux[pos] = b[pos] == a[pos];
		cnt += aux[pos];
	};
	for(int i = 0; i < n; i++) upd(i);

	while(q--) {
		char op; int l, r;
		cin >> op >> l >> r;
		l--, r--;
		if(op == 'A') { // -
			add(b[l], mod - 1);
			if(r + 1 < n)
				add(b[r + 1], f[r - l + 2]);
			if(r + 2 < n)
				add(b[r + 2], f[r - l + 1]);
		} else { // +
			add(b[l], 1);
			if(r + 1 < n)
				add(b[r + 1], mod - f[r - l + 2]);
			if(r + 2 < n)
				add(b[r + 2], mod - f[r - l + 1]);
		}
		upd(l), upd(r + 1), upd(r + 2);
		cout << (cnt == n ? "YES" : "NO") << '\n';
	}


}