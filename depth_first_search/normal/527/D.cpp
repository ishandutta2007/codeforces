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
#define max(x,y) ((x)>(y)?(x):(y))
#define Gmax(x,y) (x<(y)&&(x=(y)))
using namespace std;
int n,f[N+5],dc,dv[2*N+5];
struct Point
{
	int x,w;I Point(CI a=0,CI b=0):x(a),w(b){}
	I bool operator < (Con Point& o) Con {return x<o.x;}
}s[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
}F;
template<int SZ> class SegmentTree
{
	private:
		#define L l,mid,rt<<1
		#define R mid+1,r,rt<<1|1
		#define PU(x) (V[x]=max(V[x<<1],V[x<<1|1]))
		int n,V[SZ<<2];
		I int QL(CI x,RI l,RI r,RI rt)
		{
			RI mid,res=0;W(l^x) mid=l+r>>1,
				x<=mid?(Gmax(res,V[rt<<1|1]),r=mid,rt<<=1):(l=mid+1,(rt<<=1)|=1);
			return max(res,V[rt]);
		}
		I int QR(CI x,RI l,RI r,RI rt)
		{
			RI mid,res=0;W(r^x) mid=l+r>>1,
				x<=mid?(r=mid,rt<<=1):(Gmax(res,V[rt<<1]),l=mid+1,(rt<<=1)|=1);
			return max(res,V[rt]);
		}
	public:
		I void Init(CI _n) {n=_n;}
		I void Upt(CI tx,CI tv)
		{
			RI l=1,r=n,rt=1,mid;W(l^r) mid=l+r>>1,
				Gmax(V[rt],tv),tx<=mid?(r=mid,rt<<=1):(l=mid+1,(rt<<=1)|=1);
			Gmax(V[rt],tv);
		}
		I int QMax(CI tl,CI tr)
		{
			RI l=1,r=n,rt=1,mid,t1,t2;W(l^r)
			{
				if(mid=l+r>>1,tl<=mid&&tr>mid) return
					t1=QL(tl,l,mid,rt<<1),t2=QR(tr,mid+1,r,rt<<1|1),max(t1,t2);
				tr<=mid?(r=mid,rt<<=1):(l=mid+1,(rt<<=1)|=1);
			}return V[rt];
		}
		I int QMax() {return V[1];}
};SegmentTree<N<<1> S;
int main()
{
	RI i,ans=0;for(F.read(n),i=1;i<=n;++i) F.read(s[i].x,s[i].w);sort(s+1,s+n+1);
	for(i=1;i<=n;++i) dv[++dc]=s[i].x+s[i].w,dv[++dc]=s[i].x-s[i].w;
	sort(dv+1,dv+dc+1),dc=unique(dv+1,dv+dc+1)-dv-1,S.Init(dc);
	#define GV(x) (lower_bound(dv+1,dv+dc+1,x)-dv)
	for(i=1;i<=n;++i) S.Upt(GV(s[i].x+s[i].w),S.QMax(1,GV(s[i].x-s[i].w))+1);
	return printf("%d",S.QMax()),0;
}