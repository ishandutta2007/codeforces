#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E6+8;

_ n, m, l, r = 1E9, md, s, dp[maxn][2];
char a[maxn], b[maxn];

bool check(_ md);
int main() {
	
	scanf("%s", b+1);
	m = strlen(b+1);
	if(b[1] == 'R' && b[m] == 'R') a[++n] = 'X';
	for(_ i = 1; i <= m; ++i) {
		if(a[n] == b[i] && b[i] != 'X') a[++n] = 'X';
		a[++n] = b[i];
	}
	if(b[1] == 'L' && b[m] == 'L') a[++n] = 'X';
	for(; l <= r; ) {
		md = (l+r)>>1;
		if(check(md)) {
			s = md;
			l = md+1;
		} else r = md-1;
	}
	printf("%lld.%06lld\n", s/10000000, s/10%1000000);
	
	return 0;
}

bool check(_ md) {
//	printf("md: %Lf\n", md);
	dp[0][0] = -md;
	dp[0][1] = 0;
	for(_ i = 1; i <= n; ++i) {
		dp[i][0] = dp[i-1][1]-md+(a[i] == 'L')*(_)1E9;
		dp[i][1] = dp[i-1][0]-md+(a[i] == 'R')*(_)1E9;
		dp[i][0] = max(dp[i][0], dp[i][1]-md);
		dp[i][1] = max(dp[i][1], dp[i][0]-md);
	}
	return dp[n][1] >= 0;
}