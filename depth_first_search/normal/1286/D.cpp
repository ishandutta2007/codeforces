#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define X 998244353
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define D isdigit(oc=tc())
	int ff;char oc,FI[FS],*FA=FI,*FB=FI;
	Tp I void read(Ty& x) {x=0,ff=1;W(!D) ff=oc^'-'?1:-1;W(x=(x<<3)+(x<<1)+(oc&15),D);x*=ff;}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	#undef D
}using namespace FastIO;
int n,x[N+5],v[N+5],p[N+5];
I int QP(RI x,RI y=X-2) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
struct Data {int x,a,b,A,B;bool operator < (Cn Data& o) Cn {return 1LL*A*o.B<1LL*B*o.A;}}s[2*N+5];
struct M
{
	int a[2][2];I int* operator [] (CI o) {return a[o];}I Cn int* operator [] (CI o) Cn {return a[o];}
	I void Cl(CI x,CI y) {for(RI i=0;i^2;++i) for(RI j=0;j^2;++j) (i^x||j^y)&&(a[i][j]=0);}
	I M operator * (Cn M& o) Cn
	{
		M t;t[0][0]=(1LL*a[0][0]*o[0][0]+1LL*a[0][1]*o[1][0])%X;
		t[0][1]=(1LL*a[0][0]*o[0][1]+1LL*a[0][1]*o[1][1])%X;
		t[1][0]=(1LL*a[1][0]*o[0][0]+1LL*a[1][1]*o[1][0])%X;
		t[1][1]=(1LL*a[1][0]*o[0][1]+1LL*a[1][1]*o[1][1])%X;return t;
	}
	I int S() Cn {return (0LL+a[0][0]+a[0][1]+a[1][0]+a[1][1])%X;}
};
class SegmentTree
{
	private:
		#define PT RI l=1,RI r=n-1,RI o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define PU(o) (V[o]=V[o<<1]*V[o<<1|1])
		M V[N<<2],V_[N+5];
	public:
		void Bd(PT)
		{
			if(l==r)
			{
				if(l^1) return (void)(V[o][0][0]=V[o][1][0]=(1-p[l+1]+X)%X,V[o][0][1]=V[o][1][1]=p[l+1]);
				V[o][0][0]=1LL*(1-p[l]+X)*(1-p[l+1]+X)%X,V[o][0][1]=1LL*(1-p[l]+X)*p[l+1]%X;
				V[o][1][0]=1LL*p[l]*(1-p[l+1]+X)%X,V[o][1][1]=1LL*p[l]*p[l+1]%X;return;
			}
			RI u=l+r>>1;Bd(LT),Bd(RT),PU(o); 
		}
		void D(CI x,CI a,CI b,PT)
		{
			if(l==r) return (void)((V[o]=V_[x])[a][b]=0);RI u=l+r>>1;x<=u?D(x,a,b,LT):D(x,a,b,RT),PU(o);
		}
		void G(CI x,CI a,CI b,PT)
		{
			if(l==r) return (void)(V_[x]=V[o],V[o].Cl(a,b));RI u=l+r>>1;x<=u?G(x,a,b,LT):G(x,a,b,RT),PU(o);
		}
		I int Q() Cn {return V[1].S();}
}S;
int main()
{
	RI i;if(read(n),n==1) return puts("0"),0;
	RI Iv=QP(100);for(i=1;i<=n;++i) read(x[i],v[i],p[i]),p[i]=1LL*p[i]*Iv%X;
	RI c=0;for(i=1;i^n;++i)
	{
		s[++c]=(Data){i,1,0,x[i+1]-x[i],v[i]+v[i+1]};
		if(v[i]>v[i+1]) s[++c]=(Data){i,1,1,x[i+1]-x[i],v[i]-v[i+1]};
		if(v[i]<v[i+1]) s[++c]=(Data){i,0,0,x[i+1]-x[i],v[i+1]-v[i]};
	}
	RI t=0;for(sort(s+1,s+c+1),S.Bd(),i=1;i<=c;++i)
		S.G(s[i].x,s[i].a,s[i].b),t=(t+1LL*S.Q()*s[i].A%X*QP(s[i].B))%X,S.D(s[i].x,s[i].a,s[i].b);
	return printf("%d\n",t),0;
}