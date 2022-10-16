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

const int INF = 1e9 + 7, N = 105;


signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		auto solve = [&] (string s) -> pair<string, int> {
			int cnt = 0;
			for(int i = 1; i < n; i++) {
				if(s[i] == '?')
					s[i] = s[i - 1] ^ 'R' ^ 'B';
				cnt += s[i] == s[i - 1];
			}
			return {s, cnt};
		};
		if(s[0] == '?') {
			s[0] = 'R';
			pair<string, int> sa = solve(s);
			s[0] = 'B';
			pair<string, int> na = solve(s);
			if(sa.S < na.S)
				cout << sa.F << '\n';
			else
				cout << na.F << '\n';
		} else {
			pair<string, int> sa = solve(s);
			cout << sa.F << '\n';
		}
	}

}