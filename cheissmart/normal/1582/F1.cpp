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

int mn[1 << 9];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	memset(mn, 0x3f, sizeof mn);
	mn[0] = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vi tt;
		for(int j = 0; j < (1 << 9); j++) if(mn[j] < x) {
			tt.PB(j ^ x);
		}
		for(int j:tt)
			mn[j] = min(mn[j], x);
	}
	int cnt = 0;
	for(int i = 0; i < (1 << 9); i++)
		if(mn[i] < 600)
			cnt++;

	cout << cnt << '\n';
	for(int i = 0; i < (1 << 9); i++)
		if(mn[i] < 600)
			cout << i << ' ';
	cout << '\n';

}