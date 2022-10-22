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
int n,a[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void writeln(Con Ty& x) {write(x),pc('\n');}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
class SegmentTree
{
	private:
		#define P CI l=1,CI r=n,CI rt=1
		#define L l,mid,rt<<1
		#define R mid+1,r,rt<<1|1
		#define PU(x) (Mx[x]=max(Mx[x<<1],Mx[x<<1|1]),S[x]=S[x<<1]+S[x<<1|1])
		LL Mx[N<<2],S[N<<2];
	public:
		I void Build(P)
		{
			if(l==r) return (void)(Mx[rt]=S[rt]=a[l]);RI mid=l+r>>1;
			Build(L),Build(R),PU(rt);
		}
		I void Mod(CI tl,CI tr,CI X,P)
		{
			if(Mx[rt]<X) return;if(l==r) return (void)(Mx[rt]%=X,S[rt]%=X);RI mid=l+r>>1;
			tl<=mid&&(Mod(tl,tr,X,L),0),tr>mid&&(Mod(tl,tr,X,R),0),PU(rt);
		}
		I void Upt(CI x,CI y,P)
		{
			if(l==r) return (void)(Mx[rt]=S[rt]=y);RI mid=l+r>>1;
			x<=mid?Upt(x,y,L):Upt(x,y,R),PU(rt);
		}
		I LL Query(CI tl,CI tr,P)
		{
			if(tl<=l&&r<=tr) return S[rt];RI mid=l+r>>1;
			return (tl<=mid?Query(tl,tr,L):0)+(tr>mid?Query(tl,tr,R):0);
		}
}S;
int main()
{
	RI Qt,i,op,x,y,z;for(F.read(n,Qt),i=1;i<=n;++i) F.read(a[i]);
	S.Build();W(Qt--) switch(F.read(op,x,y),op)
	{
		case 1:F.writeln(S.Query(x,y));break;
		case 2:F.read(z),S.Mod(x,y,z);break;
		case 3:S.Upt(x,y);break;
	}return F.clear(),0;
}