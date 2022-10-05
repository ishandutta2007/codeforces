#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define _rep(i,a,b) for (int i=(a); i>=int(b); i--)
using namespace std;
typedef long double LD;

const int maxn = 1009;
int cntL[maxn][maxn], cntR[maxn][maxn], p[maxn], q[maxn];
LD sumL[maxn][maxn], sumR[maxn][maxn];
char s[maxn][maxn];
int n, m, last, sum, sum2; LD tot;

int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, n) scanf("%s", s[i]+1);
	
	rep (i, 1, n) {
		rep (j, 1, m) {
			cntL[i][j] = cntL[i-1][j] + cntL[i][j-1] - cntL[i-1][j-1] + (s[i][j] == '.');
			sumL[i][j] = sumL[i-1][j] + sumL[i][j-1] - sumL[i-1][j-1] + (s[i][j] == '.') * (i + j);
			if (s[i][j] == '.') tot += (LD) cntL[i][j-1] * (i + j) - sumL[i][j-1];
		}
		_rep (j, m, 1) {
			cntR[i][j] = cntR[i-1][j] + cntR[i][j+1] - cntR[i-1][j+1] + (s[i][j] == '.');
			sumR[i][j] = sumR[i-1][j] + sumR[i][j+1] - sumR[i-1][j+1] + (s[i][j] == '.') * (i + m + 1 - j);
			if (s[i][j] == '.') tot += (LD) cntR[i-1][j] * (i + m + 1 - j) - sumR[i-1][j];
		}
	}
	tot *= 2;

	rep (i, 1, n) rep (j, 1, m) 
		if (s[i][j] == 'X') p[i] = j; 
	rep (i, 1, m) rep (j, 1, n) 
		if (s[j][i] == 'X') q[i] = j;
	
	last = 0;
	rep (i, 1, n) if (p[i]) {
		if (!last || p[i] < p[i-1]) {
			last = i; sum = 0;
		}
		sum += p[i] - 1;
		tot += (LD) 4.0 * (m - p[i]) * sum;
	}
	else last = 0;
	
	last = 0;
	rep (i, 1, n) if (p[i]) {
		if (!last || p[i] > p[i-1]) {
			last = i; sum = 0;
		}
		tot += (LD) 4.0 * (p[i] - 1) * sum;
		sum += m - p[i];
	}
	else last = 0;
	
	last = 0;
	rep (i, 1, m) if (q[i]) {
		if (!last || q[i] < q[i-1]) {
			last = i; sum = 0;
		}
		sum += q[i] - 1; 
		tot += (LD) 4.0 * (n - q[i]) * sum;
	}
	else last = 0;
	
	last = 0;
	rep (i, 1, m) if (q[i]) {
		if (!last || q[i] > q[i-1]) {
			last = i; sum = 0;
		}
		tot += (LD) 4.0 * (q[i] - 1) * sum;
		sum += n - q[i];
	}
	else last = 0;
	
	LD ans = tot / cntL[n][m] / cntL[n][m];
	printf("%.12Lf\n", ans);
	
	return 0;
}