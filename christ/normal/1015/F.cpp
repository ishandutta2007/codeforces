#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 1e5+5, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1;
char s[205];
int dp[205][205][205]; //dp[# of brackets][prefix sum][prefix of s rn]
int precalc[205]; //if i mess up s here, what prefix do i now have?
void uadd (int &a, int b) {a += b; if (a >= MOD) a -= MOD;}
int main () {
	int n;
	scanf ("%d\n%s",&n,s+1); n<<=1;
	int m = strlen(s+1);
	for (int i = 1; i <= m; i++) {
		for (int j = i-1; j >= 1; j--) if (s[i] != s[j]) {
			for (int k = 1; k < j; k++) if (s[k] != s[i-j+k]) goto fail;
			precalc[i] = j; break;
			fail:;
		}
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < m; k++) {
				if (j) { //consider putting )
					if (s[k+1] == ')') uadd(dp[i+1][j-1][k+1],dp[i][j][k]);
					else uadd(dp[i+1][j-1][precalc[k+1]],dp[i][j][k]);
				}
				{ //consider putting (
					if (s[k+1] == '(') uadd(dp[i+1][j+1][k+1],dp[i][j][k]);
					else uadd(dp[i+1][j+1][precalc[k+1]],dp[i][j][k]);
				}
			}
			if (j) uadd(dp[i+1][j-1][m],dp[i][j][m]);
			uadd(dp[i+1][j+1][m],dp[i][j][m]);
		}
	}
	printf ("%d\n",dp[n][0][m]);
	return 0;
}