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
const int MAXN=2e5+10;
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
int T,n,m,sum[MAXN*2],inv[MAXN*2];
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
inline int C(int n,int m) {return (n<0 || m<0 || n<m)?0:(ll)sum[n]*inv[m]%mod*inv[n-m]%mod;}
int pcnt,root;
struct fhq_treap
{
	int l,r,size,val,Key,tag;
}tree[MAXN];
#define ls(x) (tree[x].l)
#define rs(x) (tree[x].r)
int NEW(int val)
{
	++pcnt;
	tree[pcnt].l=tree[pcnt].r=tree[pcnt].tag=0;
	tree[pcnt].size=1;
	tree[pcnt].val=val;
	tree[pcnt].Key=rand();
	return pcnt;
}
void Plus(int x,int val)
{
	tree[x].val+=val;
	tree[x].tag+=val;
}
void down(int x)
{
	if(tree[x].tag)
	{
		if(ls(x)) Plus(ls(x),tree[x].tag);
		if(rs(x)) Plus(rs(x),tree[x].tag);
		tree[x].tag=0;
	}
}
void up(int x) {tree[x].size=tree[ls(x)].size+tree[rs(x)].size+1;}
int merge(int x,int y)
{
	if(!x || !y) return x|y;
	int bck;
	if(tree[x].Key<tree[y].Key)
	{
		bck=x;
		down(x);
		tree[bck].r=merge(tree[x].r,y);
	}
	else
	{
		bck=y;
		down(y);
		tree[bck].l=merge(x,tree[y].l);
	}
	up(bck);
	return bck;
}
void split(int x,int val,int &lx,int &rx)
{
	if(!x) {lx=rx=0;return;}
	down(x);
	if(tree[x].val<val)
	{
		lx=x;
		split(rs(x),val,rs(lx),rx);
		up(x);
	}
	else
	{
		rx=x;
		split(ls(x),val,lx,ls(rx));
		up(x);
	}
}
void split_s(int x,int k,int &lx,int &rx)
{
	if(!x) {lx=rx=0;return;}
	down(x);
	if(tree[ls(x)].size<k)
	{
		k-=tree[ls(x)].size+1;
		lx=x;
		split_s(rs(x),k,rs(lx),rx);
		up(x);
	}
	else
	{
		rx=x;
		split_s(ls(x),k,lx,ls(rx));
		up(x);
	}
}
int main()
{
	srand(time(NULL));
	sum[0]=inv[0]=1;
	for(int i=1;i<=400000;++i) sum[i]=(ll)sum[i-1]*i%mod;
	inv[400000]=ksm(sum[400000],mod-2);
	for(int i=399999;i>=1;--i) inv[i]=(ll)inv[i+1]*(i+1)%mod;
	T=read();
	while(T--)
	{
		n=read(),m=read();
		root=pcnt=0;
		for(int i=1;i<=m;++i)
		{
			int x=read(),y=read();
			int X,Y,Z;
			split(root,y,X,Y);
			int NN=NEW(y);
			Plus(Y,1);
			if(tree[X].size)
			{
				split_s(X,tree[X].size-1,X,Z);
				if(tree[Z].val==y-1) root=merge(merge(X,NN),Y);
				else root=merge(merge(X,Z),merge(NN,Y));
			}
			else root=merge(NN,Y);
		}
		int K=tree[root].size;
		//cout<<K<<endl;
		int ans=0;
		for(int i=0;i<=K;++i)
		{
			int val=(ll)C(K,i)*C(n+n-i-1,n-1)%mod;
			//cout<<"?? "<<i<<" "<<val<<endl;
			if(i&1) ans=MOD(ans-val);
			else ans=MOD(ans+val-mod);
		}
		cout<<ans<<endl;
	}
	return 0;
}
//ore no turn,draw!