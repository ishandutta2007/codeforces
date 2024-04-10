#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 150000
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int n,m,h,dc,a[N+5],b[N+5],dv[N+5];
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
class SegmentTree
{
	private:
		#define L l,mid,rt<<1,tl,tr
		#define R mid+1,r,rt<<1|1,tl,tr
		#define PU(x) (Mn[x]=min(Mn[x<<1],Mn[x<<1|1]))
		#define PD(x) (F[x]&&(Add(x<<1,F[x]),Add(x<<1|1,F[x]),F[x]=0))
		#define Add(x,v) (Mn[x]+=v,F[x]+=v)
		int Mn[N<<2],F[N<<2];
		I void upt(CI l,CI r,CI rt,CI tl,CI tr,CI v)
		{
			if(tl<=l&&r<=tr) return (void)Add(rt,v);PD(rt);RI mid=l+r>>1;
			tl<=mid&&(upt(L,v),0),tr>mid&&(upt(R,v),0),PU(rt);
		}
	public:
		I void Update(CI l,CI r,CI v) {upt(1,n,1,l,r,v);}
		I bool Check() {return Mn[1]>=0;}
}S;
I int GV(CI x)
{
	RI l=1,r=dc,mid;W(l<=r) dv[mid=l+r>>1]<x?l=mid+1:r=mid-1;
	return l;
}
int main()
{
	RI i,ans=0;for(F.read(n,m,h),i=1;i<=m;++i) F.read(b[i]);
	for(sort(b+1,b+m+1),i=1;i<=n;++i) F.read(a[i]),dv[i]=a[i];
	sort(dv+1,dv+n+1),dc=unique(dv+1,dv+n+1)-dv-1;for(i=1;i<=n;++i) a[i]=GV(a[i]);
	for(i=1;i<=m;++i) b[i]=GV(h-b[i]),b[i]<h&&(S.Update(b[i],b[i],b[i]^b[i-1]?-i:-1),0);
	for(i=1;i<=m;++i) S.Update(1,a[i],1);ans+=S.Check();
	for(i=m+1;i<=n;++i) S.Update(1,a[i-m],-1),S.Update(1,a[i],1),ans+=S.Check(); 
	return printf("%d",ans),0;
}