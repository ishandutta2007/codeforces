#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#define M 100000
const int w=30;
using namespace std;
struct node
{
	int x,y;
	node(const int &_x=0,const int &_y=0):x(_x),y(_y) {}
	inline void read() {scanf("%d %d",&x,&y);}
	inline bool operator==(const node &_b) const
	{
		return x==_b.x && y==_b.y; 
	}
	inline bool operator!=(const node &_b) const
	{
		return x!=_b.x || y!=_b.y;
	}
	inline int deep() const {return x+y;}
	inline bool operator<(const node &_b) const
	{
		for(int i=w-1;i>=0;--i)
			if(((x>>i)&1)!=((_b.x>>i)&1) || ((y>>i)&1)!=((_b.y>>i)&1))
			{
				if((x>>i)&1) for(int j=i;j>=0;--j)
					{if((_b.y>>j)&1) return 1;}
				else if((y>>i)&1) break;
				else
				{
					if((_b.x>>i)&1) for(int j=i;j>=0;--j)
						if((y>>j)&1) return 0;
					return 1;
				}
				break;
			}
		return 0;
	}
	inline node operator^(node b) const
	{
		node ret,a=*this;
		for(int i=w-1;i>=0;--i)
			if(((a.x>>i)&1)!=((b.x>>i)&1) || ((a.y>>i)&1)!=((b.y>>i)&1))
			{
				if((a.x>>i)&1) (a.x|=(1<<i)-1)^=1<<i,(a.y|=(1<<i)-1)^=(1<<i)-1;
				else if((a.y>>i)&1) (a.y|=(1<<i)-1)^=1<<i,(a.x|=(1<<i)-1)^=(1<<i)-1;
				if((b.x>>i)&1) (b.x|=(1<<i)-1)^=1<<i,(b.y|=(1<<i)-1)^=(1<<i)-1;
				else if((b.y>>i)&1) (b.y|=(1<<i)-1)^=1<<i,(b.x|=(1<<i)-1)^=(1<<i)-1;
			}
		return a;
	}
}t[M*9+5],a[M+5],b[M+5];
vector<int> e[M*9+5];
int m,cnt=1,fa[M*9+5],sum[M*9+5],ans,sum2[M*9+5];
map<node,int> num;
map<int,bool> mp;
void dfs(int x)
{
	sum[x]+=sum2[x];
	for(int y:e[x]) dfs(y),sum[x]+=sum[y];
	if(sum[x])
	{
		mp[t[x].deep()]^=1;
		if(fa[x]) mp[t[fa[x]].deep()]^=1;
	}
	else if(sum2[x]<0) mp[t[x].deep()]^=1,t[x].deep() && (mp[t[x].deep()-1]^=1,1);
}
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		a[i].read(),b[i].read();
		t[++cnt]=a[i],t[++cnt]=b[i];
	}
	sort(t+1,t+1+cnt),cnt=unique(t+1,t+1+cnt)-t-1;
	for(int i=cnt;i>1;--i) t[++cnt]=t[i]^t[i-1];
	sort(t+1,t+1+cnt),cnt=unique(t+1,t+1+cnt)-t-1;
	for(int i=1;i<=cnt;++i) num[t[i]]=i;
	for(int i=cnt;i>1;--i) e[fa[i]=num[t[i]^t[i-1]]].push_back(i);
	for(int i=1;i<=m;++i) ++sum[num[a[i]]],++sum[num[b[i]]],sum2[num[a[i]^b[i]]]-=2;
	dfs(1);map<int,bool>::iterator it=mp.begin();
	for(;it!=mp.end();++it) ans+=it->second;
	printf("%d",ans);
	return 0;
}