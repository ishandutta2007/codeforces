//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int N=60,mod=1e9+7; 
int n,m,f[N][N],inv[N];
int main(){
	n=read();m=read();
	f[0][1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=mod-(ll)(mod/i)*inv[mod%i]%mod;
	for(int i=1,G;i<=n;i++){
		for(int j=1;j<=i+1;j++){
			G=0;
			for(int k=0;k<i;k++){
				for(int u=j;u<=k+1;u++)
					G=((ll)f[k][u]*f[i-1-k][j]+G)%mod;
				for(int u=j+1;u<=i-k;u++)
					G=((ll)f[k][j]*f[i-1-k][u]+G)%mod;
			}
			for(int u=n;u>=0;u--)
				for(int v=u+1;v;v--)
					for(int w=1,C=1;u+i*w<=n;w++){
						C=(ll)C*(G+w-1)%mod*inv[w]%mod;
						f[u+i*w][v+j*w]=((ll)f[u][v]*C+f[u+i*w][v+j*w])%mod;
					}
		}
	}
	cout<<f[n][m];
	return (0-0);
}