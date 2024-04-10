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
using namespace std;
const int MAXN=1e5+10;
const int mod=1e9+7;
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
int n,q,C[10][10];
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
int tree[6][MAXN*4],lazy[6][MAXN*4],sum[6][MAXN*4],a[MAXN];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void build(int l,int r,int x)
{
	if(l==r)
	{
		sum[0][x]=1;
		for(int i=1;i<=5;++i) sum[i][x]=(ll)sum[i-1][x]*l%mod;
		for(int i=0;i<=5;++i) tree[i][x]=(ll)a[l]*sum[i][x]%mod;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
	for(int i=0;i<=5;++i)
	{
		sum[i][x]=MOD(sum[i][ls(x)]+sum[i][rs(x)]-mod);
		tree[i][x]=MOD(tree[i][ls(x)]+tree[i][rs(x)]-mod);
	}
}
void up(int x,int ver) {tree[ver][x]=MOD(tree[ver][ls(x)]+tree[ver][rs(x)]-mod);}
void change(int x,int ver,int val)
{
	lazy[ver][x]=val;
	tree[ver][x]=(ll)val*sum[ver][x]%mod;
}
void down(int x,int ver)
{
	if(lazy[ver][x]==-1) return;
	change(ls(x),ver,lazy[ver][x]);
	change(rs(x),ver,lazy[ver][x]);
	lazy[ver][x]=-1;
}
void xg(int l,int r,int L,int R,int val,int x,int ver)
{
	if(L<=l && r<=R)
	{
		change(x,ver,val);
		return;
	}
	int mid=(l+r)>>1;
	down(x,ver);
	if(L<=mid) xg(l,mid,L,R,val,ls(x),ver);
	if(mid<R) xg(mid+1,r,L,R,val,rs(x),ver);
	up(x,ver);
}
int cx(int l,int r,int L,int R,int x,int ver)
{
	if(L<=l && r<=R) return tree[ver][x];
	int mid=(l+r)>>1,bck=0;
	down(x,ver);
	if(L<=mid) bck=cx(l,mid,L,R,ls(x),ver);
	if(mid<R) bck=MOD(bck+cx(mid+1,r,L,R,rs(x),ver)-mod);
	return bck;
}
int main()
{
	for(int i=0;i<=5;++i) C[i][0]=C[i][i]=1;
	for(int i=2;i<=5;++i)
		for(int j=1;j<i;++j)
			C[i][j]=MOD(C[i-1][j]+C[i-1][j-1]-mod);
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	memset(lazy,-1,sizeof(lazy));
	build(1,n,1);
	while(q--)
	{
		char s[5]; scanf("%s",s);
		if(s[0]=='?')
		{
			int l=read(),r=read(),K=read(),ans=0;
			for(int j=0;j<=K;++j)
			{
				int val=(ll)C[K][j]*ksm(MOD(1-l),K-j)%mod;
				ans=MOD(ans+(ll)val*cx(1,n,l,r,1,j)%mod-mod);
			}
			printf("%d\n",ans);
		}
		else
		{
			int l=read(),r=read(),val=read();
			for(int i=0;i<=5;++i) xg(1,n,l,r,val,1,i);
		}
	}
	return 0;
}
//ore no turn,draw!