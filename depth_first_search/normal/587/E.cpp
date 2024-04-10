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
#define LV 30
using namespace std;
int n,a[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
		Tp I void writeln(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);pc('\n');}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
struct LB
{
	int v[LV+5];I LB() {for(RI i=LV;~i;--i) v[i]=0;}
	I void A(RI x) {for(RI i=LV;~i;--i) if((x>>i)&1) {if(!v[i]) return (void)(v[i]=x);x^=v[i];}}
	I int C() {RI t=0;for(RI i=LV;~i;--i) v[i]&&++t;return t;}
	I friend LB operator + (LB x,LB y) {for(RI i=LV;~i;--i) y.v[i]&&(x.A(y.v[i]),0);return x;}
};
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1 
		#define PU(x) (S[x]=S[x<<1]+S[x<<1|1],V[x]=V[x<<1]^V[x<<1|1])
		int V[N<<2];LB S[N<<2];
	public:
		I void Build(int *a,PT)
		{
			if(l==r) return S[rt].A(V[rt]=a[l]^a[l-1]);RI mid=l+r>>1;Build(a,LT),Build(a,RT),PU(rt);
		}
		I void U(CI x,CI v,PT)
		{
			if(l==r) return (S[rt]=LB()).A(V[rt]^=v);RI mid=l+r>>1;x<=mid?U(x,v,LT):U(x,v,RT),PU(rt);
		}
		I int Q(CI x,PT)
		{
			if(r<=x) return V[rt];RI mid=l+r>>1;return Q(x,LT)^(x>mid?Q(x,RT):0);
		}
		I LB G(CI x,CI y,PT)
		{
			if(x<=l&&r<=y) return S[rt];RI mid=l+r>>1;if(y<=mid) return G(x,y,LT);
			if(x>mid) return G(x,y,RT);return G(x,mid,LT)+G(mid+1,y,RT);
		}
}S;
int main()
{
	RI Qt,i,op,x,y,v;for(F.read(n),F.read(Qt),i=1;i<=n;++i) F.read(a[i]);
	LB t;S.Build(a);W(Qt--) switch(F.read(op),F.read(x),F.read(y),op)
	{
		case 1:F.read(v),S.U(x,v),y^n&&(S.U(y+1,v),0);break;
		case 2:(t=x^y?S.G(x+1,y):LB()).A(S.Q(x)),F.writeln(1<<t.C());break;
	}return F.clear(),0;
}