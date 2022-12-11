#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1100,M=100;
int tr[M][26],tot,fail[M],a[M],q[M],l,r,n,dp[N][M],ans;char c[N],b[M];
void cmax(int &x,int y){
	y>x?x=y:0;
}
void insert(char *c,int k){
	int x=0;
	for(int i=0;c[i];i++){
		if(!tr[x][c[i]-'a'])tr[x][c[i]-'a']=++tot;
		x=tr[x][c[i]-'a'];
	}
	a[x]=k;
}
void build(){
	l=1;r=0;
	for(int i=0;i<26;i++)if(tr[0][i])q[++r]=tr[0][i];
	for(;l<=r;l++){
		int x=q[l];
		for(int i=0;i<26;i++){
			int &y=tr[x][i],z=tr[fail[x]][i];
			if(!y)y=z;
			else fail[y]=z,a[y]+=a[z],q[++r]=y;
		}
	}
}
int main(){
	scanf("%s%s",c,b);insert(b,1);
	scanf("%s",b);insert(b,-1);
	build();
	n=strlen(c);
	memset(dp,0xcf,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=tot;j++){
			if(c[i]!='*')cmax(dp[i+1][tr[j][c[i]-'a']],dp[i][j]+a[tr[j][c[i]-'a']]);
			else for(int k=0;k<26;k++)cmax(dp[i+1][tr[j][k]],dp[i][j]+a[tr[j][k]]);
		}
	}
	ans=-1e9;
	for(int i=0;i<=tot;i++)ans=max(ans,dp[n][i]);
	printf("%d",ans);
	return 0;
}