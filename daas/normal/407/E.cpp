#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<map>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,d,ans,ansl,ansr,a[MAXN],v[MAXN],pre[MAXN],z[2][MAXN],top[2];
map<int,int> Q;
struct seg_tree
{
	int minn,tag;
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void up(int x) {tree[x].minn=min(tree[ls(x)].minn,tree[rs(x)].minn);}
void change(int x,int val)
{
	tree[x].minn+=val;
	tree[x].tag+=val;
}
void down(int x)
{
	if(tree[x].tag)
	{
		change(ls(x),tree[x].tag);
		change(rs(x),tree[x].tag);
		tree[x].tag=0;
	}
}
void xg(int l,int r,int L,int R,int val,int x)
{
	if(L<=l && r<=R) {change(x,val);return;}
	int mid=(l+r)>>1;
	down(x);
	if(L<=mid) xg(l,mid,L,R,val,ls(x));
	if(mid<R) xg(mid+1,r,L,R,val,rs(x));
	up(x);
}
void touch(int l,int r,int zone,int x)
{
	if(l==r) {tree[x].minn=-K;return;}
	int mid=(l+r)>>1;
	down(x);
	if(zone<=mid) touch(l,mid,zone,ls(x));
	else touch(mid+1,r,zone,rs(x));
	up(x);
}
int cx(int l,int r,int L,int R,int x)
{
	if(tree[x].minn>0) return -1;
	if(l==r) return l;
	int mid=(l+r)>>1;
	down(x);
	if(R<=mid) return cx(l,mid,L,R,ls(x));
	if(mid<L) return cx(mid+1,r,L,R,rs(x));
	int bck=cx(l,mid,L,R,ls(x));
	if(bck==-1) return cx(mid+1,r,L,R,rs(x));
	else return bck;
}
void solve(int st,int N)
{
	Q.clear();
	top[0]=top[1]=0;
	int las=0;
	for(int i=1;i<=N;++i)
	{
		if(i!=1) xg(1,N,1,i-1,-1,1);
		while(top[0] && v[z[0][top[0]]]<v[i])
		{
			xg(1,N,z[0][top[0]-1]+1,z[0][top[0]],v[i]-v[z[0][top[0]]],1);
			--top[0];
		}
		z[0][++top[0]]=i;
		while(top[1] && v[z[1][top[1]]]>v[i])
		{
			xg(1,N,z[1][top[1]-1]+1,z[1][top[1]],-(v[i]-v[z[1][top[1]]]),1);
			--top[1];
		}
		z[1][++top[1]]=i;
		touch(1,N,i,1);
		pre[i]=Q[v[i]];
		Q[v[i]]=i;
		las=max(las,pre[i]);
		int x=cx(1,N,las+1,i,1);
		if(i-x+1>ans) ans=i-x+1,ansl=x+st,ansr=i+st;
		else if(i-x+1==ans && x+st<ansl) ansl=x+st,ansr=i+st;
	}
}
int main()
{
	n=read(),K=read(),d=read();
	for(int i=1;i<=n;++i) a[i]=read();
	if(!d)
	{
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && a[r+1]==a[r]) ++r;
			if(r-l+1>ans) ans=r-l+1,ansl=l,ansr=r;
		}
		printf("%d %d\n",ansl,ansr);
		return 0;
	}
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r+1<=n && (a[r+1]%d+d)%d==(a[r]%d+d)%d) ++r;
		int N=0,R=(a[r]%d+d)%d;
		for(int i=l;i<=r;++i) v[++N]=(a[i]-R)/d;
		solve(l-1,N);
	}
	/*int N=0,R=(a[ansl]%d+d)%d;
	for(int i=ansl;i<=ansr;++i) if((a[i]%d+d)%d!=R) cerr<<"cao";
	for(int i=ansl;i<=ansr;++i) v[++N]=(a[i]+R)/d;
	sort(v+1,v+N+1);
	for(int i=2;i<=N;++i) if(v[i]==v[i-1]) cerr<<"cao";
	cerr<<v[N]-v[1]<<" "<<N-1<<" "<<K<<" "<<ans<<" "<<v[1]<<" "<<v[N]<<endl;*/
	printf("%d %d\n",ansl,ansr);
	return 0;
}
//ore no turn,draw!