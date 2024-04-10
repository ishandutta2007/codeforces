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
#define K 5
using namespace std;
int n,p,a[N+5];struct Data
{
	int k,V[K],C[K];I Data() {k=0,memset(V,0,sizeof(V)),memset(C,0,sizeof(C));}
	I friend Data operator + (Data x,Data y)
	{
		for(RI i=0,j;i^y.k;++i)
		{
			for(j=0;j^x.k&&x.V[j]^y.V[i];++j);if(j^x.k) {x.C[j]+=y.C[i];continue;}
			if(x.k^(100/p)) {x.V[x.k]=y.V[i],x.C[x.k++]=y.C[i];continue;}
			for(j=0;j^x.k;++j) x.C[j]<y.C[i]&&(swap(x.V[j],y.V[i]),swap(x.C[j],y.C[i]),0);
			for(j=0;j^x.k;++j) x.C[j]-=y.C[i];
		}return x;
	}
};
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);}
	I void print(Con Data& v) {write(v.k),pc(' ');for(RI i=0;i^v.k;++i) write(v.V[i]),pc(' ');pc('\n');}
}using namespace FastIO;
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PU() (V[rt]=V[rt<<1]+V[rt<<1|1])
		#define PD() (F[rt]&&(T(rt<<1,F[rt],mid-l+1),T(rt<<1|1,F[rt],r-mid),F[rt]=0))
		#define T(x,v,c) (V[x].k=1,V[x].V[0]=F[x]=v,V[x].C[0]=c)
		Data V[N<<2];int F[N<<2];
	public:
		I void B(PT) {if(l==r) return (void)T(rt,a[l],1);RI mid=l+r>>1;B(LT),B(RT),PU();}
		I void U(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)T(rt,v,r-l+1);RI mid=l+r>>1;PD();
			L<=mid&&(U(L,R,v,LT),0),R>mid&&(U(L,R,v,RT),0),PU();
		}
		I Data Q(CI L,CI R,PT)
		{
			if(L==l&&r==R) return V[rt];RI mid=l+r>>1;PD();if(R<=mid) return Q(L,R,LT);
			if(L>mid) return Q(L,R,RT);return Q(L,mid,LT)+Q(mid+1,R,RT);
		}
}S;
int main()
{
	RI Qt,i,op,x,y,v;for(read(n,Qt,p),i=1;i<=n;++i) read(a[i]);S.B();
	W(Qt--) read(op,x,y),op==1?(read(v),S.U(x,y,v)):print(S.Q(x,y));return clear(),0;
}