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

const int INF = 1e9 + 7, N = 2e5 + 7;

string s[2];
int dp[N][2][3];
void cmax(int& a, int b) {
	a = max(a, b);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n >> s[0] >> s[1];

	for(int i = n - 1; i >= 0; i--) {
		for(int lst = 0; lst < 2; lst++) {
			for(int no = 0; no < 3; no++) {
				// 0 0 
				cmax(dp[i][lst][no], dp[i + 1][lst][2]);

				// 1 1
				if(s[0][i] == '1' && s[1][i] == '1' && no == 2) 
					cmax(dp[i][lst][no], dp[i + 1][lst ^ 1][lst] + 2);

				// 0 1 / 1 0
				if(s[lst][i] == '1' && no != lst)
					cmax(dp[i][lst][no], dp[i + 1][lst][2] + 1);
				if(s[lst ^ 1][i] == '1' && no != (lst ^ 1))
					cmax(dp[i][lst][no], dp[i + 1][lst ^ 1][lst] + 1);
			}
		}
	}

	cout << dp[0][0][2] << '\n';

}