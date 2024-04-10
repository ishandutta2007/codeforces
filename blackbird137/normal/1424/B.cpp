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

const int N=20005,M=1e5+5;
int n,m,l,r,ans=-1,du[N];

struct Edge
{
	int u,v,w,ne;
}e[M*2];
int head[N],tot;

inline void add(int u,int v,int w);
inline bool check(int x);

signed main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read()+n,w=read();
		add(u,v,w);add(v,u,w);r=max(r,w);
	}
	int l=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){u,v,w,head[u]};
	head[u]=tot;
}

inline bool check(int x)
{
	queue<int> qu;
	memset(du,0,sizeof(du));
	for(int i=1;i<=tot;i+=2)
		if(e[i].w<=x)
		{
			du[e[i].u]++;
			du[e[i].v]++;
		}
	for(int i=1;i<=(n<<1);++i)
		if(du[i]==0) return 0;
	return 1;
}