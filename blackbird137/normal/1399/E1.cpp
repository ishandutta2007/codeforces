#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int t,n,s,ans,all;

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

struct Node
{
	int x,y;
	bool operator < (const Node &A)const
	{
		return x*y-x*(y/2)<A.x*A.y-A.x*(A.y/2);
	}
};

priority_queue<Node> sum;

inline void add(int u,int v,int w);
int dfs(int u,int fa);

signed main()
{
	t=read();
	while(t--)
	{
		tot=ans=all=0;
		memset(head,0,sizeof(head));
		n=read();s=read();
		for(int i=1;i<=n-1;++i)
		{
			int u=read(),v=read(),w=read();
			add(u,v,w);add(v,u,w);
		}
		dfs(1,0);
		while(all>s)
		{
			Node tmp=sum.top();
			sum.pop();
			all-=tmp.x*tmp.y-tmp.x*(tmp.y/2);
			sum.push((Node){tmp.x,tmp.y/2});
			ans++;
		}
		printf("%lld\n",ans);
		while(!sum.empty()) sum.pop();
	}
	return 0;
}

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

int dfs(int u,int fa)
{
	int res=0,flag=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		flag=0;
		int tmp=dfs(v,u);
		all+=tmp*e[i].w;
		sum.push((Node){tmp,e[i].w});
		res+=tmp;
	}
	return res+flag;
}