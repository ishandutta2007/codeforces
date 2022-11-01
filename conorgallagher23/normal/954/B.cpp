#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=105;
int n,dp[N][2];char str[N];bool can[N];
void rel(int &x,int y){x=x<y?x:y;}
int main(){
	scanf("%d",&n);scanf("%s",str+1);
	for(int i=1;i<=n;i++)if(!(i&1)){
		bool fl=true;
		for(int j=1;j<=(i>>1);j++)if(str[j]!=str[(i>>1)+j]){
			fl=false;break;
		}
		if(fl)can[i]=true;
	}
	memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	for(int i=1;i<=n;i++){
		if(can[i])rel(dp[i][1],dp[i>>1][0]+1);
		rel(dp[i][0],dp[i-1][0]+1);rel(dp[i][1],dp[i-1][1]+1);
	}
	printf("%d\n",min(dp[n][0],dp[n][1]));
	return 0;
}