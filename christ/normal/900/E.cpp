#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+3, LOG = 18, MOD = 1e9+7;
int cnt[MN][2][2], unk[MN];
int have[MN], dp[MN][2];
char s[MN];
int main() {
	int n,m;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	scanf ("%d",&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) cnt[i][j][k] = cnt[i-1][j][k];
		unk[i] = unk[i-1];
		if (s[i] != '?') cnt[i][s[i]-'a'][i&1]++;
		else ++unk[i];
	}
	int mx = 0;
	for (int i = 1; i <= n-m+1; i++) {
		if (cnt[i+m-1][0][i&1^1]==cnt[i-1][0][i&1^1] && cnt[i+m-1][1][i&1]==cnt[i-1][1][i&1]) {
			have[i] = ++mx;
			i += m-1;
		}
	}
	//dp[i] = least # of stuff to end @ i+m-1 kinda
	for (int i = 1; i <= n-m+1; i++) {
		if (have[i]) {
			dp[i][0] = min(dp[i-1][1],(i>=m?dp[i-m][0]:0)+unk[i+m-1]-unk[i-1]);
			dp[i][1] = (i>=m?dp[i-m][1]:0) + unk[i+m-1] - unk[i-1]; 
		} else {
			dp[i][0] = dp[i-1][0]; dp[i][1] = dp[i-1][1];
			if (cnt[i+m-1][0][i&1^1]==cnt[i-1][0][i&1^1] && cnt[i+m-1][1][i&1]==cnt[i-1][1][i&1]) {
				dp[i][0] = min(dp[i][0],(i>=m?dp[i-m][0]:0)+unk[i+m-1]-unk[i-1]);
				dp[i][1] = min(dp[i][1],(i>=m?dp[i-m][1]:0)+unk[i+m-1]-unk[i-1]);
			}
		}
	}
	printf ("%d\n",dp[n-m+1][1]);
    return 0;
}