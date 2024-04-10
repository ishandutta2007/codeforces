#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 300000
#define LN 19
using namespace std;
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
	I void NA() {pc('-'),pc('1'),pc('\n');} 
}using namespace FastIO;
int n;struct line {int x,y,v;bool operator < (Cn line& o) Cn {return v<o.v;}}s[N+5];
namespace K
{
	int ct,V[N<<1],S[N<<1][2],d,dfn[N<<1],fac[N<<1],D[N<<1],f[N<<1][LN+1];
	int fa[N+5];int Fa(CI x) {return fa[x]?fa[x]=Fa(fa[x]):x;}
	void dfs(CI x,CI p=0) {D[x]=D[f[x][0]=p]+1,fac[dfn[x]=++d]=x,x>n&&(dfs(S[x][0],x),dfs(S[x][1],x),0);}
	I void Bd()
	{
		RI i,j;for(sort(s+1,s+n),ct=n,i=1;i^n;++i) V[++ct]=s[i].v,fa[S[ct][0]=Fa(s[i].x)]=fa[S[ct][1]=Fa(s[i].y)]=ct;
		for(dfs(ct),j=1;j<=LN;++j) for(i=1;i<=ct;++i) f[i][j]=f[f[i][j-1]][j-1];
	}
	I int LCA(RI x,RI y)
	{
		RI i;for(D[x]<D[y]&&(swap(x,y),0),i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(x=f[x][i]);if(x==y) return x;
		for(i=0;f[x][i]^f[y][i];++i);for(--i;~i;--i) f[x][i]^f[y][i]&&(x=f[x][i],y=f[y][i]);return f[x][0];
	}
}
class SegmentTree
{
	private:
		#define PT RI l=1,RI r=n,RI o=1
		#define LT l,u,o<<1
		#define RT u+1,r,o<<1|1
		#define PU(o) (Mn[o]=min(Mn[o<<1],Mn[o<<1|1]),Mx[o]=max(Mx[o<<1],Mx[o<<1|1]))
		#define PD(o) (~P[o]&&(T(o<<1,P[o]),T(o<<1|1,P[o]),P[o]=-1))
		#define T(o,v) ((P[o]=v)?(Mn[o]=Mn0[o],Mx[o]=Mx0[o]):(Mn[o]=1e9,Mx[o]=0))
		int P[N<<2],Mn[N<<2],Mx[N<<2],Mn0[N<<2],Mx0[N<<2];
	public:
		void Bd(PT)
		{
			if(Mn[o]=1e9,Mx[o]=0,l==r) return (void)(Mn0[o]=Mx0[o]=K::dfn[l]);RI u=l+r>>1;Bd(LT),Bd(RT);
			Mn0[o]=min(Mn0[o<<1],Mn0[o<<1|1]),Mx0[o]=max(Mx0[o<<1],Mx0[o<<1|1]);
		}
		void U(CI L,CI R,CI v,PT)
		{
			if(L<=l&&r<=R) return (void)T(o,v);RI u=l+r>>1;PD(o);L<=u&&(U(L,R,v,LT),0),R>u&&(U(L,R,v,RT),0),PU(o);
		}
		I int G(CI x) Cn
		{
			RI mn=min(Mn[1],K::dfn[x]),mx=max(Mx[1],K::dfn[x]);return K::V[K::LCA(K::fac[mn],K::fac[mx])];
		}
}S;
int main()
{
	RI Qt,i;for(read(n,Qt),i=1;i^n;++i) read(s[i].x,s[i].y,s[i].v);K::Bd();
	RI op,x,y,t;S.Bd();W(Qt--) switch(read(op),op)
	{
		case 1:read(x,y),S.U(x,y,1);break;case 2:read(x,y),S.U(x,y,0);break;
		case 3:read(x),(t=S.G(x))?writeln(t):NA();break;
	}return clear(),0;
}