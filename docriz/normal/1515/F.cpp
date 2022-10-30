#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
struct node
{
	ll x,y;
	node(ll nx=0,ll ny=0){x=nx;y=ny;}
	bool operator<(const node&z)const
	{
		return y>z.y||(y==z.y&&x<z.x);
	}
};
map<node,int>mp;
set<node>st[300005];
set<node>nd;
set<node>::iterator it,it2;
int dsu[300005],n,m,x,y;
ll k,al=0,a[300005];
vector<int>ans;
int getf(int p){return dsu[p]==p?p:dsu[p]=getf(dsu[p]);}
void mrg(int x,int y)
{
	set<node>::iterator it;
	if(st[x].size()>st[y].size())swap(x,y);
	dsu[x]=y;
	for(it=st[x].begin();it!=st[x].end();it++)
	{
		int v=(*it).y,x=(*it).x;
		if(getf(v)!=y)st[y].insert(node(x,v));
		else st[y].erase(node(v,x));
	}
	st[x].clear();
	nd.erase(node(x,a[x]));
	nd.erase(node(y,a[y]));
	a[y]+=a[x]-k;
	nd.insert(node(y,a[y]));
}
int main()
{
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		al+=a[i];
		nd.insert(node(i,a[i]));
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		int fx=getf(x),fy=getf(y);
		if(fx==fy)continue;
		dsu[fx]=fy;
		st[x].insert(node(x,y));
		st[y].insert(node(y,x));
		mp[node(min(x,y),max(x,y))]=i;
	}
	for(int i=1;i<=n;i++)dsu[i]=i;
	if(al<k*(n-1))
	{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		it=nd.begin();
		it2=st[(*it).x].begin();
		//printf("#%d %d\n",(*it2).x,(*it2).y);
		ans.push_back(mp[node(min((*it2).x,(*it2).y),max((*it2).x,(*it2).y))]);
		mrg((*it).x,getf((*it2).y));
	}
	printf("YES\n");
	for(int i=0;i<n-1;i++)printf("%d\n",ans[i]);
	return 0;
}