#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,K,f[1024][1024],x,y,t[10];
bool v[10][10];
void add(int &a,int b){
	a+=b;
	if(a>=M)a-=M;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<n;i++)
		for(int j=i-1;j>=0;j--)t[i]|=(1<<j);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);--x,--y;
		v[x][y]=v[y][x]=1;
		if(x==n-1||y==n-1)f[(1<<x)|(1<<y)][(1<<x)|(1<<y)]=1;
	}
	for(int i=1;i<(1<<n);i++)for(int j=i;j;j=(j-1)&i)if(f[i][j]){
		for(int k=0;k<n;k++)if(!((1<<k)&i))
			for(int l=0;l<n;l++)if((1<<l)&i)if(v[k][l])
				if(!((j&(((1<<n)-1)^(1<<l)))&t[k]))
					add(f[i|(1<<k)][(j|(1<<k))^(((1<<l)&j)==0?0:(1<<l))],f[i][j]);
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++)if(__builtin_popcount(i)==K)add(ans,f[(1<<n)-1][i]);
	printf("%d",ans);
}