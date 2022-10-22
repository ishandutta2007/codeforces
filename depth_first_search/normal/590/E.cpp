#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 750
#define SZ 10000000
using namespace std;
int n,m,bg[N+5],l[N+5],f[N+5][N+5];char s[SZ+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	I void reads(int& l,char* s) {l=0;W(isspace(oc=tc()));W(s[++l]=oc,!isspace(oc=tc())&&~oc);}
}using namespace FastIO;
namespace AC
{
	int Nt=1;struct node {int P,F,S[2];}O[SZ+5];
	I void Ins(CI id,CI l,char* s)
	{
		RI x=1;for(RI i=1,t;i<=l;++i) !O[x].S[t=s[i]&1]&&(O[x].S[t]=++Nt),x=O[x].S[t];O[x].P=id;
	}
	int q[SZ+5];I void Build()
	{
		RI i,k,H=1,T=0;for(i=0;i<=1;++i) (O[1].S[i]?O[q[++T]=O[1].S[i]].F:O[1].S[i])=1;
		W(H<=T) for(k=q[H++],i=0;i<=1;++i) (O[k].S[i]?O[q[++T]=O[k].S[i]].F:O[k].S[i])=O[O[k].F].S[i];
		for(i=1;i<=Nt;++i) k=q[i],!O[k].P&&(O[k].P=O[O[k].F].P);
	}
	I void Work(CI id,CI l,char* s)
	{
		for(RI i=1,x=1,t;i<=l;++i) x=O[x].S[s[i]&1],(t=i^l?O[x].P:O[O[x].F].P)&&(f[t][id]=1);
	}
}
namespace H
{
	int p[N+5],s[N+5],vis[N+5];I bool Match(CI x,CI ti)
	{
		for(RI i=1;i<=n;++i) if(f[x][i]&&
			!p[i]&&vis[i]^ti&&(vis[i]=ti,!s[i]||Match(s[i],ti))) return s[i]=x;
		return 0;
	}
	I int Calc()
	{
		RI i,t=0;for(i=1;i<=n;++i) s[i]=vis[i]=0;for(i=1;i<=n;++i) !p[i]&&(t+=!Match(i,i));return t;
	}
}
int main()
{
	RI i,j,k;for(read(n),i=1;i<=n;++i) bg[i]=bg[i-1]+l[i-1],reads(l[i],s+bg[i]),AC::Ins(i,l[i],s+bg[i]);
	for(AC::Build(),i=1;i<=n;++i) AC::Work(i,l[i],s+bg[i]);
	for(k=1;k<=n;++k) for(i=1;i<=n;++i) for(j=1;j<=n;++j) f[i][j]|=f[i][k]&f[k][j];
	RI t=k=H::Calc();for(printf("%d\n",k),i=1;i<=n;++i) if(!H::p[i])
	{
		for(j=1;j<=n;++j) H::p[j]+=i==j||f[j][i]||f[i][j];if(H::Calc()==t-1) {printf("%d ",i),--t;continue;}
		for(j=1;j<=n;++j) H::p[j]-=i==j||f[j][i]||f[i][j];
	}return 0;
}