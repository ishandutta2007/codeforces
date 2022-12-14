#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
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

pi ask(int i, int j) {
	i++, j++;
	int a, b;
	cout << "or " << i << " " << j << endl;
	cin >> a;
	cout << "and " << i << " " << j << endl;
	cin >> b;
	return {a, b};
}

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	V<pi> tt(n);
	for(int i = 1; i < n; i++) {
		tt[i] = ask(0, i);
	}
	pi p = ask(1, 2);
	vi a(n);
	for(int bit = 0; bit < 30; bit++) {
		vi b(n, -1), idk;
		for(int i = 1; i < n; i++) {
			int OR = tt[i].F >> bit & 1, AND = tt[i].S >> bit & 1;
			if(AND == 1) { // both
				assert(b[0] == -1 || b[0] == 1);
				b[0] = b[i] = 1;
			} else if(OR == 0) { // none
				assert(b[0] == -1 || b[0] == 0);
				b[0] = b[i] = 0;
			} else {
				idk.PB(i);
			}
		}
		if(b[0] == -1) {
			assert(int(idk.size()) == n - 1);
			int OR = p.F >> bit & 1, AND = p.S >> bit & 1;
			if(AND == 1) { // both
				b[0] = 0;
			} else if(OR == 0) { // none
				b[0] = 1;
			} else {
				throw;
			}
		}
		for(int i:idk)
			b[i] = b[0] ^ 1;
		for(int i = 0; i < n; i++) {
			assert(b[i] != -1);
			a[i] |= b[i] << bit;
		}
	}
	sort(ALL(a));
	cout << "finish " << a[k - 1] << endl;

}