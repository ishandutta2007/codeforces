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

int go(string s) {
	int a = 5, b = 5;
	int x = 0, y = 0;
	for(int i = 0; i < 10; i++) {
		if(i % 2 == 0) {
			a--;
			x += s[i] - '0';
		} else {
			b--;
			y += s[i] - '0';
		}
		if(x + a < y || y + b < x)
			return i + 1;
	}
	return 10;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		string t = s, r = s;
		for(int i = 0; i < 10; i++)
			if(t[i] == '?')
				t[i] = '0' + i % 2;
		for(int i = 0; i < 10; i++)
			if(r[i] == '?')
				r[i] = '0' + 1 - i % 2;
		cout << min(go(t), go(r)) << '\n';
	}

}