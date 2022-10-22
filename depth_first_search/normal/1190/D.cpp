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
using namespace std;
int n,x[N+5],y[N+5],vis[N+5];vector<int> s[N+5];vector<int>::iterator l,r;
template<int SZ> class Discretization
{
	private:
		int v[SZ+5];
	public:
		int n;I int GV(CI x) {return lower_bound(v+1,v+n+1,x)-v;}
		I void Init(CI x,int *s) {for(RI i=1;i<=x;++i) v[i]=s[i];sort(v+1,v+x+1),n=unique(v+1,v+x+1)-v-1;}
};Discretization<N> Dx,Dy;
template<int SZ> class TreeArray
{
	private:
		#define lowbit(x) (x&-(x))
		int n,v[SZ+5];
		I int Q(RI x,RI t=0) {W(x) t+=v[x],x-=lowbit(x);return t;}
	public:
		I void Init(CI _n) {n=_n;}
		I void Upt(RI x) {W(x<=n) ++v[x],x+=lowbit(x);}
		I int Qry(CI l,CI r) {return Q(r)-Q(l-1);}
};TreeArray<N> T;
I long long S(CI x) {return 1LL*x*(x+1)>>1;}
int main()
{
	RI i;long long ans=0;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",x+i,y+i);
	for(Dx.Init(n,x),Dy.Init(n,y),i=1;i<=n;++i) s[Dy.GV(y[i])].push_back(Dx.GV(x[i]));
	for(T.Init(Dx.n),i=Dy.n;i;--i)
	{
		sort(s[i].begin(),s[i].end());
		for(l=s[i].begin();l!=s[i].end();++l) !vis[*l]&&(T.Upt(*l),vis[*l]=1);
		ans+=S(T.Qry(1,Dx.n))-S(T.Qry(1,*s[i].begin()-1))-S(T.Qry(*(--s[i].end())+1,Dx.n));
		for(l=s[i].begin(),++(r=l);r!=s[i].end();++l,++r) ans-=S(T.Qry(*l+1,*r-1));
	}return cout<<ans<<endl,0;
}