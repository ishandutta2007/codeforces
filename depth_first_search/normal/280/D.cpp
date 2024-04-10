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
#define K 20
#define max(x,y) ((x)<(y)?(y):(x))
#define Gmax(x,y) (x<(y)&&(x=(y),0))
using namespace std;
int n,a[N+5];struct Op {int l,r;I Op(CI x=0,CI y=0):l(x),r(y){}}s[K+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int f,T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0,f=1;W(!D) f=c^'-'?1:-1;W(x=tn+(c&15),D);x*=f;}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void writeln(Con Ty& x) {write(x),pc('\n');}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
struct data
{
	int l,r,v;I data(CI x=0,CI y=0,CI z=0):l(x),r(y),v(z){}
	I data operator + (Con data& o) Con {return data(l,o.r,v+o.v);}
	I bool operator < (Con data& o) Con {return v<o.v;}
	I void operator *= (CI o) {v*=o;}
};
struct status
{
	data Pre,Nxt,Val;I status() {Pre=Nxt=Val=data();}
	I void operator *= (CI o) {Pre*=o,Nxt*=o,Val*=o;}
	I data operator = (Con data& o) {return Pre=Nxt=Val=o;}
};
struct qdata
{
	status Max;data Sum;
	I qdata(Con status& x=status(),Con data& y=data()):Max(x),Sum(y){}
};
class SegmentTree
{
	private:
		#define P CI l=1,CI r=n,CI rt=1
		#define L l,mid,rt<<1
		#define R mid+1,r,rt<<1|1
		#define LS(x) O[x<<1]
		#define RS(x) O[x<<1|1]
		#define PU(x)\
		(\
			O[x].Max.Pre=max(LS(x).Max.Pre,LS(x).Sum+RS(x).Max.Pre),\
			O[x].Max.Nxt=max(RS(x).Max.Nxt,LS(x).Max.Nxt+RS(x).Sum),\
			O[x].Max.Val=max(LS(x).Max.Nxt+RS(x).Max.Pre,max(LS(x).Max.Val,RS(x).Max.Val)),\
			O[x].Min.Pre=min(LS(x).Min.Pre,LS(x).Sum+RS(x).Min.Pre),\
			O[x].Min.Nxt=min(RS(x).Min.Nxt,LS(x).Min.Nxt+RS(x).Sum),\
			O[x].Min.Val=min(LS(x).Min.Nxt+RS(x).Min.Pre,min(LS(x).Min.Val,RS(x).Min.Val)),\
			O[x].Sum=LS(x).Sum+RS(x).Sum\
		)
		#define PD(x) !~O[x].F&&(Upt(x<<1),Upt(x<<1|1),O[x].F=1)
		#define Assign(x,v) (O[x].Sum=O[x].Max=O[x].Min=data(l,r,v))
		#define Upt(x) (O[x].Sum*=-1,O[x].Max*=-1,O[x].Min*=-1,swap(O[x].Max,O[x].Min),O[x].F*=-1)
		struct Il {data Sum;status Max,Min;int F;I Il() {Sum=data(),Max=Min=status(),F=1;}}O[N<<2];
	public:
		I void Build(P) {if(l==r) return (void)Assign(rt,a[l]);RI mid=l+r>>1;Build(L),Build(R),PU(rt);}
		I void Update(CI x,CI v,P)
		{
			if(l==r) return (void)Assign(rt,v);PD(rt);RI mid=l+r>>1;
			x<=mid?Update(x,v,L):Update(x,v,R),PU(rt);
		}
		I void Modify(CI tl,CI tr,P)
		{
			if(tl<=l&&r<=tr) return (void)Upt(rt);PD(rt);RI mid=l+r>>1;
			tl<=mid&&(Modify(tl,tr,L),0),tr>mid&&(Modify(tl,tr,R),0),PU(rt);
		}
		I qdata Query(CI tl,CI tr,P)
		{
			if(tl<=l&&r<=tr) return qdata(O[rt].Max,O[rt].Sum);PD(rt);RI mid=l+r>>1;
			if(tr<=mid) return Query(tl,tr,L);if(tl>mid) return Query(tl,tr,R);
			qdata ql=Query(tl,tr,L),qr=Query(tl,tr,R),res;
			res.Max.Pre=max(ql.Max.Pre,ql.Sum+qr.Max.Pre),
			res.Max.Nxt=max(qr.Max.Nxt,ql.Max.Nxt+qr.Sum),
			res.Max.Val=max(ql.Max.Nxt+qr.Max.Pre,max(ql.Max.Val,qr.Max.Val));
			return res.Sum=ql.Sum+qr.Sum,res;
		}
}S;
int main()
{
	RI Qtot,i,op,x,y,z,ans,cnt;data t;for(F.read(n),i=1;i<=n;++i) F.read(a[i]);
	S.Build(),F.read(Qtot);W(Qtot--)
	{
		if(F.read(op,x,y),op)
		{
			F.read(z),ans=cnt=0;W(z--) 
			{
				if((t=S.Query(x,y).Max.Val).v>0) S.Modify(t.l,t.r),s[++cnt]=Op(t.l,t.r),ans+=t.v;
				else break;
			}
			W(cnt) S.Modify(s[cnt].l,s[cnt].r),--cnt;F.writeln(ans);
		}else S.Update(x,y);
	}return F.clear(),0;
}