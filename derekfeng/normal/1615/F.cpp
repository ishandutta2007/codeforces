#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2001,M=1e9+7;
int T,n;
char s[2002],t[2002];
int a[2002],b[2002];
int f[2002][4004],g[2002][4004];
int *F[2002],*G[2002];
void sol(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='0')a[i]=0;
		if(s[i]=='1')a[i]=1;
		if(s[i]=='?')a[i]=2;
		if(t[i]=='0')b[i]=0;
		if(t[i]=='1')b[i]=1;
		if(t[i]=='?')b[i]=2;
		if(i&1){
			if(a[i]<2)a[i]^=1;
			if(b[i]<2)b[i]^=1;
		}
	}
	for(int i=0;i<=n;i++){
		memset(f[i],0,sizeof(f[i]));
		memset(g[i],0,sizeof(g[i]));
		F[i]=f[i]+N;
		G[i]=g[i]+N;
	}
	F[0][0]=1,G[0][0]=0;
	for(int i=1;i<=n;i++)for(int j=-i;j<=i;j++)if(F[i-1][j])
		for(int p=0;p<2;p++)if(a[i]!=(p^1))for(int q=0;q<2;q++)if(b[i]!=(q^1)){
			(F[i][j+p-q]+=F[i-1][j])%=M;
			(G[i][j+p-q]+=((ll)F[i-1][j]*abs(j)+G[i-1][j])%M)%=M;
		}
	printf("%d\n",G[n][0]);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}