#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define M 1000000
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,Qt,a[N+5],p[N+5],L[N+5],R[N+5],St[N+5];pair<int,int> u[N+5];
vector<pair<int,int> > w[N+5];vector<pair<int,int> >::iterator it;
struct OP {int x,l,r,v;bool operator < (Cn OP& o) Cn {return x<o.x;}}s[N*8];
LL ans[M+5];struct Q {int p,x,l,r,v;bool operator < (Cn Q& o) Cn {return x<o.x;}}q[2*M+5];
struct Seg
{
	LL k,b;I friend Seg operator - (Cn Seg& o) {return (Seg){-o.k,-o.b};}
	I Seg operator + (Cn Seg& o) Cn {return (Seg){k+o.k,b+o.b};}
	I Seg operator - (Cn Seg& o) Cn {return (Seg){k-o.k,b-o.b};}
	I Seg operator * (CI o) Cn {return (Seg){k*o,b*o};}
	I LL GV(CI x) {return 1LL*k*x+b;}
};
class SegmentTree
{
	private:
		#define PT RI l=1,RI r=n,RI o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define PU(o) (V[o]=V[o<<1]+V[o<<1|1]+F[o]*(r-l+1))
		Seg V[N<<2],F[N<<2];
	public:
		void U(CI L,CI R,Cn Seg& v,PT)
		{
			if(L<=l&&r<=R) return (void)(F[o]=F[o]+v,V[o]=V[o]+v*(r-l+1));
			RI u=l+r>>1;L<=u&&(U(L,R,v,LT),0),R>u&&(U(L,R,v,RT),0),PU(o);
		}
		Seg Q(CI L,CI R,PT)
		{
			if(L==l&&r==R) return V[o];RI u=l+r>>1;
			return (R<=u?Q(L,R,LT):(L>u?Q(L,R,RT):Q(L,u,LT)+Q(u+1,R,RT)))+F[o]*(R-L+1);
		}
}S;
int main()
{
	RI i,j,k,x,y,T;for(read(n,Qt),i=1;i<=n;++i) read(a[i]),p[a[i]]=i;
	for(i=1;i<=Qt;++i) read(x,y),q[i]=(Q){i,x-1,x,y,-1},q[Qt+i]=(Q){i,y,x,y,1};sort(q+1,q+2*Qt+1);
	for(T=0,i=1;i<=n;++i) {W(T&&a[St[T]]<a[i]) --T;L[i]=St[T]+1,St[++T]=i;}
	for(St[T=0]=n+1,i=n;i;--i) {W(T&&a[St[T]]<a[i]) --T;R[i]=St[T]-1,St[++T]=i;}
	for(i=1;i*(i+1)<=n;++i) for(j=i+1;i*j<=n;++j)
		if(L[p[i*j]]<=min(p[i],p[j])&&max(p[i],p[j])<=R[p[i*j]])
			w[p[i*j]].push_back(make_pair(min(min(p[i],p[j]),p[i*j]),max(max(p[i],p[j]),p[i*j])));
	RI c,tt=0;for(i=1;i<=n;++i)
	{
		for(sort(w[i].begin(),w[i].end()),c=0,it=w[i].begin();it!=w[i].end();++it)
			if(!c||u[c].first^it->first) {W(c&&u[c].second>=it->second) --c;u[++c]=*it;}
		for(u[0].first=L[i]-1,j=1;j<=c;++j)
			s[++tt]=(OP){u[j-1].first+1,u[j].second,R[i],1},s[++tt]=(OP){u[j].first+1,u[j].second,R[i],-1};
	}
	sort(s+1,s+tt+1),j=k=1;W(!q[k].x) ++k;for(i=1;i<=n;++i)
	{
		W(s[j].x==i) S.U(s[j].l,s[j].r,(Seg){s[j].v,-(i-1)*s[j].v}),++j;
		W(q[k].x==i) ans[q[k].p]+=q[k].v*S.Q(q[k].l,q[k].r).GV(q[k].x),++k;
	}
	for(i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}