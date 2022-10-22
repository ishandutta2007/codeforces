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
#define LL long long
using namespace std;
int n;LL a[N+5];
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
namespace Block
{
	#define BS 320
	#define BT 320
	int sz,bl[N+5],p[BT+5],q[BT+5];LL f[N+5],tg[BT+5];vector<int> g[BT+5];
	queue<int> tmp[BS+5];I void Bd(CI o)
	{
		RI i,x,l=(o-1)*sz+1,r=min(o*sz,n);for(i=l;i<=r;++i) (a[i]-=tg[o])>=l?(tmp[a[i]-l].push(i),0):f[i]=a[i];tg[o]=0;
		for(p[o]=q[o]=0,g[o].clear(),i=l;i<=r;++i) W(!tmp[i-l].empty()) ++q[o],g[o].push_back(x=tmp[i-l].front()),tmp[i-l].pop(),f[x]=f[i];
	}
	I void BF(CI l,CI r,CI v)
	{
		for(RI i=l;i<=r;++i) a[i]-=v;Bd(bl[l]);
	}
	I void Tg(CI o,CI v)
	{
		RI l=(o-1)*sz+1;tg[o]+=v;W(p[o]^q[o]&&a[g[o][p[o]]]-tg[o]<l) f[g[o][p[o]]]=a[g[o][p[o]]],++p[o];
		for(RI i=p[o];i^q[o];++i) f[g[o][i]]=f[a[g[o][i]]-tg[o]];
	}
	I void U(CI l,CI r,CI v)
	{
		RI L=bl[l],R=bl[r];if(L==R) return BF(l,r,v);BF(l,L*sz,v),BF((R-1)*sz+1,r,v);for(RI i=L+1;i<R;++i) Tg(i,v);
	}
	I int Q(RI x,RI y)
	{
		#define F(x) max(f[x]-tg[bl[x]],1LL)
		RI t;W(x^y)
		{
			if(x<y&&(swap(x,y),0),bl[x]^bl[y]) {x=F(x);continue;}if(F(x)^F(y)) {x=F(x),y=F(y);continue;}
			if((t=max(a[x]-tg[bl[x]],1LL))==F(x)) return t;x=t;
		}return x;
	}
}using namespace Block;
int main()
{
	RI Qt,i,op,l,r,x;for(read(n,Qt),sz=sqrt(n),bl[1]=1,i=2;i<=n;++i) read(a[i]),bl[i]=(i-1)/sz+1;for(i=1;i<=bl[n];++i) Bd(i);
	W(Qt--) read(op,l,r),op==1?(read(x),U(l,r,x)):writeln(Q(l,r));return clear(),0;
}