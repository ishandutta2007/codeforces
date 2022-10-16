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

const int INF = 1e9 + 7;

int vis[1001][1001], d[1001][1001];
int last[10], s[10];
char a[1001][1001];
V<pi> q[10];
int dd[][2] = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

signed main()
{
	IO_OP;

	int n, m ,p;
	cin >> n >> m >> p;
	for(int i=1;i<=p;i++) cin >> s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin >> a[i][j];
			if(isdigit(a[i][j])) {
				vis[i][j] = a[i][j] - '0';
				q[a[i][j]-'0'].EB(i, j);
			}
		}
	int times = 1;
	while(true) {
		bool has_change = false;
		for(int i=1;i<=p;i++) {
			for(;last[i]<q[i].size();last[i]++){
				int x = q[i][last[i]].F, y = q[i][last[i]].S;
				if(d[x][y] >= s[i] * times) break;
				for(int dir=0;dir<4;dir++) {
					int ii = x + dd[dir][0], jj = y + dd[dir][1];
					if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
					if(a[ii][jj] == '#' || vis[ii][jj]) continue;
					vis[ii][jj] = i;
					q[i].EB(ii, jj);
					d[ii][jj] = d[x][y] + 1;
					has_change = true;
				}
			}
		}
		if(!has_change) break;
		times++;
	}
	for(int i=1;i<=p;i++) cout << q[i].size() << " ";
}