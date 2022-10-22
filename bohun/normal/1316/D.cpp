#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;	

const int nax = 1100;

int n;
int row[nax][nax], col[nax][nax];
int done[nax][nax];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s = "LRUD";

char ans[nax][nax];

bool in(int r, int c) {
	return 1 <= r && r <= n && 1 <= c && c <= n;
}

void dfs(int r, int c, int g) {
	done[r][c] = 1;
	if (g >= 0) ans[r][c] = s[g];
	rep(k, 0, 3) {
		int nr = r + dx[k];
		int nc = c + dy[k];
		if (in(nr, nc) && !done[nr][nc] && row[r][c] == row[nr][nc] && col[r][c] == col[nr][nc])
			dfs(nr, nc, k);
	}
}

queue <pair<int, int>> q;

void wa() {
	printf ("INVALID");
	exit(0);
}

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) rep(j, 1, n) {
		scanf ("%d%d", &row[i][j], &col[i][j]);
		if (row[i][j] != -1)
			q.push({row[i][j], col[i][j]});
	}
	
	while (ss(q)) {
		int r = q.front().fi;
		int c = q.front().se;
		q.pop();
		if (row[r][c] != r) wa();
		if (col[r][c] != c) wa();
		if (done[r][c]) continue;
		ans[r][c] = 'X';
		dfs(r, c, -1);
	}
	
	rep(i, 1, n) rep(j, 1, n) {
		if (row[i][j] != -1) {
			if (!done[i][j]) wa();
		}
		else {
			bool ok = 0;
			rep(k, 0, 3) {
				int nr = i + dx[k];
				int nc = j + dy[k];
				if (!in(nr, nc) || row[nr][nc] != -1) continue;
				ok = 1;
				done[i][j] = 1;
				if (done[nr][nc]) {
					ans[i][j] = s[k ^ 1];
				}
				else {
					done[nr][nc] = 1;
					ans[i][j] = s[k ^ 1];
					ans[nr][nc] = s[k];
				}
				break;
			}
			if (!ok) wa();
		}
	}
	
	printf ("VALID\n");
	
	rep(i, 1, n) {
		rep(j, 1, n) printf ("%c", ans[i][j]);
		printf ("\n");
	}
		
	
	
	return 0;
}