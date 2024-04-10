#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 300000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	char oc,FI[FS],*FA=FI,*FB=FI;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	void readc(char& x) {while(isspace(x=tc()));}
}using namespace FastIO;
int n,X,a[N+5],f[N+5][2];
class SegmentTree
{
	private:
		#define PT int l=1,int r=n,int o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define F(n,x,y) (1LL*f[n][0]*x+1LL*f[n][1]*y)%X
		#define T(o,x,y) (A[o]=(A[o]+x)%X,B[o]=(B[o]+y)%X,fA[o]=(fA[o]+x)%X,fB[o]=(fB[o]+y)%X)
		int P[N<<2],A[N<<2],B[N<<2],fA[N<<2],fB[N<<2];
		void PU(CI o,CI l,CI r)
		{
			int u=l+r>>1;if(!P[o<<1]||!P[o<<1|1]) return (void)(P[o]=0);
			if(l==u&&r==u+1) return (void)(P[o]=1,A[o]=A[o<<1],B[o]=A[o<<1|1]);
			if(l==u)
			{
				if((A[o<<1]+A[o<<1|1])%X!=B[o<<1|1]) return (void)(P[o]=0);
				return (void)(P[o]=1,A[o]=A[o<<1],B[o]=A[o<<1|1]);
			}
			if(r==u+1)
			{
				if((A[o<<1]+B[o<<1])%X!=A[o<<1|1]) return (void)(P[o]=0);
				return (void)(P[o]=1,A[o]=A[o<<1],B[o]=B[o<<1]);
			}
			if(F(u+1-l,A[o<<1],B[o<<1])!=A[o<<1|1]||F(u+2-l,A[o<<1],B[o<<1])!=B[o<<1|1]) return (void)(P[o]=0);
			P[o]=1,A[o]=A[o<<1],B[o]=B[o<<1];
		}
		void PD(CI o,CI l,CI r)
		{
			if(!fA[o]&&!fB[o]) return;int u=l+r>>1;
			T(o<<1,fA[o],fB[o]),T(o<<1|1,F(u+1-l,fA[o],fB[o]),F(u+2-l,fA[o],fB[o])),fA[o]=fB[o]=0;
		}
	public:
		void Bd(PT)
		{
			if(l==r) return (void)(P[o]=1,A[o]=a[l]);int u=l+r>>1;Bd(LT),Bd(RT),PU(o,l,r);
		}
		void U(CI L,CI R,CI x,CI y,PT)
		{
			if(L==l&&r==R) return (void)T(o,x,y);int u=l+r>>1;PD(o,l,r);if(R<=u) U(L,R,x,y,LT);
			else if(L>u) U(L,R,x,y,RT);else U(L,u,x,y,LT),U(u+1,R,F(u+1-L,x,y),F(u+2-L,x,y),RT);PU(o,l,r);
		}
		int Check() Cn {return P[1]&&!A[1]&&(n==1||!B[1]);}
}S;
int main()
{
	int Qt,i,x,y;for(read(n,Qt,X),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) read(x),a[i]=(a[i]-x+X)%X;
	for(f[0][0]=f[1][1]=1,i=2;i<=n;++i) f[i][0]=(f[i-2][0]+f[i-1][0])%X,f[i][1]=(f[i-2][1]+f[i-1][1])%X;S.Bd();
	char op;while(Qt--) readc(op),read(x,y),op=='A'?S.U(x,y,1,1):S.U(x,y,X-1,X-1),puts(S.Check()?"YES":"NO");return 0;
}