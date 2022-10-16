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

const int INF = 1e9 + 7, N = 255;

int a[N][N], b[N][N], isr[N * N], isc[N * N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++) {
		int mx = -1;
		for(int j = 0; j < m; j++) mx = max(mx, a[i][j]);
		isr[mx] = 1;
	}
	for(int j = 0; j < m; j++) {
		int mx = -1;
		for(int i = 0; i < n; i++) mx = max(mx, a[i][j]);
		isc[mx] = 1;
	}
	queue<pi> q;
	int x = -1, y = -1;
	for(int i = n * m; i >= 1; i--) {
		if(isr[i]) x++;
		if(isc[i]) y++;
		if(isr[i] || isc[i])
			b[x][y] = i;
		else {
			assert(q.size());
			pi p = q.front(); q.pop();
			b[p.F][p.S] = i;
		}
		if(isr[i]) {
			for(int j = y - 1; j >= 0; j--)
				q.push({x, j});
		}
		if(isc[i]) {
			for(int j = x - 1; j >= 0; j--)
				q.push({j, y});
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cout << b[i][j] << " \n"[j == m - 1];

}