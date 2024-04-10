#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000
#define D 50
#define X 1000000007
#define Inc(x,y) ((x+=(y))>=X&&(x-=X))
using namespace std;
int n,d;char s[N+5],l[D+5],r[D+5];
namespace AcAutomation
{
	int Nt=1;struct node {int P,F,S[30];}O[N*D+5];
	I void Ins(CI x,CI y)
	{
		RI t,k=1;for(RI i=x;i<=y;k=O[k].S[t],++i)
			!O[k].S[t=s[i]&15]&&(O[k].S[t]=++Nt);O[k].P=1;
	}
	int q[N*D+5];I void Build()
	{
		RI i,k,H=1,T=1;for(i=0;i<=9;++i)
			(O[1].S[i]?O[q[++T]=O[1].S[i]].F:O[1].S[i])=1;
		W(H<=T) for(k=q[H++],i=0;i<=9;++i)
			(O[k].S[i]?O[q[++T]=O[k].S[i]].F:O[k].S[i])=O[O[k].F].S[i];
	}
	int f[D+5][N*D+5][2];I int DP(char *w,CI x=1,CI rt=1,CI p=0,CI fg=0)
	{
		if(x>d) return p;if(fg&&~f[x][rt][p]) return f[x][rt][p];
		RI i,k,t=0,lim=fg?9:(w[x]&15);for(i=0;i<=lim;++i)
			k=O[rt].S[i],Inc(t,DP(w,x+1,k,p||O[k].P,fg||i^lim));
		return fg&&(f[x][rt][p]=t),t;
	}
}
int main()
{
	using namespace AcAutomation;memset(f,-1,sizeof(f));
	RI i;scanf("%s%s%s",s+1,l+1,r+1),n=strlen(s+1),d=strlen(l+1);
	for(i=1;i<=n-(d>>1)+1;++i) Ins(i,i+(d>>1)-1);Build();
	for(i=d;l[i]=='0';--i) l[i]='9';--l[i];return printf("%d\n",(DP(r)-DP(l)+X)%X),0;
}