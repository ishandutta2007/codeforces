#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 100
#define M 100000
#define LL long long
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp void writeln(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,m;LL a[N+5],b[M+5];
class SegmentTree
{
	private:
		#define PT int l=2,int r=m,int o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define PU(o) (O[o]=O[o<<1]+O[o<<1|1],Mx[o]=max(Mx[o<<1],Mx[o<<1|1]))
		#define PD(o) (F[o]&&(T(o<<1,F[o]),T(o<<1|1,F[o]),F[o]=0))
		#define T(o,v) (O[o]+=v,Mx[o]+=v,F[o]+=v)
		LL Mx[M<<2];int F[M<<2];
		struct V
		{
			int c;LL s,v;V(int x=0,LL y=0,LL z=0):c(x),s(y),v(z){}
			V operator + (Cn V& o) Cn {return V(c+o.c,s+o.s,v+o.v+s*o.c);}
			void operator += (int f) {s+=1LL*c*f,v+=1LL*c*(c+1)/2*f;}
		}O[M<<2];
		V G(int L,int R,PT)
		{
			if(L<=l&&r<=R) return O[o];int u=l+r>>1;PD(o);
			return R<=u?G(L,R,LT):(L>u?G(L,R,RT):G(L,u,LT)+G(u+1,R,RT));
		}
		int Z(Cn LL& v,PT)
		{
			if(l==r) return l-1;int u=l+r>>1;PD(o);return Mx[o<<1]<=v?Z(v,RT):Z(v,LT);
		}
	public:
		void Bd(PT)
		{
			if(l==r) return (void)(O[o]=V(1,b[l],b[l]),Mx[o]=b[l]);int u=l+r>>1;Bd(LT),Bd(RT),PU(o);
		}
		void U(CI L,CI v,PT)
		{
			if(L<=l) return (void)T(o,v);int u=l+r>>1;PD(o),L<=u&&(U(L,v,LT),0),U(L,v,RT),PU(o);
		}
		int Find(LL v) {return Mx[1]<=v?m:Z(v);}
		LL Q(CI L,CI R,CI w) {V t=G(L,R);return t.v+1LL*t.s*w;}
}S;
int main()
{
	int Qt,i;for(read(n,m,Qt),i=1;i<=n;++i) read(a[i]);for(i=n;i;--i) a[i]-=a[i-1];
	for(i=1;i<=m;++i) read(b[i]);for(i=m;i;--i) b[i]-=b[i-1];S.Bd();
	int op,x,y;LL t;while(Qt--)
	{
		if(read(op,x,y),op==1) for(i=n-x+1;i<=n;++i) a[i]+=y;else m==x&&(b[1]+=y,--x),S.U(m-x+1,y);
		for(t=(a[1]+b[1])*(n+m-1),i=2,x=1;i<=n;++i)
			y=S.Find(a[i]),x^y&&(t+=S.Q(x+1,y,n-i+1+m-y),x=y),t+=a[i]*(n-i+1+m-y);
		x^m&&(t+=S.Q(x+1,m,0)),writeln(t);
	}return 0;
}