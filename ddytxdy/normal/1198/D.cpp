    #include<bits/stdc++.h>
    using namespace std;
    const int N=60;
    int n,dp[N][N][N][N];char c[N][N];
    int solve(int x1,int y1,int x2,int y2){
    	if(~dp[x1][y1][x2][y2])return dp[x1][y1][x2][y2];
    	if(x1==x2&&y1==y2)return dp[x1][y1][x2][y2]=c[x1][y1]=='#';
    	int ret=max(x2-x1+1,y2-y1+1);
    	for(int i=x1;i<x2;i++)ret=min(ret,solve(x1,y1,i,y2)+solve(i+1,y1,x2,y2));
    	for(int i=y1;i<y2;i++)ret=min(ret,solve(x1,y1,x2,i)+solve(x1,i+1,x2,y2));
    	return dp[x1][y1][x2][y2]=ret;
    }
    int main(){
    	memset(dp,-1,sizeof(dp));
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
    	printf("%d\n",solve(1,1,n,n));
    	return 0;
    }