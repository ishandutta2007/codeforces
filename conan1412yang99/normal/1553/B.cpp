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

signed main()
{
	IO_OP;

	int q;
	cin >> q;
	while(q--) cout << ([]() -> bool {
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < int(s.size()); i++) {
			string r;
			for(int j = i; j < int(s.size()); j++) {
				r += s[j];
				if(r.size() > t.size()) break;
				string tt = r;
				int k = j - 1;
				while(k >= 0 && tt.size() < t.size())
					tt += s[k--];
				if(tt == t) return true;
			}
		}
		return false;
	}() ? "YES" : "NO") << '\n';

}