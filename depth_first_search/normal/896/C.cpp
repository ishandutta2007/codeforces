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
#define X 1000000007
#define LL long long
#define swap(x,y) (x^=y^=x^=y)
using namespace std;
int n,seed,Mx,a[N+5];I int Rd(CI x) {RI t=seed;return seed=(7LL*seed+13)%X,t%x+1;}
I int QP(RI x,RI y,RI p) {RI t=1;W(y) y&1&&(t=1LL*t*x%p),x=1LL*x*x%p,y>>=1;return t;}
class ChthollyTree
{
	private:
		#define IT set<P>::iterator
		#define T insert
		#define E erase
		#define fi first
		#define se second
		struct P
		{
			int l,r;mutable LL v;I P(CI x=0,CI y=0,Con LL& t=0):l(x),r(y),v(t){}
			I bool operator < (Con P& o) Con {return l<o.l;}
		};set<P> S;
		I IT Sp(CI x)
		{
			IT t=S.lower_bound(P(x));if(t!=S.end()&&t->l==x) return t;
			RI l=(--t)->l,r=t->r;LL v=t->v;return S.E(t),S.T(P(l,x-1,v)),S.T(P(x,r,v)).fi;
		}
	public:
		I void Build() {for(RI i=1;i<=n;++i) S.T(P(i,i,a[i]));}
		I void A(CI l,CI r,CI v) {IT R=Sp(r+1),L=Sp(l);S.E(L,R),S.T(P(l,r,v));}
		I void U(CI l,CI r,CI v) {IT R=Sp(r+1),L=Sp(l);W(L!=R) (L++)->v+=v;}
		vector<pair<LL,int> > v;I LL G(CI l,CI r,RI k)
		{
			IT R=Sp(r+1),L=Sp(l);v.clear();W(L!=R) v.push_back(make_pair(L->v,L->r-L->l+1)),++L;
			RI i;for(sort(v.begin(),v.end()),i=0;v[i].se<k;k-=v[i++].se);return v[i].fi;
		}
		I int Q(CI l,CI r,CI x,CI y)
		{
			IT R=Sp(r+1),L=Sp(l);RI t=0;W(L!=R)
				t=(1LL*(L->r-L->l+1)*QP(L->v%y,x,y)+t)%y,++L;return t;
		}
}O;
int main()
{
	RI Qt,i;for(scanf("%d%d%d%d",&n,&Qt,&seed,&Mx),i=1;i<=n;++i) a[i]=Rd(Mx);O.Build();
	RI op,l,r,x,y;W(Qt--) switch(op=Rd(4),l=Rd(n),r=Rd(n),l>r&&swap(l,r),op)
	{
		case 1:O.U(l,r,Rd(Mx));break;case 2:O.A(l,r,Rd(Mx));break;
		case 3:printf("%lld\n",O.G(l,r,Rd(r-l+1)));break;
		case 4:x=Rd(Mx),y=Rd(Mx),printf("%d\n",O.Q(l,r,x,y));break;
	}return 0;
}