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
	string s;
	cin >> s;
	int n = int(s.size());
	vi cnt(26);
	for(char c:s)
		cnt[c - 'a']++;
	V<pi> tt;
	for(int i = 0; i < 26; i++)
		if(cnt[i])
			tt.EB(i, cnt[i]);
	if(int(tt.size()) == 1) {
		cout << s << '\n';
		return;
	}
	int j = -1;
	for(int i = 0; i < int(tt.size()); i++)
		if(tt[i].S == 1) {
			j = i;
			break;
		}
	if(j != -1) {
		char c = tt[j].F + 'a';
		string ans = string(1, c);
		for(int i = 0; i < int(tt.size()); i++) if(i != j)
			ans += string(tt[i].S, 'a' + tt[i].F);
		cout << ans << '\n';
		return;
	}
	int cnt_a = tt[0].S;
	if(cnt_a - 2 <= n - cnt_a) {
		string ans;
		ans += string(2, 'a' + tt[0].F);
		cnt_a -= 2;
		for(int i = 1; i < int(tt.size()); i++) {
			for(int j = 0; j < tt[i].S; j++) {
				ans += tt[i].F + 'a';
				if(cnt_a) {
					ans += 'a' + tt[0].F;
					cnt_a--;
				}
			}
		}
		assert(cnt_a == 0);
		cout << ans << '\n';
		return;
	}
	if(int(tt.size()) >= 3) {
		char c = tt[2].F + 'a';
		tt[2].S--;
		string ans;
		ans += tt[0].F + 'a';
		tt[0].S--;
		ans += tt[1].F + 'a';
		tt[1].S--;
		for(int i = 0; i < tt[0].S; i++)
			ans += tt[0].F + 'a';
		ans += c;
		for(int i = 1; i < int(tt.size()); i++)
			for(int j = 0; j < tt[i].S; j++)
				ans += tt[i].F + 'a';
		cout << ans << '\n';
		return;
	}
	assert(int(tt.size()) == 2);
	string ans;
	ans += tt[0].F + 'a';
	for(int i = 0; i < tt[1].S; i++)
		ans += tt[1].F + 'a';
	for(int i = 0; i < tt[0].S - 1; i++)
		ans += tt[0].F + 'a';
	cout << ans << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();
	
}