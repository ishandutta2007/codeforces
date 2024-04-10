#include<bits/stdc++.h>
#define CI const int&
#define N 5000
#define X 998244353 
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
}using namespace FastIO;
int n,a[N+5],f[N+5][N+5],F[N+5],Fc[N+5],Ic[N+5],Iv[N+5];
int main()
{
	int i,j;for(read(n),i=1;i<=n;++i) read(a[i]);sort(a+1,a+n+1);
	for(Iv[1]=1,i=2;i<=n;++i) Iv[i]=1LL*(X-X/i)*Iv[X%i]%X;
	for(Fc[0]=Ic[0]=i=1;i<=n;++i) Fc[i]=1LL*Fc[i-1]*i%X,Ic[i]=1LL*Ic[i-1]*Iv[i]%X;
	int p;for(f[n][0]=1,i=p=n;i;--i)
	{
		while(2*a[p]>a[i]) --p;
		for(j=0;j<i-p-1;++j) F[j]=0;for(;j<=n;++j) F[j]=((j?F[j-1]:0)+1LL*f[i][j]*Fc[j]%X*Ic[j-(i-p-1)])%X;
		for(j=0;j<=n;++j) f[p][j]=(f[p][j]+F[j+i-p-1]+(j+i-p-1>i?0LL+X-F[j+i-p-1-i-1]:0))%X;
		for(j=1;j<=n;++j) f[i-1][j-1]=(f[i-1][j-1]+1LL*f[i][j]*j)%X;
	}
	return printf("%d\n",f[0][0]),0;
}