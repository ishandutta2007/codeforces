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
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int Test,n,m,a[MAXN],num[MAXN],pos[MAXN];
vector<int> mem[MAXN],tmp[MAXN];
struct seg_tree
{
	int tag;
}tree[MAXN*4];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void build(int l,int r,int x)
{
	tree[x].tag=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,ls(x));
	build(mid+1,r,rs(x));
}
void down(int x)
{
	if(tree[x].tag)
	{
		tree[ls(x)].tag=max(tree[ls(x)].tag,tree[x].tag);
		tree[rs(x)].tag=max(tree[rs(x)].tag,tree[x].tag);
		tree[x].tag=0;
	}
}
void xg(int l,int r,int L,int R,int val,int x)
{
	if(L<=l && r<=R) {tree[x].tag=max(tree[x].tag,val);return;}
	int mid=(l+r)>>1;
	down(x);
	if(L<=mid) xg(l,mid,L,R,val,ls(x));
	if(mid<R) xg(mid+1,r,L,R,val,rs(x));
}
int cx(int l,int r,int zone,int x)
{
	if(l==r) return tree[x].tag;
	int mid=(l+r)>>1;
	down(x);
	if(zone<=mid) return cx(l,mid,zone,ls(x));
	else return cx(mid+1,r,zone,rs(x));
}
#include<set>
multiset<int> T;
int main()
{
	Test=read();
	while(Test--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i) num[i]=a[i]=read();
		sort(num+1,num+n+1);
		for(int i=1;i<=n;++i) a[i]=lower_bound(num+1,num+n+1,a[i])-num;
		for(int i=1;i<=n;++i) mem[i].clear(),mem[i].push_back(0),tmp[i].clear();
		for(int i=1;i<=n;++i) pos[i]=mem[a[i]].size(),mem[a[i]].push_back(i);
		build(1,n,1);
		for(int i=1;i<=m;++i)
		{
			int l=read(),r=read();
			xg(1,n,l,r,r,1);
		}
		T.clear();
		int lim=n;
		for(int i=1;i<=n;++i)
		{
			int val=cx(1,n,i,1);
			if(!val) continue;
			int id=a[i];
			int x=upper_bound(mem[id].begin(),mem[id].end(),val)-mem[id].begin()-1;
			if(pos[i]+1<(int)mem[id].size() && mem[id][pos[i]+1]<=val) lim=min(lim,mem[id][pos[i]+1]);
			x=mem[id][x];
			if(i!=x) tmp[i].push_back(x),T.insert(i);
		}
		//cout<<"cao\n";
		if(T.empty()) {puts("0");continue;}
		//cout<<"nmd\n";
		int ans=n;
		for(int i=1;i<=lim;++i)
		{
			auto it=T.end(); --it;
			ans=min(ans,*it-i+1);
			for(int j=0;j<(int)tmp[i].size();++j)
			{
				T.erase(T.lower_bound(i));
				T.insert(tmp[i][j]);
			}
		}
		printf("%d\n",ans);
		//for(int i=1;i<=cnt;++i) cout<<i<<" "<<cnt<<endl;
	}
	return 0;
}
//ore no turn,draw!