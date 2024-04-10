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
#define cint const int&
 
using namespace std;	

const int mod = 1e9 + 7;
const int nax = 1111;

int T;
int n, m;
char s[nax][nax];

bool used[nax][nax];
bool row[nax];
bool col[nax];

bool fr[nax];
bool fc[nax];

int ans;

bool in(int r, int c){
	return 1 <= r && r <= n && 1 <= c && c <= m;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int r, int c) {
	used[r][c] = true;
	row[r] = true;
	col[c] = true;
	rep(i, 0, 3) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (in(nr, nc) && !used[nr][nc] && s[nr][nc] == '#')	
			dfs(nr, nc);
	}
}
	

int main() {	
	T = 1;
	while (T--) {
		scanf ("%d%d", &n, &m);
		rep(i, 1, n) scanf ("%s", s[i]+1);
		rep(i, 1, n) {
			rep(j, 1, m)
				used[i][j] = false;
		}
		bool bad = false;
		rep(i, 1, n) {
			bool black = false;
			rep(j, 1, m) {
				if (j > 1) {
					if (black == true && s[i][j-1] != '#' && s[i][j] == '#')
						bad = true;
				}
				black |= s[i][j] == '#';
			}
		}
		
		rep(j, 1, m) {
			bool black = false;
			rep(i, 1, n) {
				if (i > 1) {
					if (black == true && s[i-1][j] != '#' && s[i][j] == '#')
						bad = true;
				}
				black |= s[i][j] == '#';
			}
		}
		
		if (bad == true) {
			printf ("-1\n");
			continue;
		}
		
		ans = 0;
		rep(i, 1, n)
			rep(j, 1, m) {
				if (used[i][j] == false && s[i][j] == '#') {
					ans++;
					dfs(i, j);
				}
			}
		
		rep(i, 1, n) fr[i] = row[i];
		rep(i, 1, m) fc[i] = col[i];
		rep(i, 1, n)
			rep(j, 1, m)
				if (row[i] == false && col[j] == false) {
					fr[i] = true;
					fc[j] = true;
				}
		rep(i, 1, n) if (fr[i] == false) {
			printf ("-1\n");
			return 0;
		}	
		rep(i, 1, m) {
			if (fc[i] == false) {
				printf ("-1\n");
				return 0;
			}
		}
		
		printf ("%d\n", ans);
		
		
	}
			
	
	return 0;
}