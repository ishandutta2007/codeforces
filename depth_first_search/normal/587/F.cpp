#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
using namespace std;
int n,Nt=1,sz,id[N+5],bg[N+5],l[N+5];LL v[N+5],ans[N+5];char s[N+5];
struct Q {int p,x,y;I Q(CI i=0,CI a=0,CI b=0):p(i),x(a),y(b){}};vector<Q> V[N+5],G[N+5];vector<Q>::iterator it;
namespace AC
{
	#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
	struct node {int F,S[30];}O[N+5];
	int d,dI[N+5],dO[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
	I void Init(CI x=1) {dI[x]=++d;for(RI i=lnk[x];i;i=e[i].nxt) Init(e[i].to);dO[x]=d;}
	struct TreeArray
	{
		int a[N+5];I void U(RI x,CI v) {W(x<=Nt) a[x]+=v,x+=x&-x;}
		I int Q(RI x,RI t=0) {W(x) t+=a[x],x-=x&-x;return t;}
	}A;
	I int Ins(char* s,CI l)
	{
		RI x=1;for(RI i=1,t;i<=l;++i) !O[x].S[t=s[i]&31]&&(O[x].S[t]=++Nt),x=O[x].S[t];return x;
	}
	int q[N+5];I void Build()
	{
		RI i,k,H=1,T=0;for(i=1;i<=26;++i) (O[1].S[i]?O[q[++T]=O[1].S[i]].F:O[1].S[i])=1;
		W(H<=T) for(k=q[H++],i=1;i<=26;++i) (O[k].S[i]?O[q[++T]=O[k].S[i]].F:O[k].S[i])=O[O[k].F].S[i];
		for(i=2;i<=Nt;++i) add(O[i].F,i);Init();
	}
	I void P(char* s,CI l,CI v) {for(RI i=1,x=1;i<=l;++i) x=O[x].S[s[i]&31],A.U(dI[x],v);}
	I int G(CI x) {return A.Q(dO[x])-A.Q(dI[x]-1);}
	I void U(CI x) {A.U(dI[x],1),A.U(dO[x]+1,-1);}
	I LL Q(char* s,CI l) {LL t=0;for(RI i=1,x=1;i<=l;++i) x=O[x].S[s[i]&31],t+=A.Q(dI[x]);return t;}
}
int main()
{
	RI Qt,i,j;for(scanf("%d%d",&n,&Qt),i=1;i<=n;++i)
		bg[i]=bg[i-1]+l[i-1],scanf("%s",s+bg[i]+1),id[i]=AC::Ins(s+bg[i],l[i]=strlen(s+bg[i]+1));
	RI x,y,k;for(sz=sqrt(n),i=1;i<=Qt;++i) scanf("%d%d%d",&x,&y,&k),
		l[k]<=sz?(V[x-1].push_back(Q(i,k,-1)),V[y].push_back(Q(i,k,1))):G[k].push_back(Q(i,x,y));
	for(AC::Build(),i=1;i<=n;++i) if(!G[i].empty())
	{
		for(AC::P(s+bg[i],l[i],1),j=1;j<=n;++j) v[j]=v[j-1]+AC::G(id[j]);
		for(it=G[i].begin();it!=G[i].end();++it) ans[it->p]=v[it->y]-v[it->x-1];AC::P(s+bg[i],l[i],-1);
	}
	for(i=1;i<=n;++i)
	{
		for(AC::U(id[i]),it=V[i].begin();it!=V[i].end();++it) ans[it->p]+=it->y*AC::Q(s+bg[it->x],l[it->x]);
	}
	for(i=1;i<=Qt;++i) printf("%lld\n",ans[i]);return 0;
}