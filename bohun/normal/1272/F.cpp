#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define DOW(i, n) for(int i = n - 1; 0 <= i; --i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 211;
const int inf = 11111111;

int dp[nax][nax][nax];
int co[nax][nax][nax];
pair<int,int> opt[nax][nax][nax];
int bb[nax][nax][nax];

char s[nax];
char t[nax]; 

int n, m;

int main() {
	for (int i = 0; i < nax; ++i)
		for (int j = 0; j < nax; ++j)
			for (int k = 0; k < nax; ++k)
				dp[i][j][k] = inf;
	dp[0][0][0] = 0;
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	s[n + 1] = '#';
	t[m + 1] = '#';
	
	for (int i = 0; i <= n; ++i) 
		for (int j = 0; j <= m; ++j) {
			 for (int bil = nax - 1; 0 <= bil; --bil) {
				 if(dp[i][j][bil] == inf) continue;
				 int a = i + (s[i + 1] == '(');
				 int b = j + (t[j + 1] == '(');
				 if (dp[i][j][bil] + 1 < dp[a][b][bil + 1]) {
					 dp[a][b][bil + 1] = dp[i][j][bil] + 1;
					 co[a][b][bil + 1] = 1;
					 opt[a][b][bil + 1] = {i, j};
					 bb[a][b][bil + 1] = bil;
				}
				if(bil == 0) continue;
				a = i + (s[i + 1] == ')');
				b = j + (t[j + 1] == ')');
				if (dp[i][j][bil] + 1 < dp[a][b][bil - 1]) {
					dp[a][b][bil - 1] = dp[i][j][bil] + 1;
					co[a][b][bil - 1] = 0;
					opt[a][b][bil - 1] = {i, j};
					bb[a][b][bil - 1] = bil;
				}
			}
			for (int bil = 0; bil < nax; ++bil) {
				 if(dp[i][j][bil] == inf) continue;
				 int a = i + (s[i + 1] == '(');
				 int b = j + (t[j + 1] == '(');
				 if (dp[i][j][bil] + 1 < dp[a][b][bil + 1]) {
					 dp[a][b][bil + 1] = dp[i][j][bil] + 1;
					 co[a][b][bil + 1] = 1;
					 opt[a][b][bil + 1] = {i, j};
					 bb[a][b][bil + 1] = bil;
				}
				if(bil == 0) continue;
				a = i + (s[i + 1] == ')');
				b = j + (t[j + 1] == ')');
				if (dp[i][j][bil] + 1 < dp[a][b][bil - 1]) {
					dp[a][b][bil - 1] = dp[i][j][bil] + 1;
					co[a][b][bil - 1] = 0;
					opt[a][b][bil - 1] = {i, j};
					bb[a][b][bil - 1] = bil;
				}
			}
		}
	int x = n;
	int y = m;
	int z = 0;
	vector <int> v;
//	cat(dp[0][0][1]);
//	cat(dp[n][m][0]);
	for (int i = 1; i <= dp[n][m][0]; ++i) {
		v.pb(co[x][y][z]);
		pair<int, int> q = opt[x][y][z];
		z = bb[x][y][z];
		x = q.fi;
		y = q.se;
	}
	reverse(v.begin(), v.end());
	for (auto it : v) {
		if (it == 0) printf(")");
		else printf("(");
	}
	
	
		
	
	return 0;
}