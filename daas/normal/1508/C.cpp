#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<set>
#define int long long
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
int n,m,val,father[MAXN],Father[MAXN],pd[MAXN],dl[MAXN],h,t,size[MAXN],del[MAXN],ans;
set<int> res,node[MAXN];
struct data
{
	int u,v,l;
	bool operator <(const data &Z)const {return l<Z.l;}
}Q[MAXN];
int find(int k){return father[k]==k?k:father[k]=find(father[k]);}
int Find(int k){return Father[k]==k?k:Father[k]=Find(Father[k]);}
void bfs(int S)
{
	h=t=0;
	dl[++t]=S;
	res.erase(S);
	while(h!=t)
	{
		int u=dl[++h];
		Father[u]=S;
		for(set<int> :: iterator i=res.begin();i!=res.end();)
		{
			int v=(*i);
			++i;
			if(node[u].find(v)==node[u].end())
			{
				res.erase(v);
				dl[++t]=v;
			}
		}
	}
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) res.insert(i),father[i]=i;
	for(int i=1;i<=m;++i)
	{
		Q[i].u=read(),Q[i].v=read(),Q[i].l=read();
		node[Q[i].u].insert(Q[i].v);
		node[Q[i].v].insert(Q[i].u);
		val^=Q[i].l;
	}
	for(int i=1;i<=n;++i) if(!Father[i]) bfs(i);
	for(int i=1;i<=n;++i) ++size[Father[i]];
	for(int i=1;i<=m;++i) if(Father[Q[i].u]==Father[Q[i].v]) ++del[Father[Q[i].u]];
	for(int i=1;i<=n;++i) if(Father[i]==i && size[i]<=size[i]*(size[i]-1)/2-del[i]) val=0;
	sort(Q+1,Q+m+1);
	for(int i=1;i<=m;++i)
	{
		int au=Find(Q[i].u),av=Find(Q[i].v);
		if(au==av) pd[i]=1;
		else
		{
			Father[au]=av;
			father[find(Q[i].u)]=find(Q[i].v);
			ans+=Q[i].l;
		}
	}
	for(int i=1;i<=m;++i) if(pd[i] && find(Q[i].u)!=find(Q[i].v)) val=min(val,Q[i].l);
	printf("%lld\n",ans+val);
	return 0;
}