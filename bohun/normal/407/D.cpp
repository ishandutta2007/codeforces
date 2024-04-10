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
#define all(x) x.begin(), x.end()

using namespace std;
	
const int N = 410;
const int M = N * N;

int n, m;
int t[N][N];	
int ans;
int x[N][N];
int x2[N][N];
int y[M];
int y3[M];
int r[N];

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) {
		scanf ("%d", &t[i][j]);
		x2[i][j] = m + 1;
	}
	rep(i, 0, M - 1) y3[i] = m + 1;
	
	per(i, 1, n) {
		rep(j, 1, m) r[j] = m;
		
		rep(j, 1, m) {
			x[i][j] = y[t[i][j]];
			y[t[i][j]] = j;
			rep(r, i + 1, n) x[r][j] = max(x[r][j], y[t[r][j]]);
		}
		rep(j, 1, m) y[t[i][j]] = 0;
		
		per(j, 1, m) {
			x2[i][j] = y3[t[i][j]];
			y3[t[i][j]] = j;
			rep(r, i + 1, n) x2[r][j] = min(x2[r][j], y3[t[r][j]]);
		}
		
		rep(j, 1, m) y3[t[i][j]] = m + 1;
		
		rep(d, i, n) {
			rep(j, 1, m) r[x[d][j]] = min(r[x[d][j]], j - 1);
			rep(j, 1, m) r[j] = min(r[j], x2[d][j] - 1);
			per(j, 1, m - 1) r[j] = min(r[j], r[j + 1]);
			rep(j, 1, m) ans = max(ans, (d - i + 1) * (r[j] - j + 1));
		} 
		
		
	}
	printf ("%d\n", ans);
			
		
	return 0;
}