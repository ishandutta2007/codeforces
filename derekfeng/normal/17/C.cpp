#include<bits/stdc++.h>
#define N 150
#define M 50
#define MOD 51123987
#define Inc(x,a) x=(x+(a))%MOD
using namespace std;
int n,m,dp[N][M+2][M+2][M+2],nxt[N+1][3];
char buffer[N+1];
int main(){
	scanf("%d%s",&n,buffer);
	m=(n+2)/3;
	nxt[n][0]=nxt[n][1]=nxt[n][2]=n;
	for(int i=n-1;i!=-1;--i)
		for(int j=0;j!=3;++j)
			nxt[i][j]=buffer[i]-'a'==j?i:nxt[i+1][j];
	int answer=0;
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0]=1;
	for(int i=0;i!=n;++i)
		for(int a=0;a<=m;++a)
			for(int b=0;b<=m;++b)
				for(int c=0;c<=m;++c){
					if(a+b+c==n&&abs(a-b)<=1&&abs(b-c)<=1&&abs(a-c)<=1)Inc(answer,dp[i][a][b][c]);
					if(nxt[i][0]!=n)Inc(dp[nxt[i][0]][a+1][b][c],dp[i][a][b][c]);
					if(nxt[i][1]!=n)Inc(dp[nxt[i][1]][a][b+1][c],dp[i][a][b][c]);
					if(nxt[i][2]!=n)Inc(dp[nxt[i][2]][a][b][c+1],dp[i][a][b][c]);
				}
	printf("%d\n",answer);
	return 0;
}