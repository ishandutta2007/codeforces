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

bool go(string s, string t) {
	int i = 0, j = 0;
	for(; i < int(s.size()) && j < int(t.size()); i++) {
		if(i % 2 != j % 2) continue;
		if(s[i] == t[j]) j++;
	}
	return j == int(t.size());
}

signed main()
{
	IO_OP;

	int q;
	cin >> q;
	while(q--) {
		string s, t;
		cin >> s >> t;
		reverse(ALL(s)), reverse(ALL(t));
		cout << (go(s, t) ? "YES" : "NO") << '\n';	
	}
	
}