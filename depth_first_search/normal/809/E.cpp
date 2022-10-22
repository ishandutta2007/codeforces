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
#define LN 18
#define X 1000000007
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,a[N+5],p[N+5],f[N+5],ee,lnk[N+5];struct edge {int to,nxt;}e[2*N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int Pt,P[N+5],phi[N+5];I void Sieve()
{
	phi[1]=1;for(RI i=2,j;i<=n;++i) for(!P[i]&&(phi[P[++Pt]=i]=i-1),j=1;j<=Pt&&i*P[j]<=n;++j)
		if(P[i*P[j]]=1,i%P[j]) phi[i*P[j]]=phi[i]*(P[j]-1);else {phi[i*P[j]]=phi[i]*P[j];break;}
}
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
		#undef D
}F;
namespace VTree
{
	int d,dI[N+5],dO[N+5],D[N+5],fa[N+5][LN+5];
	I bool cmp(CI x,CI y) {return dI[x]<dI[y];}
	I int LCA(RI x,RI y)
	{
		RI i;D[x]<D[y]&&(swap(x,y),0);
		for(i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(x=fa[x][i]);if(x==y) return x;
		for(i=LN;~i;--i) fa[x][i]^fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0];
	}
	I void Init(CI x=1)
	{
		RI i;for(dI[x]=++d,i=1;i<=LN;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
		for(i=lnk[x];i;i=e[i].nxt) e[i].to^fa[x][0]&&
			(D[e[i].to]=D[fa[e[i].to][0]=x]+1,Init(e[i].to),0);dO[x]=d;
	}
	int c,o[N+5],vis[N+5],S[N+5],anc[N+5],g[N+5],sum[N+5],tot[N+5];I int Solve(CI x)
	{
		RI i;for(c=0,i=x;i<=n;i+=x) vis[o[++c]=p[i]]=x;sort(o+1,o+c+1,cmp);
		RI t=c,w;for(i=1;i^t;++i) vis[w=LCA(o[i],o[i+1])]^x&&(vis[o[++c]=w]=x);
		RI T=0;for(sort(o+1,o+c+1,cmp),i=1;i<=c;anc[i]=S[T],S[++T]=i++) W(T&&dO[o[S[T]]]<dI[o[i]]) --T;
		for(i=1;i<=c;++i) sum[i]=tot[i]=0;
		for(i=c;i;--i) !(a[o[i]]%x)&&(tot[i]=(tot[i]+phi[a[o[i]]])%X),
			g[i]=(1LL*(D[o[i]]-D[o[anc[i]]])*tot[i]+sum[i])%X,
			sum[anc[i]]=(0LL+sum[anc[i]]+g[i])%X,tot[anc[i]]=(tot[anc[i]]+tot[i])%X;
		for(t=0,i=1;i<=c;!(a[o[i]]%x)&&(t=(1LL*phi[a[o[i]]]*sum[i]+t)%X),++i)
			anc[i]&&(sum[i]=(1LL*(D[o[i]]-D[o[anc[i]]])*(tot[1]-tot[i]+X)+(sum[anc[i]]-g[i]+X)+sum[i])%X);
		return t;
	}
}
int main()
{
	RI i,j,x,y;for(F.read(n),Sieve(),i=1;i<=n;++i) F.read(a[i]),p[a[i]]=i;
	for(i=1;i^n;++i) F.read(x),F.read(y),add(x,y),add(y,x);VTree::Init();
	for(i=n;i;--i) for(f[i]=VTree::Solve(i),j=2*i;j<=n;j+=i) f[i]=(f[i]-f[j]+X)%X;
	RI t=0;for(i=1;i<=n;++i) t=(1LL*i*QP(phi[i],X-2)%X*f[i]+t)%X;
	return printf("%d\n",1LL*t*QP(1LL*n*(n-1)%X,X-2)%X),0;
}