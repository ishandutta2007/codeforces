#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=1e9+7,inv2=Mod+1>>1;
int pw2[500100];

int n,m; int deg[500010];
int f[500010];
int find(int x)
{
	return f[x]?f[x]=find(f[x]):x;
}

struct Edge{
	int to,nxt;
}edge[1000010];
int cnt=1,last[500010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[500010],dep[500010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (v=edge[i].to,(v^fat)) dfs1(v,cur,dep+1);
}

struct Rec{
	int x,y,siz;
}rec[500010]; int rectop;

int A[500010],B[500010];

int _n,_m,_h,nn,mm,hh,nm,nh,mh; int hht;
int nn1,nn2,mm1,mm2,mm3,hh1,hh2,hh3,nm1,nm2,nh1,nh2,mh1,mh2,mh3;

int sqr(int x)
{
	return 1LL*x*x%Mod;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read(),m=read();
	pw2[0]=1; for (int i=1;i<=n+50;i++) pw2[i]=1LL*pw2[i-1]*inv2%Mod;
	for (int i=1,x,y,u,v;i<=m;i++)
	{
		x=read(),y=read(); deg[x]++,deg[y]++;
		u=find(x),v=find(y);
		if (u==v) rec[++rectop]=(Rec){x,y,1};
		else f[u]=v,addedge(x,y);
	}
	dfs1(1,0,1);
	for (int i=1,u,v;i<=rectop;i++)
	{
		u=rec[i].x,v=rec[i].y;
		while (u^v)
		{
			if (dep[u]<dep[v]) v=fat[v];
			else u=fat[u];
			rec[i].siz++;
		}
		u=rec[i].x,v=rec[i].y;
		while (u^v)
		{
			if (dep[u]<dep[v]) swap(u,v);
			A[u]=(A[u]+1LL*pw2[rec[i].siz]*pw2[rec[i].siz])%Mod;
			B[u]=(B[u]+pw2[rec[i].siz])%Mod;
			u=fat[u];
		}
		A[u]=(A[u]+1LL*pw2[rec[i].siz]*pw2[rec[i].siz])%Mod;
		B[u]=(B[u]+pw2[rec[i].siz])%Mod;
		_h=(_h+pw2[rec[i].siz])%Mod;
		hht=(hht+1LL*pw2[rec[i].siz]*pw2[rec[i].siz])%Mod;
	}
	
	_n=1LL*n*inv2%Mod;
	_m=1LL*pw2[2]*m%Mod;
	
	nn1=_n; nn2=1LL*pw2[2]*n%Mod*(n-1)%Mod; nn=(nn1+nn2)%Mod;
	
	mm3=m; for (int i=1;i<=n;i++) mm2=(mm2+1LL*deg[i]*(deg[i]-1))%Mod; mm1=(1LL*m*(m-1)-mm2)%Mod;
	//printf("mm1 %d mm2 %d mm3 %d\n",(mm1+Mod)%Mod,(mm2+Mod)%Mod,(mm3+Mod)%Mod);
	mm1=1LL*mm1*pw2[4]%Mod,mm2=1LL*mm2*pw2[3]%Mod,mm3=1LL*mm3*pw2[2]%Mod; mm=(0LL+mm1+mm2+mm3)%Mod;
	
	hh1=_h; for (int i=1;i<=n;i++) hh2=(hh2+1LL*B[i]*B[i]-A[i])%Mod; hh3=(1LL*_h*_h-hht-hh2)%Mod;
	hh2=hh2*2%Mod; hh=(0LL+hh1+hh2+hh3)%Mod;
	
	nm2=m*2; nm1=(1LL*n*m-nm2)%Mod; nm2=1LL*nm2*pw2[2]%Mod; nm1=1LL*nm1*pw2[3]%Mod; nm=(nm1+nm2)%Mod;
	
	for (int i=1;i<=rectop;i++)
		nh1=(nh1+1LL*pw2[rec[i].siz]*rec[i].siz)%Mod,
		nh2=(nh2+1LL*pw2[rec[i].siz+1]*(n-rec[i].siz))%Mod;
	nh=(nh1+nh2)%Mod;
	
	for (int i=1,u,v,a,b;i<=rectop;i++)
	{
		mh3=(mh3+1LL*rec[i].siz*pw2[rec[i].siz])%Mod;
		u=rec[i].x,v=rec[i].y;
		a=0;
		while (u^v)
		{
			if (dep[u]<dep[v]) swap(u,v);
			a+=deg[u]-2;
			u=fat[u];
		}
		a+=deg[u]-2;
		b=m-rec[i].siz-a;
		mh2=(mh2+1LL*a*pw2[rec[i].siz+1])%Mod;
		mh1=(mh1+1LL*b*pw2[rec[i].siz+2])%Mod;
	}
	//printf("mh1 %d mh2 %d mh3 %d\n",(mh1+Mod)%Mod,(mh2+Mod)%Mod,(mh3+Mod)%Mod);
	mh=(0LL+mh1+mh2+mh3)%Mod;
	
	//printf("_n %d _m %d _h %d nn %d mm %d hh %d nm %d mh %d nh %d\n",(_n+Mod)%Mod,(_m+Mod)%Mod,(_h+Mod)%Mod,(nn+Mod)%Mod,(mm+Mod)%Mod,(hh+Mod)%Mod,(nm+Mod)%Mod,(mh+Mod)%Mod,(nh+Mod)%Mod);
	int ans=((0LL+nn+mm+hh-2*nm-2*mh+2*nh)-sqr((0LL+_n-_m+_h)%Mod))%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}