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

void solve() {
	int n;
	string s;
	cin >> n >> s;
	string t = s;
	reverse(ALL(t));
	if(s == t) {
		cout << 0 << '\n';
		return;
	}

	int ans = INF;
	for(char c = 'a'; c <= 'z'; c++) {
		string t;
		for(char cc:s) if(cc != c)
			t.PB(cc);
		string r = t;
		reverse(ALL(r));
		if(r != t) continue;
		int L = -1, R = -1;
		if(t.size() & 1) L = R = int(r.size()) / 2;
		else R = int(r.size()) / 2, L = R - 1;
		L++, R++;
		int i = 0, j = 0;
		while(L) {
			if(s[i] != c)
				L--;
			i++;
		}
		while(R) {
			if(s[j] != c)
				R--;
			j++;
		}
		i--, j--;
		int tt = 0;
		while(i >= 0 || j < n) {
			if(i < 0) {
				assert(s[j++] == c);
				tt++;
			} else if(j >= n) {
				assert(s[i--] == c);
				tt++;
			} else if(s[i] != s[j]) {
				if(s[i] == c) i--;
				else if(s[j] == c) j++;
				else throw;
				tt++;
			} else {
				i--, j++;
			}
		}
		ans = min(ans, tt);
	}
	if(ans == INF)
		ans = -1;
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();	
	
}