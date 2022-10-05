#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a),_E=(b); i<=_E; i++)
#define per(i,a,b) for (int i=(a),_E=(b); i>=_E; i--)
#define REP(i,a,b) for (int i=0,_E=(n); i<_E; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int maxn = 2005;
char s[maxn][maxn], ans[2*maxn], mn;
int f[maxn][maxn], n, K, flag, x, y, j, las;

int main() {
	scanf("%d%d", &n, &K);
	rep (i, 1, n) scanf("%s", s[i] + 1);
	memset(f, -1, sizeof f);
	if (K && s[1][1] != 'a') f[1][1] = 1, ans[2] = 'a';
	else ans[2] = s[1][1], f[1][1] = 0;
	
	rep (t, 3, 2 * n) {
		mn = 'z' + 1; flag = 0;
		rep (i, 1, min(n, t - 1)) if ((j = t - i) <= n) {
			//printf("%d %d   %c\n", i, j, s[i][j]);
			if (~f[i-1][j]) {
				if (f[i-1][j] < K) flag = 1;
				mn = min(mn, s[i][j]); 
			}
			if (~f[i][j-1]) {
				if (f[i][j-1] < K) flag = 1;
				mn = min(mn, s[i][j]);
			}
		}
		if (flag) ans[t] = 'a';
		else ans[t] = mn;
		rep (i, 1, min(n, t - 1)) if ((j = t - i) <= n) {
			las = -1;
			if (~f[i-1][j]) las = f[i-1][j];
			if (~f[i][j-1]) las = (las != -1 ? min(las, f[i][j-1]) : f[i][j-1]);
			if (las == -1) continue;
			if (s[i][j] == ans[t]) f[i][j] = las;
			else if (las < K) f[i][j] = las + 1;
		}
	}
	
	puts(ans + 2);
	return 0;
}