#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000000
#define M 500000
#define V 100001
#define BT 1000
#define BS 1000
using namespace std;
int n,sz,a[N+5],ans[M+5];struct Q {int op,l,r,v;}q[M+5];
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
struct Block
{
	int n,fg,Mx,a[BS+5],lnk[V+5];I int& operator [] (CI x) {return a[x];}
	int f[BS+5],g[BS+5];I int fa(CI x) {return f[x]?f[x]=fa(f[x]):x;}
	I void Build() {Mx=0;for(RI i=1;i<=n;++i) lnk[a[i]]?++g[f[i]=lnk[a[i]]]:g[lnk[a[i]]=i]=1,Mx=max(Mx,a[i]);}
	I void Cl() {for(RI i=1;i<=n;++i) lnk[a[i]=a[fa(i)]]=0,f[i]=0;for(RI i=1;i<=n;++i) a[i]-=fg;fg=0;}
	I void Union(CI x,CI y) {lnk[y]&&(lnk[x]?g[f[lnk[y]]=lnk[x]]+=g[lnk[y]]:a[lnk[x]=lnk[y]]=x,lnk[y]=0);}
	I int Q(CI v) {return fg+v<=V&&lnk[fg+v]?g[lnk[fg+v]]:0;}
	I int G(CI l,CI r,CI v) {RI t=0;for(RI i=l;i<=r;++i) a[fa(i)]==fg+v&&++t;return t;}
	I void U(CI v)
	{
		if(2*v>Mx-fg) {for(RI i=fg+v+1;i<=Mx;++i) Union(i-v,i);Mx=min(Mx,fg+v);}
		else {for(RI i=fg+v;i>=fg+1;--i) Union(i+v,i);fg+=v;}
	}
	I void BF(CI l,CI r,CI v)
	{
		RI i;for(Cl(),i=l;i<=r;++i) a[i]>v&&(a[i]-=v);for(fg=Mx=0,i=1;i<=n;++i) Mx=max(Mx,a[i]);Build();
	}
}B;
int main()
{
	RI Qt,i,j;for(read(n,Qt),i=1;i<=n;++i) read(a[i]);for(i=1;i<=Qt;++i) read(q[i].op,q[i].l,q[i].r,q[i].v);
	RI L,R,op,l,r,v;for(sz=sqrt(n),i=1;i<=(n-1)/sz+1;++i)
	{
		for(L=(i-1)*sz+1,R=min(i*sz,n),B.Cl(),B.n=0,j=L;j<=R;++j) B[++B.n]=a[j];
		for(B.Build(),j=1;j<=Qt;++j) L<=q[j].r&&R>=q[j].l&&
		(
			op=q[j].op,l=max(q[j].l-L+1,1),r=min(q[j].r-L+1,B.n),v=q[j].v,
			l==1&&r==B.n?(op==1?(B.U(v),0):ans[j]+=B.Q(v)):(op==1?(B.BF(l,r,v),0):ans[j]+=B.G(l,r,v))
		);
	}
	for(i=1;i<=Qt;++i) q[i].op==2&&(writeln(ans[i]),0);return clear(),0;
}