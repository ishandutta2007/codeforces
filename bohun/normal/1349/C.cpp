#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int N = 1010;

queue <pair<int,int>> q;

int n, m, T;
char s[N][N];

int dis[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in(int r, int c) {
	return 1 <= r && r <= n && 1 <= c && c <= m;
}

int main() {
	scanf ("%d%d%d", &n, &m, &T);
	rep(i, 1, n) {
		scanf ("%s", s[i] + 1);
		rep(j, 1, m) dis[i][j] = 1e9;
	}
	rep(i, 1, n)
		rep(j, 1, m) {
			bool ok = false;
			rep(g, 0, 3) {
				int ni = i + dx[g];
				int nj = j + dy[g];
				if (in(ni, nj) && s[i][j] == s[ni][nj]) 
					ok = true;
			}
			if (ok) {
				dis[i][j] = 0;
				q.push({i, j});
			}
		}
	while (ss(q)) {
		int r = q.front().fi;
		int c = q.front().se;
		q.pop();
		rep(g, 0, 3) {
			int nr = r + dx[g];
			int nc = c + dy[g];
			if (in(nr, nc) && dis[nr][nc] == 1e9) {
				dis[nr][nc] = dis[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}
	while (T--) {
		int a, b;
		ll c;
		scanf ("%d%d%lld", &a, &b, &c);
	//	cat(dis[a][b]);
		if (dis[a][b] == 1e9 || dis[a][b] >= c) {
			printf ("%c\n", s[a][b]);
		}
		else {
			int val = s[a][b] - '0';
			int par = (c % 2 - dis[a][b] % 2 + 10) % 2;
			printf ("%d\n", val ^ par);
		}
	}
	
	
	
	return 0;
}