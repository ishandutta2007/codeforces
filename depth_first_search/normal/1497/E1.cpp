#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define K 20
#define V 10000000
using namespace std;
int n,k,a[N+5],s[K+5],f[N+5][K+5],lst[V+5];
int Pt,P[V+5];I void Sieve()
{
	RI i,j;for(i=2;i<=V;++i) for(!P[i]&&(P[++Pt]=i),j=1;j<=Pt&&i*P[j]<=V;++j) if(P[i*P[j]]=1,!(i%P[j])) break;
}
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
}using namespace FastIO;
int main()
{
	RI Tt,i,j,x,t;Sieve(),read(Tt);W(Tt--)
	{
		for(read(n),read(k),i=1;i<=n;lst[a[i++]*=x]=0)
			for(a[i]=1,read(x),j=1;1LL*P[j]*P[j]<=x;++j) {t=0;W(!(x%P[j])) x/=P[j],t^=1;t&&(a[i]*=P[j]);}
		for(t=0,i=1;i<=k+1;++i) s[i]=0;for(i=1;i<=n;++i)
		{
			for(j=1;j<=k+1&&s[j]>lst[a[i]];++j);if(j<=k+1) {for(x=k+1;x^j;--x) s[x]=s[x-1];s[j]=lst[a[i]];}lst[a[i]]=i;
			for(j=0;j<=k;++j) for(f[i][j]=1e9,x=0;x<=j;++x) f[i][j]=min(f[i][j],f[s[x+1]][j-x]+1);
		}
		for(t=1e9,i=0;i<=k;++i) t=min(t,f[n][i]);printf("%d\n",t);
	}return 0;
}