//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=204;
int n,d,ans,mod,c[N][N],f[N][N],sum[N];
signed main(){
	n=read();d=read();mod=read(); 
	for(int i=0;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	f[1][0]=sum[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=min(i,d);j++){
			for(int k=1;k<i;k++){
				f[i][j]=(f[i-k][j-1]*sum[k]%mod*c[i-2][k-1]%mod+f[i][j])%mod;
			}
			if(j!=d)sum[i]=(f[i][j]+sum[i])%mod;//
		}
	}
	for(int i=1;i<=n;i++){
		for(int u=0;u<=d;u++){
			for(int v=0;u+v<=d;v++)if(v!=1){//
				ans=(f[i][u]*f[n-i+1][v]+ans)%mod;
			}
		}
	}
	cout<<ans*n%mod*(n-1)%mod*2%mod;
	return (0-0);
}