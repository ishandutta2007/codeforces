#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define LN 18
using namespace std;
string st,s[N+5];int v[N+5],Lg[N+5];
int Nt,Et,Ep[N+5];struct node {int V,F,S[26];}O[N+5];
class ACAutomation
{
	private:
		#define New() (Et?Ep[Et--]:++Nt)
		#define D(x) (O[x].V=0,memset(O[x].S,0,sizeof(O[x].S)),Ep[++Et]=x)
		int rt,nt,pl[N+5];
		I void Ins(Cn string& s,CI v)
		{
			RI i,x=rt,t,l=s.length();for(i=0;i^l;++i) !O[x].S[t=s[i]-'a']&&(O[x].S[t]=pl[++nt]=New()),x=O[x].S[t];O[x].V+=v;
		}
		int q[N+5];I void Get()
		{
			RI i,k,H=1,T=0;for(i=0;i^26;++i) (O[rt].S[i]?O[q[++T]=O[rt].S[i]].F:O[rt].S[i])=rt;
			W(H<=T) for(k=q[H++],i=0;i^26;++i) (O[k].S[i]?O[q[++T]=O[k].S[i]].F:O[k].S[i])=O[O[k].F].S[i];
			for(i=1;i<=T;++i) O[q[i]].V+=O[O[q[i]].F].V;
		}
	public:
		I void Bd(CI l,CI r)
		{
			W(nt) D(pl[nt]),--nt;rt=pl[nt=1]=New();for(RI i=l;i<=r;++i) Ins(s[i],v[i]);Get();
		}
		I int Q()
		{
			RI i,x=rt,t,l=st.length(),g=0;for(i=0;i^l;++i) if(!O[x].S[t=st[i]-'a']) break;else x=O[x].S[t],g+=O[x].V;return g;
		}
}AC[LN+1];
int main()
{
	RI Qt,i,op,x,t,ct=0;for(i=1;(1<<i)<=N;++i) Lg[1<<i]=i;
	scanf("%d",&Qt);W(Qt--) switch(scanf("%d",&op),cin>>st,op)
	{
		case 1:s[++ct]=st,v[ct]=1,AC[Lg[ct&-ct]].Bd(ct-(ct&-ct)+1,ct);break;
		case 2:s[++ct]=st,v[ct]=-1,AC[Lg[ct&-ct]].Bd(ct-(ct&-ct)+1,ct);break;
		case 3:x=ct,t=0;W(x) t+=AC[Lg[x&-x]].Q(),x-=x&-x;printf("%d\n",t),fflush(stdout);break;
	}return 0;
}