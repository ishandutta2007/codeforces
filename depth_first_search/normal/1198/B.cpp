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
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
template<int SZ> class SegmentTree
{
	private:
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PD(x) (U(x<<1,Mx[x]),U(x<<1|1,Mx[x]),Mx[x]=0)
		#define U(x,v) (Mx[x]<(v)&&(Mx[x]=v))
		int n,V[SZ+5],Mx[SZ<<2];
		I void Upt(CI x,CI y,CI l,CI r,CI rt)
		{
			if(l==r) return (void)(Mx[rt]=0);RI mid=l+r>>1;PD(rt),
			x<=mid?Upt(x,y,LT):Upt(x,y,RT);
		}
		I int Qry(CI x,CI l,CI r,CI rt)
		{
			if(l==r) return max(V[l],Mx[rt]);RI mid=l+r>>1,t;
			return t=x<=mid?Qry(x,LT):Qry(x,RT),max(t,Mx[rt]);
		}
	public:
		I void Build(CI _n,int *a) {n=_n;for(RI i=1;i<=n;++i) V[i]=a[i];}
		I void Upt(CI x,CI y) {V[x]=y,Upt(x,y,1,n,1);}I void Max(CI x) {U(1,x);}
		I int Qry(CI x) {return Qry(x,1,n,1);}
};SegmentTree<N> S;
int main()
{
	RI Qt,i,op,x,y;for(F.read(n),i=1;i<=n;++i) F.read(a[i]);S.Build(n,a);
	F.read(Qt);W(Qt--) F.read(op,x),op==1?(F.read(y),S.Upt(x,y)):S.Max(x);
	for(i=1;i<=n;++i) F.write(S.Qry(i)," \n"[i==n]);return F.clear(),0;
}