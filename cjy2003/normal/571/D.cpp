#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
namespace t1
{
	vector<int>tm[500050];
	vector<long long>sum[500050];
	long long cur[500050];
	int siz[500050],f[500050],t[500050];
	void init(){for(int i=1;i<=n;++i)siz[i]=1;}
	inline int find(int x)
	{
		while(f[x])x=f[x];
		return x;
	}
	inline void merge(int x,int y,int ti)
	{
		x=find(x),y=find(y);
		if(siz[x]<siz[y])swap(x,y);
		siz[x]+=siz[y];f[y]=x;t[y]=ti;
	}	
	inline void add(int x,int ti)
	{
		x=find(x);
		cur[x]+=siz[x];
		tm[x].push_back(ti);
		sum[x].push_back(cur[x]);
	}
	inline long long query(int x,int ti)
	{
		long long res=0;
		int p;
		while(x)
		{
			p=lower_bound(tm[x].begin(),tm[x].end(),ti)-tm[x].begin()-1;
			res+=cur[x];
			if(p>=0)res-=sum[x][p];
			ti=max(ti,t[x]);x=f[x];
		}
		return res;
	}
}
namespace t2
{
	int siz[500050],f[500050],t[500050],w[500050];
	void init(){for(int i=1;i<=n;++i)siz[i]=1;}
	inline int find(int x)
	{
		while(f[x])x=f[x];
		return x;
	}
	inline void merge(int x,int y,int ti)
	{
		x=find(x),y=find(y);
		if(siz[x]<siz[y])swap(x,y);
		siz[x]+=siz[y];f[y]=x;t[y]=ti;
	}	
	inline void add(int x,int ti)
	{
		x=find(x);
		w[x]=ti;
	}
	inline int query(int x)
	{
		int res=0,bt=0;
		while(x)
		{
			if(bt<w[x])res=max(res,w[x]);
			bt=max(bt,t[x]);
			x=f[x];
		}
		return res;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	t1::init();t2::init();
	char c;
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf(" %c",&c);
		if(c=='U'||c=='M')scanf("%d %d",&x,&y);
		else scanf("%d",&x);
		if(c=='U')t1::merge(x,y,i);
		else if(c=='M')t2::merge(x,y,i);
		else if(c=='A')t1::add(x,i);
		else if(c=='Z')t2::add(x,i);
		else printf("%lld\n",t1::query(x,t2::query(x)));
	}
	return 0;
}