#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50,inf=1e9,M=260;
int n,q,nxt[26][N],x,len[4],dp[M][M][M],a[4][M];char c[N],d[3],e[3];
void update(int x){
	for(int i=x==1?len[1]:0;i<=len[1];i++){
		for(int j=x==2?len[2]:0;j<=len[2];j++){
			for(int k=x==3?len[3]:0;k<=len[3];k++){
				dp[i][j][k]=inf;
				if(i&&dp[i-1][j][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[a[1][i]][dp[i-1][j][k]+1]);
				if(j&&dp[i][j-1][k]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[a[2][j]][dp[i][j-1][k]+1]);
				if(k&&dp[i][j][k-1]!=inf)dp[i][j][k]=min(dp[i][j][k],nxt[a[3][k]][dp[i][j][k-1]+1]);
			}
		}
	}
}
int main(){
	scanf("%d%d%s",&n,&q,c+1);
	for(int i=0;i<26;i++){
		nxt[i][n+1]=inf;
		for(int j=n;j;j--){
			if(c[j]==i+'a')nxt[i][j]=j;
			else nxt[i][j]=nxt[i][j+1];
		}
	}
	while(q--){
		scanf("%s%d",d,&x);
		if(d[0]=='+'){
			scanf("%s",e);
			a[x][++len[x]]=e[0]-'a';
			update(x);
		}
		else len[x]--;
		if(dp[len[1]][len[2]][len[3]]!=inf)puts("YES");
		else puts("NO");
	}
	return 0;
}