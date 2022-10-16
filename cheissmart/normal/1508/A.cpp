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

string to_string(string s) {
	return s;
}

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

void solve() {
	int n; cin >> n;
	string a[3]; cin >> a[0] >> a[1] >> a[2];
	auto go = [&] (string a, string b, char c) {
		string s;
		int i = 0, j = 0;
		while(i < 2 * n || j < 2 * n) {
			while(i < 2 * n && a[i] != c) {
				debug(a[i]);
				s += a[i++];
			}
			while(j < 2 * n && b[j] != c) {
				debug(b[j]);
				s += b[j++];
			}
			if(i == 2 * n && j == 2 * n) break;
			if(i == 2 * n) s += b[j++];
			else if(j == 2 * n) s += a[i++];
			else {
				debug(c);
				assert(a[i] == c && b[j] == c);
				s += c, i++, j++;
			}
		}
		debug(s.size());
		for(int i = 0; i < int(s.size()); i++)
			debug(i, s[i]);
		assert(int(s.size()) <= 3 * n);
		while(int(s.size()) < 3 * n) s += '0';
		cout << s << '\n';
	};	
	for(char c = '0'; c <= '1'; c++)
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < i; j++) {
				if(count(ALL(a[i]), c) >= n && count(ALL(a[j]), c) >= n) {
					go(a[i], a[j], c);
					return;
				}
			}
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();
	
}