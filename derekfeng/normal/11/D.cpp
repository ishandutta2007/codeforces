#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int ok[20][20],lowbits[540000];
ll dp[540000][20],ans=0;
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int x,y;scanf("%d%d",&x,&y),x--,y--;
		ok[x][y]=ok[y][x]=1;
	}
	for (int i=1;i<(1<<n);i++)
		for (int j=0;j<n;j++) if ((1<<j)&i){
			lowbits[i]=j;
			break;
		}
	for (int i=0;i<n;i++)
		dp[1<<i][i]=1;
	for (int i=1;i<(1<<n);i++){
		for (int j=lowbits[i]+1;j<n;j++)if((1<<j)&i)
			for (int k=lowbits[i];k<n;k++)if(((1<<k)&i)>0 && k!=j && ok[k][j])
				dp[i][j]+=dp[i^(1<<j)][k];
		for (int j=0;j<n;j++)if((1<<j)&i && __builtin_popcount(i)>=3 && ok[j][lowbits[i]])
			ans+=dp[i][j];
	}
	cout<<ans/2;
}