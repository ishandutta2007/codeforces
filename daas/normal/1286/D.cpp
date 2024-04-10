#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
#define double long double
using namespace std;
const int MAXN=1e5+10;
const int mod=998244353;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,x[MAXN],v[MAXN],p[MAXN],ANS;
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y&1) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return z;
}
const double eps=1e-11;
int geq(double x,double y) {return fabs(x-y)<eps || x>y;}
int les(double x,double y) {return fabs(x-y)>eps && x<y;}
//-----
int cnt;
struct quest
{
	double t;
	int val,lx,rx;
	double llim,rlim;
	quest(double _t=0,int _val=0,int _lx=0,double _llim=0,int _rx=0,double _rlim=0) {t=_t,val=_val,lx=_lx,llim=_llim,rx=_rx,rlim=_rlim;}
	bool operator <(const quest &Z) const {return t<Z.t;}
}Q[MAXN*2];
int tot;
struct Exchange
{
	double t;
	int ver,k;
	Exchange(double _t=0,int _ver=0,int _k=0) {t=_t,ver=_ver,k=_k;}
	bool operator <(const Exchange &Z) const {return t<Z.t;}
}EEE[MAXN*60];
//----------------------------------------------------------------
/*
int vis_pre[MAXN][2],pre[MAXN][2];
int f_pre(int k,int type)
{
	if(!k) return 1;
	if(vis_pre[k][type]) return pre[k][type];
	vis_pre[k][type]=1;
	double lim=(type?x[k+1]+v[k+1]*tim:x[k+1]-v[k+1]*tim);
	int bck=0;
	if(les(x[k]+v[k]*tim,lim)) bck=MOD(bck+(ll)p[k]*f_pre(k-1,1)%mod-mod);
	if(les(x[k]-v[k]*tim,lim)) bck=MOD(bck+(ll)MOD(1-p[k])*f_pre(k-1,0)%mod-mod);
	return pre[k][type]=bck;
}
int vis_suf[MAXN][2],suf[MAXN][2];
int f_suf(int k,int type)
{
	if(k==n+1) return 1;
	if(vis_suf[k][type]) return suf[k][type];
	vis_suf[k][type]=1;
	double lim=(type?x[k-1]+v[k-1]*tim:x[k-1]-v[k-1]*tim);
	int bck=0;
	if(geq(x[k]+v[k]*tim,lim)) bck=MOD(bck+(ll)p[k]*f_suf(k+1,1)%mod-mod);
	if(geq(x[k]-v[k]*tim,lim)) bck=MOD(bck+(ll)MOD(1-p[k])*f_suf(k+1,0)%mod-mod);
	return suf[k][type]=bck;
}
*/
//----------------------------------------------------------------
double tim;
struct matrix
{
	int n,m,A[2][2];
	matrix operator *(const matrix &Z) const
	{
		matrix bck;
		bck.n=n,bck.m=Z.m;
		memset(bck.A,0,sizeof(bck.A));
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<Z.m;++k)
					bck.A[i][k]=MOD(bck.A[i][k]+(ll)A[i][j]*Z.A[j][k]%mod-mod);
		return bck;
	}
}tree[2][MAXN*4],ans;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void up(int x,int ver)
{
	if(!ver) tree[ver][x]=tree[ver][ls(x)]*tree[ver][rs(x)];
	else tree[ver][x]=tree[ver][rs(x)]*tree[ver][ls(x)];
}
void init(int X,int ver,int k)
{
	tree[ver][X].n=tree[ver][X].m=2;
	if(!ver)
	{
		for(int type=0;type<2;++type)
		{
			double lim=(type?x[k+1]+v[k+1]*tim:x[k+1]-v[k+1]*tim);
			if(les(x[k]+v[k]*tim,lim)) tree[ver][X].A[1][type]=p[k];
			else tree[ver][X].A[1][type]=0;
			if(les(x[k]-v[k]*tim,lim)) tree[ver][X].A[0][type]=MOD(1-p[k]);
			else tree[ver][X].A[0][type]=0;
		}
	}
	else
	{
		for(int type=0;type<2;++type)
		{
			double lim=(type?x[k-1]+v[k-1]*tim:x[k-1]-v[k-1]*tim);
			if(geq(x[k]+v[k]*tim,lim)) tree[ver][X].A[1][type]=p[k];
			else tree[ver][X].A[1][type]=0;
			if(geq(x[k]-v[k]*tim,lim)) tree[ver][X].A[0][type]=MOD(1-p[k]);
			else tree[ver][X].A[0][type]=0;
		}
	}
}
void build(int l,int r,int x,int ver)
{
	if(l==r) {init(x,ver,l);return;}
	int mid=(l+r)>>1;
	build(l,mid,ls(x),ver);
	build(mid+1,r,rs(x),ver);
	up(x,ver);
}
void xg(int l,int r,int zone,int x,int ver)
{
	if(l==r) {init(x,ver,l);return;}
	int mid=(l+r)>>1;
	if(zone<=mid) xg(l,mid,zone,ls(x),ver);
	else xg(mid+1,r,zone,rs(x),ver);
	up(x,ver);
}
void cx(int l,int r,int L,int R,int x,int ver)
{
	if(ans.A[0][1]==0 && ans.A[0][0]==0) return;
	if(L<=l && r<=R) {ans=ans*tree[ver][x];return;}
	int mid=(l+r)>>1;
	if(R<=mid) {cx(l,mid,L,R,ls(x),ver);return;}
	if(mid<L) {cx(mid+1,r,L,R,rs(x),ver);return;}
	if(!ver) {cx(l,mid,L,R,ls(x),ver); cx(mid+1,r,L,R,rs(x),ver);}
	else {cx(mid+1,r,L,R,rs(x),ver); cx(l,mid,L,R,ls(x),ver);}
}
int calc_pre(int k,double lim)
{
	if(!k) return 1;
	int bck=0;
	ans.n=1,ans.m=2;
	ans.A[0][0]=ans.A[0][1]=1;
	if(k!=1) cx(1,n,1,k-1,1,0);
	if(les(x[k]+v[k]*tim,lim)) bck=MOD(bck+(ll)p[k]*ans.A[0][1]%mod-mod);
	if(les(x[k]-v[k]*tim,lim)) bck=MOD(bck+(ll)MOD(1-p[k])*ans.A[0][0]%mod-mod);
	return bck;
}
int calc_suf(int k,double lim)
{
	if(k==n+1) return 1;
	int bck=0;
	ans.n=1,ans.m=2;
	ans.A[0][0]=ans.A[0][1]=1;
	if(k!=n) cx(1,n,k+1,n,1,1);
	if(geq(x[k]+v[k]*tim,lim)) bck=MOD(bck+(ll)p[k]*ans.A[0][1]%mod-mod);
	if(geq(x[k]-v[k]*tim,lim)) bck=MOD(bck+(ll)MOD(1-p[k])*ans.A[0][0]%mod-mod);
	return bck;
}
//const double Eps=1e-9;
void ADD(double t,int a,int b)
{
	EEE[++tot]=Exchange(t-3*eps,0,a);
	EEE[++tot]=Exchange(t+3*eps,0,a);
	EEE[++tot]=Exchange(t-3*eps,1,b);
	EEE[++tot]=Exchange(t+3*eps,1,b);
	return;
	for(int i=-3;i<=3;++i)
	{
		EEE[++tot]=Exchange(t+i*eps,0,a);
		EEE[++tot]=Exchange(t+i*eps,1,b);
	}
}
int pd[MAXN][2];
int main()
{
	//cerr<<(double)(sizeof(Q)+sizeof(EEE)+sizeof(tree))/1024/1024<<endl;
	n=read();
	for(int i=1;i<=n;++i) x[i]=read(),v[i]=read(),p[i]=(ll)read()*ksm(100,mod-2)%mod;
	for(int i=1;i<n;++i)
	{
		double t=(double)(x[i+1]-x[i])/(v[i]+v[i+1]);
		Q[++cnt]=quest(t,(ll)(x[i+1]-x[i])%mod*ksm(v[i]+v[i+1],mod-2)%mod*p[i]%mod*MOD(1-p[i+1])%mod,i-1,x[i]+v[i]*t,i+2,x[i+1]-v[i+1]*t);
		if(v[i]!=v[i+1])
		{
			t=(double)(x[i+1]-x[i])/fabs(v[i]-v[i+1]);
			if(v[i]>v[i+1])
			{
				Q[++cnt]=quest(t,(ll)(x[i+1]-x[i])%mod*ksm(v[i]-v[i+1],mod-2)%mod*p[i]%mod*p[i+1]%mod,i-1,x[i]+v[i]*t,i+2,x[i+1]+v[i+1]*t);
			}
			else
			{
				Q[++cnt]=quest(t,(ll)(x[i+1]-x[i])%mod*ksm(v[i+1]-v[i],mod-2)%mod*MOD(1-p[i])%mod*MOD(1-p[i+1])%mod,i-1,x[i]-v[i]*t,i+2,x[i+1]-v[i+1]*t);
			}
		}
	}
	for(int i=1;i<n;++i)
	{
		int a=i,b=i+1;
		//-----------
		if(v[a]!=v[b])
		{
			double t=(double)(x[a]-x[b])/(v[b]-v[a]);
			ADD(t,a,b);
		}
		//-----------
		{
			double t=(double)(x[a]-x[b])/(v[a]+v[b]);
			ADD(t,a,b);
		}
		//-----------
		{
			double t=(double)(x[b]-x[a])/(v[a]+v[b]);
			ADD(t,a,b);
		}
		//-----------
		if(v[a]!=v[b])
		{
			double t=(double)(x[a]-x[b])/(v[a]-v[b]);
			ADD(t,a,b);
		}
	}
	sort(EEE+1,EEE+tot+1);
	sort(Q+1,Q+cnt+1);
	tim=-10;
	build(1,n,1,0);
	build(1,n,1,1);
	//cerr<<endl;
	for(int i=1,cur=0;i<=cnt;++i)
	{
		tim=Q[i].t;
		while(cur+1<=tot && geq(Q[i].t,EEE[cur+1].t))
		{
			++cur;
			if(pd[EEE[cur].k][EEE[cur].ver]==i) continue;
			pd[EEE[cur].k][EEE[cur].ver]=i;
			xg(1,n,EEE[cur].k,1,EEE[cur].ver);
		}
		ANS=MOD(ANS+(ll)Q[i].val*calc_pre(Q[i].lx,Q[i].llim)%mod*calc_suf(Q[i].rx,Q[i].rlim)%mod-mod);
	}
	printf("%d\n",ANS);
	return 0;
}
//ore no turn,draw!