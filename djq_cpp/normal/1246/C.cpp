#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, m;
char ch[2005][2005];
int pl[2005][2005], pu[2005][2005];
int dpr[2005][2005], dpd[2005][2005];
int rsum[2005][2005], dsum[2005][2005];

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", ch[i]);
	
	dpd[0][0] = 1;
	
	rep(i, n) {
		int cr = 0;
		for(int j = m - 1; j >= 0; j --) if(ch[i][j] == 'R') {
			cr ++;
			pl[i][m - cr] = j;
		}
	}
	rep(i, m) {
		int cr = 0;
		for(int j = n - 1; j >= 0; j --) if(ch[j][i] == 'R') {
			cr ++;
			pu[n - cr][i] = j;
		}
	}
	
	rsum[0][0] = dsum[0][0] = 1;
	rep(i, n) rep(j, m) {
		if(i == 0 && j == 0) continue;
		if(i > 0) {
			if(pu[i][j] > 0) dpd[i][j] = (dsum[i - 1][j] - dsum[pu[i][j] - 1][j] + MOD) % MOD;
			else dpd[i][j] = dsum[i - 1][j];
		}
		if(j > 0) {
			if(pl[i][j] > 0) dpr[i][j] = (rsum[i][j - 1] - rsum[i][pl[i][j] - 1] + MOD) % MOD;
			else dpr[i][j] = rsum[i][j - 1];
		}
		dsum[i][j] = i == 0 ? dpr[i][j] : (dsum[i - 1][j] + dpr[i][j]) % MOD;
		rsum[i][j] = j == 0 ? dpd[i][j] : (rsum[i][j - 1] + dpd[i][j]) % MOD;
	}

	printf("%d\n", (dpd[n - 1][m - 1] + dpr[n - 1][m - 1]) % MOD);
	return 0;
}