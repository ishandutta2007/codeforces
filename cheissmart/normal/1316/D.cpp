#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
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

const int INF = 1e9 + 7, N = 1003;

string s = "UDLR";
string invs = "DURL";

int dd[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void NO() {
	cout << "INVALID" << endl;
	exit(0);
}

pi a[N][N];

char ans[N][N];
bool can[N][N], vis[N][N];

signed main()
{
	IO_OP;
	memset(ans, '.', sizeof ans);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin >> a[i][j].F >> a[i][j].S;
			if(a[i][j].F != -1) {
				ans[a[i][j].F][a[i][j].S] = 'X';
			}
		}
	}	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(ans[i][j] == 'X') {
				if(a[i][j] != MP(i, j)) {
					NO();
				}
			}
		}
	}
	for(int i=1;i<=n;i++)  {
		for(int j=1;j<=n;j++) {
			if(ans[i][j] == 'X') {
				queue<pi> q({{i, j}});
				can[i][j] = true;
				while(q.size()) {
					pi p = q.front(); q.pop();
					int x = p.F, y = p.S;
					for(int dir=0;dir<4;dir++) {
						int xx = x + dd[dir][0], yy = y + dd[dir][1];
						if(xx <= 0 || yy <= 0 || xx > n || yy > n) continue;
						if(!can[xx][yy] && a[xx][yy] == MP(i, j)) {
							can[xx][yy] = true;
							q.push({xx, yy});
							ans[xx][yy] = invs[dir];
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j] != MP(-1, -1)) {
				if(!can[i][j]) NO();
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j] == MP(-1, -1) && !vis[i][j]) {
				for(int dir=0;dir<4;dir++) {
					int ii = i + dd[dir][0], jj = j + dd[dir][1];
					if(ii <= 0 || jj <= 0 || ii > n || jj > n) continue;
					if(a[ii][jj] == MP(-1, -1)) {
						if(vis[ii][jj]) {
							vis[i][j] = 1;
							ans[i][j] = s[dir];
						} else {
							vis[i][j] = vis[ii][jj] = 1;
							ans[i][j] = s[dir];
							ans[ii][jj] = invs[dir];
						}
					}
				}
				if(vis[i][j] == 0) {
					NO();
				}
			}
		}
	}

	cout << "VALID" << endl;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) cout << ans[i][j];
		cout << endl;
	}
}