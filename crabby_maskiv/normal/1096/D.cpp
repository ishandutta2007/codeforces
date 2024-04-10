#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll dp[N][5];
char a[N];
ll c[N];
int main(){
    int i,j;
    cin>>n;
    cin>>(a+1);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(i=1;i<=n;i++) cin>>c[i];
    for(i=1;i<=n;i++){
    	if(a[i]=='h'){
    		dp[i][0]=dp[i-1][0]+c[i];
    		dp[i][1]=min(dp[i-1][1],dp[i-1][0]);
    		dp[i][2]=dp[i-1][2];
    		dp[i][3]=dp[i-1][3];
		}
    	else if(a[i]=='a'){
    		dp[i][1]=dp[i-1][1]+c[i];
    		dp[i][2]=min(dp[i-1][2],dp[i-1][1]);
    		dp[i][0]=dp[i-1][0];
    		dp[i][3]=dp[i-1][3];
		}
		else if(a[i]=='r'){
    		dp[i][2]=dp[i-1][2]+c[i];
    		dp[i][3]=min(dp[i-1][3],dp[i-1][2]);
    		dp[i][0]=dp[i-1][0];
    		dp[i][1]=dp[i-1][1];
		}
		else if(a[i]=='d'){
			dp[i][3]=dp[i-1][3]+c[i];
			dp[i][0]=dp[i-1][0];
    		dp[i][1]=dp[i-1][1];
    		dp[i][2]=dp[i-1][2];
		}
    	else{
    		for(j=0;j<4;j++)
    			dp[i][j]=dp[i-1][j];
		}
	}
	cout<<min(min(dp[n][1],dp[n][2]),min(dp[n][3],dp[n][0]));
    return 0;
}