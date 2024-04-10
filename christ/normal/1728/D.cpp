#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3+5;
char s[MN];
int dp[MN][MN]; //0 loss, 1 draw, 2 win
string ret[3] = {"Bob", "Draw", "Alice"};
int solve (int l, int r) {
	if (l + 1 == r) return s[l] == s[r] ? 1 : 2;
	if (dp[l][r] >= 0) return dp[l][r];
	int &ret = dp[l][r];
	auto getRes = [&] (int oRes, char ac, char bc) {
		if (oRes != 1) return oRes;
		return ac < bc ? 2 : (ac==bc?1:0); 
	};
	//consider taking L
	ret = max(ret,min(getRes(solve(l+2,r),s[l],s[l+1]), getRes(solve(l+1,r-1),s[l],s[r])));
	//consider taking R
	ret = max(ret,min(getRes(solve(l+1,r-1),s[r],s[l]),getRes(solve(l,r-2),s[r],s[r-1])));
	return ret;
	
}
void solve () {
	scanf ("%s",s+1);
	int n = strlen(s+1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	printf ("%s\n",ret[solve(1,n)].c_str());
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}