#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=1010;
int n,m,g[N][N],la;char c[N][N];LL f[N][N],ans;
int check(int x,int y){
	int len=g[x][y];
	x-=len;
	if(g[x][y]!=len)return 0;
	x-=len;
	return len*(g[x][y]>=len);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(i==1||c[i][j]!=c[i-1][j])g[i][j]=1;
		else g[i][j]=g[i-1][j]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		int v=check(i,j);
		if(!v){la=0;continue;}
		f[i][j]=1;   
		if(la==v&&c[i][j]==c[i][j-1]&&c[i-v][j]==c[i-v][j-1]&&c[i-2*v][j]==c[i-2*v][j-1])f[i][j]+=f[i][j-1];
		ans+=f[i][j];la=v;
	}
	cout<<ans;
	return 0;
}