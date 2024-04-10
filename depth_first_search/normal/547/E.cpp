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
#define M 500000
using namespace std;
int n,bg[N+5],l[N+5],ans[M+5];char s[N+5];
struct Q {int p,k,op;I Q(CI i=0,CI x=0,CI f=0):p(i),k(x),op(f){}};vector<Q> q[N+5];vector<Q>::iterator it;
namespace T
{
	int d,dI[N+5],dO[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[N+5];
	I void Add(CI x,CI y) {e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y;}
	I void Init(CI x) {dI[x]=++d;for(RI i=lnk[x];i;i=e[i].nxt) Init(e[i].to);dO[x]=d;}
}
struct TreeArray
{
	int a[N+5];I void U(RI x) {W(x<=T::d) ++a[x],x+=x&-x;}I int Q(RI x,RI t=0) {W(x) t+=a[x],x-=x&-x;return t;}
}A;
namespace AC
{
	int Nt=1,p[N+5],q[N+5];struct node {int F,S[30];}O[N+5];
	I void Ins(CI id,char* s,CI l) {RI x=1;
		for(RI i=1,t;i<=l;++i) !O[x].S[t=s[i]&31]&&(O[x].S[t]=++Nt),x=O[x].S[t];p[id]=x;}
	I void Build()
	{
		RI i,k,H=1,T=0;for(i=1;i<=26;++i) (O[1].S[i]?O[q[++T]=O[1].S[i]].F:O[1].S[i])=1;
		W(H<=T) for(k=q[H++],i=1;i<=26;++i) (O[k].S[i]?O[q[++T]=O[k].S[i]].F:O[k].S[i])=O[O[k].F].S[i];
		for(i=2;i<=Nt;++i) T::Add(O[i].F,i);T::Init(1);
	}
	I void U(char* s,CI l) {for(RI i=1,x=1;i<=l;++i) x=O[x].S[s[i]&31],A.U(T::dI[x]);}
	I int Q(CI id) {return A.Q(T::dO[p[id]])-A.Q(T::dI[p[id]]-1);}
}
int main()
{
	RI Qt,i,x,y,z;scanf("%d%d",&n,&Qt);
	for(i=1;i<=n;++i) scanf("%s",s+(bg[i]=bg[i-1]+l[i-1])+1),AC::Ins(i,s+bg[i],l[i]=strlen(s+bg[i]+1));
	for(AC::Build(),i=1;i<=Qt;++i) scanf("%d%d%d",&x,&y,&z),q[x-1].push_back(Q(i,z,-1)),q[y].push_back(Q(i,z,1));
	for(i=1;i<=n;++i) for(AC::U(s+bg[i],l[i]),it=q[i].begin();it!=q[i].end();++it) ans[it->p]+=it->op*AC::Q(it->k);
	for(i=1;i<=Qt;++i) printf("%d\n",ans[i]);return 0;
}