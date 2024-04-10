#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100000
#define M 200000
#define LG 59
#define X 1000000007
#define LL long long
#define add(x,y,z) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].v=z)
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
int n,m,ans,ee,lnk[N+5];struct edge {int to,nxt;LL v;}e[2*M+5];
struct LinearBasis
{
	int c;LL v[LG+1];void Cl() {c=0;for(int i=0;i<=LG;++i) v[i]=0;}
	void Ins(LL x) {for(int i=LG;~i;--i) if(x>>i&1) {if(!v[i]) return (void)(v[i]=x,++c);x^=v[i];}}
}B;
int c,vis[N+5];LL q[N+5],v[N+5];void dfs(int x)
{
	vis[x]=1,q[++c]=v[x];
	for(int i=lnk[x],y;i;i=e[i].nxt) vis[y=e[i].to]?B.Ins(v[x]^v[y]^e[i].v):(v[y]=v[x]^e[i].v,dfs(y));
}
void Calc()
{
	int i,j,o,tg,ct[2];for(j=0;j<=LG;++j)
	{
		for(ct[0]=ct[1]=0,i=1;i<=c;++i) ++ct[q[i]>>j&1];for(tg=i=0;i<=LG;++i) B.v[i]&&B.v[i]>>j&1&&(tg=1);
		o=1LL*ct[0]*ct[1]%X*((1LL<<B.c-tg)%X)%X,tg&&(o=(o+(1LL*ct[0]*(ct[0]-1)/2+1LL*ct[1]*(ct[1]-1)/2)%X*((1LL<<B.c-1)%X))%X);
		ans=(ans+o*((1LL<<j)%X))%X;
	}
}
int main()
{
	int i,x,y;LL z;for(read(n,m),i=1;i<=m;++i) read(x,y,z),add(x,y,z),add(y,x,z);
	for(i=1;i<=n;++i) !vis[i]&&(B.Cl(),c=0,dfs(i),Calc(),0);return printf("%d\n",ans),0;
}