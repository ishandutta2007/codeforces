#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[101][101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    for(int i=0;i<=n;i++){
		dp[0][i]=1;
    }
    lli ans=0;
    for(int i=1;i<=n;i++){
        lli reps[26]={ };
        for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j-1]+dp[i][j-1]-reps[a[j-1]-'a'];
        	reps[a[j-1]-'a']+=(dp[i-1][j-1]-reps[a[j-1]-'a']);
        }
    }
    for(int i=n;i>=0;i--){
	    ans+=min(k,dp[i][n])*(n-i);
	    k-=min(k,dp[i][n]);
	    if(!k)break;
    }
    if(k)printf("-1\n");
    else printf("%lli\n",ans);
    return 0;
}