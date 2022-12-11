#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,m,a[200020],w[200020];
int SA,SB,F[3030][3030],G[3030][3030];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]),a[i]?SA+=w[i]:SB+=w[i];
	for(int i=0;i<=m;++i)F[i][m-i]=1,G[i][m-i]=1;
	for(int k=m-1;k>=0;--k)
		for(int i=0,j=k;i<=k;++i,--j)
		{
			int inv=kpow(SA+i+SB-j,mod-2);
			F[i][j]=(1ll*(SA+i+1)*inv%mod*F[i+1][j]+1ll*(SB-j)*inv%mod*F[i][j+1])%mod; 
			G[i][j]=(1ll*(SB-j-1)*inv%mod*G[i][j+1]+1ll*(SA+i)*inv%mod*G[i+1][j])%mod;
		}
	for(int i=1;i<=n;++i)
		if(a[i])printf("%d\n",1ll*F[0][0]*w[i]%mod);
		else printf("%d\n",1ll*G[0][0]*w[i]%mod);
	return 0;
}