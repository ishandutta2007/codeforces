#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 105;

bool dp[N][N][N][2];
bool pre[N][N][N][2];

signed main()
{
	IO_OP;
	
	dp[0][0][0][0] = dp[0][0][0][1] = 1;
	for(int i = 0; i < N - 1; i++) {
		for(int j = 0; j < N - 1; j++) {
			for(int k = 0; k < N - 1; k++) {
				for(int l = 0; l < 2; l++) {
					if(dp[i][j][k][l] == 0) continue;
					for(int r = 0; r < 2; r++) {
						int ii = i, jj = j, kk = k;
						if(r == l) {
							if(l == 0) ii++;
							else kk++;
							dp[ii][jj][kk][r] = 1;
							pre[ii][jj][kk][r] = l;
						} else {
							jj++;
							dp[ii][jj][kk][r] = 1;
							pre[ii][jj][kk][r] = l;
						}
					}
				}
			}
		}
	}

	int t;
	cin >> t;
	while(t--) {
		int a, b, c, d = 0;
		cin >> a >> b >> c;
		if(dp[a][b][c][d] == 0) d = 1;
		string s;
		while(true) {
			if(a == 0 && b == 0 && c == 0) {
				s += '0' + d;
				break;
			}
			s += '0' + d;
			int dd = pre[a][b][c][d];
			if(dd == d) {
				if(d == 0) a--;
				else c--;
			} else {
				b--;
			}
			d = dd;
		}
		cout << s << endl;
	}

}