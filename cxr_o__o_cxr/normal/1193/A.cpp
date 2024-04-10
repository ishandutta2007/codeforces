#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int mod=998244353,inv2=mod+1>>1,N=1e6+4;
int n,m,u[400],v[400],f[N],bit[N],cant[N]; 
int main(){
	n=read();m=read();
	if(!m){puts("0");return (0-0);}
	for(int i=1;i<=m;i++){u[i]=read();v[i]=read();}
	f[0]=1;bit[0]=mod-1;
	for(int i=1,S=1<<n;i<S;i++)bit[i]=mod-bit[i&(i-1)];
	for(int i=1,S=1<<n;i<S;i++)
		for(int j=1;j<=m;j++)
			if(((i>>u[j]-1)&1)&&((i>>v[j]-1)&1)){cant[i]=1;break;}
	for(int s=1,S=1<<n;s<S;s++)
		for(int sta=s;sta;sta=s&(sta-1))if(!cant[sta])
			f[s]=((ll)f[sta^s]*bit[sta]+f[s])%mod;
	cout<<(ll)f[(1<<n)-1]*m%mod*inv2%mod;
	return (0-0);
}