//Code By CXY
#include<bits/stdc++.h>
using namespace std;
    
//#define int long long
    
const int MAXN = 510;
const int INF = 2e9;
const int mod = 1e9 + 7;
     
int n,ans;
int a[MAXN];
int dp1[MAXN][MAXN],dp2[MAXN]; 
     
signed main () {
  	scanf("%d",&n); ans = n;
   	for(register int i = 1;i <= n; ++i)
   		scanf("%d",&a[i]),dp1[i][i] = a[i];
   	for(register int l = 2;l <= n; ++l) {
   		for(register int i = 1,j;i + l - 1 <= n; ++i) {
   			j = i + l - 1;
   			for(register int p = i;p < j; ++p)
   				if(dp1[i][p] && dp1[i][p] == dp1[p + 1][j]) dp1[i][j] = dp1[i][p] + 1;	
   		}
   	}
   	for(register int i = 1;i <= n; ++i) {
   		dp2[i] = i;
   		for(register int j = 1;j <= i; ++j)
   			if(dp1[j][i]) dp2[i] = min(dp2[i],dp2[j - 1] + 1);
   	}
   	cout << dp2[n] << endl;
   	return 0;
}