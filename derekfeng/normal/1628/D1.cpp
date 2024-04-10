#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int M=1e9+7,i2=(M+1)/2;
int n,m,k;
int f[2005][2005];
db dp[2005][2005];
pair<int,double>sol(int x,int y){
	if(~f[x][y])return {f[x][y],dp[x][y]};
	if(n-(x-1)==y)return {f[x][y]=(ll)k*y%M,dp[x][y]=(ll)k*y};
	pair<int,double> a=sol(x+1,max(y-1,0)),b=sol(x+1,y);
	if(b.second<a.second)return {f[x][y]=b.first,dp[x][y]=b.second};
	return {f[x][y]=(ll)(a.first+b.first)*i2%M,dp[x][y]=(a.second+b.second)*0.5};
}
void sol(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)f[i][j]=-1;
	printf("%d\n",sol(1,m).first);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}