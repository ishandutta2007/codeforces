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

const int INF = 1e9 + 7, N = 2e5 + 7;

int cnt[20][N];

signed main()
{
	IO_OP;

	for(int i = 0; i < 20; i++) {
		for(int j = 1; j < N; j++) {
			cnt[i][j] = cnt[i][j - 1];
			if(!(j >> i & 1)) 
				cnt[i][j]++;
		}
	}

	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		int mn = INF;
		for(int i = 0; i < 20; i++) {
			mn = min(mn, cnt[i][r] - cnt[i][l - 1]);
		}
		cout << mn << '\n';
	}

}