#include <bits/stdc++.h>
using namespace std;
const char en='\n';
long long dp[3][210][210];
int main() {
	long long t, n;
long long x, y;
string a, b;
cin>>t;
while (t--) {
cin>>n>>x>>y;
n-=x+y;
memset(dp, 0, sizeof(dp));
dp[0][1][1]=n;
dp[1][1][1]=n+1;
x+=1;
y+=1;
for (int s=0;s<2;++s) for (int i=1;i<=x;++i) for (int j=1;j<=y;++j) if (i+j>2) dp[s][i][j]=(dp[s][i][j-1]+1)/2+dp[s][i-1][j]/2;
if (dp[0][x][y]==dp[1][x][y]) cout<<"NO\n";
else cout<<"YES\n";
} 
	return 0;
}