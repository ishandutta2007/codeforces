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

const int INF = 1e9 + 7, N = 102;

int dp[N];

int go(int len) {
	if(len <= 100) return dp[len];
	len -= (len - 100) / 34 * 34;
	while(len > 100) len -= 34;
	return dp[len];
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int bal = 0;
	for(char c:s) {
		if(c == 'R') bal++;
		else bal--;
	}
	if(bal > 0) {
		cout << "Alice\n";
		return;
	}
	if(bal < 0) {
		cout << "Bob\n";
		return;
	}
	vi aux;
	for(int i = 0; i < n -	 1; i++) {
		if(s[i] != s[i + 1]) {
			aux.PB(i);
		}
	}
	int sg = 0;

	for(int i = 0; i < SZ(aux); i++) {
		int len = 1;
		while(i + 1 < SZ(aux) && aux[i + 1] == aux[i] + 1){
			i++; 
			len++;
		}
		sg ^= go(len);
	}

	if(sg) cout << "Alice\n";
	else cout << "Bob\n";
}


signed main()
{
	IO_OP;
	
	for(int i = 1; i <= 100; i++) {
		set<int> s;
		for(int j = 1; j <= i; j++) {
			s.insert(dp[max(0, j - 2)] ^ dp[max(0, i - j - 1)]);
		}
		while(s.count(dp[i])) dp[i]++;
	}

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}