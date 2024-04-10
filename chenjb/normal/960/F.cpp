#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n, m, tot, ans, root[210000];
struct node
{
	int l,r,max;
}tree[2000010];

void insert(int &t,int l,int r,int p,int k)
{
	if (!t)tree[++tot]=tree[t],t=tot;
	if (l==r)
	{
		tree[t].max=max(tree[t].max,k);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid)insert(tree[t].l,l,mid,p,k);
	else insert(tree[t].r,mid+1,r,p,k);
	tree[t].max=max(tree[tree[t].l].max,tree[tree[t].r].max);
}

int getmax(int t, int l, int r, int a, int b)
{
	if (!t) return 0;
	if (a<=l && r<=b) return tree[t].max;
	int mid=(l+r)/2;
	int ans=0;
	if (a<=mid) ans= max(ans, getmax(tree[t].l, l, mid, a, b));
	if (b>mid)  ans= max(ans, getmax(tree[t].r, mid + 1, r, a, b));
	return ans;
}
struct EDGE 
{
	int x,y,w;
}edge[110000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
	for(int i=1;i<=m;i++)
	{
		int u=edge[i].x;
		int v=edge[i].y;
		int w=edge[i].w;
		if (!w)
		{
			insert(root[v],0,100000,0,1);
			ans=max(ans,1);
			continue;
		}
		int ff = getmax(root[u], 0, 100000, 0, w - 1) + 1;
		ans = max(ans,ff);
		insert(root[v],0,100000,w,ff);
	}
	cout<<ans<<endl;
	return 0;
}