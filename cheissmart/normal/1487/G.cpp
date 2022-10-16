#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 402, M = 998244353;

int dp1[2][N][2][2], dp2[2][N][N][3][3];
int sa[N], na[N][N];
int c[26];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M; 
}

int qpow(int a, int b) {
	if(b == 0) return 1;
	ll t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < 26; i++)
		cin >> c[i];

	dp1[0][0][0][0] = 25 * 25, dp1[0][1][0][1] = 25, dp1[0][1][1][0] = 25, dp1[0][2][1][1] = 1;
	for(int i = 2; i < n; i++) {
		memset(dp1[(i + 1) % 2], 0, sizeof dp1[(i + 1) % 2]);
		for(int c = 0; c <= i; c++) {
			for(int j = 0; j < 2; j++) {
				for(int k = 0; k < 2; k++) if(dp1[i % 2][c][j][k]) {
					if(j == 0) {
						add(dp1[(i + 1) % 2][c + 1][k][1], dp1[i % 2][c][j][k]); // add 1
						add(dp1[(i + 1) % 2][c][k][0], dp1[i % 2][c][j][k] * 24LL % M); // add 0
					} else { // add 0
						add(dp1[(i + 1) % 2][c][k][0], dp1[i % 2][c][j][k] * 25LL % M);
					}
				}
			}
		}
	}
	for(int c = n; c >= 0; c--) {
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++) {
				add(sa[c], dp1[n % 2][c][j][k]);
			}
		add(sa[c], sa[c + 1]);
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			int a = (i == 1 ? 1 : 0) + (j == 1 ? 1 : 0);
			int b = (i == 2 ? 1 : 0) + (j == 2 ? 1 : 0);
			int ways = 1;
			if(i == 0) ways *= 24;
			if(j == 0) ways *= 24;
			dp2[0][a][b][i][j] = ways;
		}
	}
	for(int i = 2; i < n; i++) {
		memset(dp2[(i + 1) % 2], 0, sizeof dp2[(i + 1) % 2]);
		for(int c1 = 0; c1 <= i; c1++) {
			for(int c2 = 0; c1 + c2 <= i; c2++) {
				for(int j = 0; j < 3; j++) {
					for(int k = 0; k < 3; k++) if(dp2[i % 2][c1][c2][j][k]) {
						for(int l = 0; l < 3; l++) {
							int ways = dp2[i % 2][c1][c2][j][k];
							ways = ways * ((l == 0 ? 24LL : 1LL) - (j == l ? 1LL : 0LL)) % M;
							int new_c1 = c1 + (l == 1 ? 1 : 0), new_c2 = c2 + (l == 2 ? 1 : 0);
							add(dp2[(i + 1) % 2][new_c1][new_c2][k][l], ways);
						}
					}
				}
			}
		}
	}
	for(int c1 = n; c1 >= 0; c1--) {
		for(int c2 = n - c1; c2 >= 0; c2--) {
			for(int j = 0; j < 3; j++) {
				for(int k = 0; k < 3; k++) {
					add(na[c1][c2], dp2[n % 2][c1][c2][j][k]);
				}
			}
			add(na[c1][c2], na[c1 + 1][c2]);
			add(na[c1][c2], na[c1][c2 + 1]);
			add(na[c1][c2], M - na[c1 + 1][c2 + 1]);
		}
	}

	int ans = 26LL * 26 * qpow(25, n - 2) % M;
	for(int i = 0; i < 26; i++) {
		add(ans, M - sa[c[i] + 1]);
	}
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < i; j++) {
			add(ans, na[c[i] + 1][c[j] + 1]);
		}
	}
	cout << ans << endl;

}