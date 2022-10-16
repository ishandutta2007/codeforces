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

const int INF = 1e9 + 7, N = 505;

int a[N], dp[N][N], dp2[N][N], trans[N][N][N];

void cmax(int& a, int b) {
	a = max(a, b);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < n; j++) for(int k = 0; k <= n; k++) {
			trans[i + 1][j][k] = dp[i + 1][j] + a[k] * (i + 1);
			if(i + 2 <= n) trans[i + 1][j][k] = max(trans[i + 1][j][k], trans[i + 2][j][k]);
		}
		for(int j = 0; j < n; j++) {
			auto go = [&] () {
				int res = -INF;
				for(int k = i; k < n; k++) {
					int delta = i - k + 1;
					if(j + delta < 0 || j + delta >= n) continue;
					if(a[k] == 0)
						cmax(res, trans[k + 1][j + delta][n] - a[k] * i);
					else
						cmax(res, trans[k + 1][j + delta][k] - a[k] * i);
					if(k > i) cmax(res, dp2[k][j + delta] + a[k] * (k - i));
				}
				return res;
			};
			dp[i][j] = go();			
			int hebe = a[i];
			a[i] = 0;
			dp2[i][j] = go();
			a[i] = hebe;
		}
	}
	cout << dp[0][0] << '\n';

}