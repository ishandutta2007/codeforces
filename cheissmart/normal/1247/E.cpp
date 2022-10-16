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

const int INF = 1e9 + 7, N = 2005, M = 1e9 + 7;

void add(int& x, int y) {
	x += y;
	if(x >= M) x -= M;
}

char a[N][N];
int dp1[N][N], dp2[N][N], l[N][N], u[N][N];
/*
	dp1: from left
	dp2: from top
*/

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	if(n == 1 && m == 1) return cout << 1 << endl, 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];

	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = m; j >= 1; j--) {
			if(a[i][j] == 'R') {
				cnt++;
				l[i][cnt] = j;
			}
		}
		for(int j = cnt + 1; j <= m; j++) l[i][j] = 1;
	}

	for(int j = 1; j <= m; j++) {
		int cnt = 0;
		for(int i = n; i >= 1; i--) {
			if(a[i][j] == 'R') {
				cnt++;
				u[j][cnt] = i;
			}
		}
		for(int i = cnt + 1; i <= n; i++) u[j][i] = 1;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i == 1 && j == 1) {
				dp1[i][j] = dp2[i][j] = 1;
			} else {
				// dp1
				{
					int can = m - j;
					add(dp1[i][j], (dp2[i][j - 1] - dp2[i][l[i][can+1]-1] + M) % M);
				}
				// dp2
				{
					int can = n - i;
					add(dp2[i][j], (dp1[i - 1][j] - dp1[u[j][can+1]-1][j] + M) % M);
				}
			}
			add(dp1[i][j], dp1[i-1][j]);
			add(dp2[i][j], dp2[i][j-1]);
		}
	}
	int x = 0;
	add(x, (dp1[n][m] - dp1[n-1][m] + M) % M);
	add(x, (dp2[n][m] - dp2[n][m-1] + M) % M);
	cout << x << endl;

}