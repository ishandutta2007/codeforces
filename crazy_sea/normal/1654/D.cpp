#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
const int N=2e5+10,mod=998244353;
struct edge{
	int next,to,x,y;
}e[N<<1];
ll s,s1,ans;
int first[N],len,f[N],t[N],t1[N],fa[N],vis[N];
void add(int a,int b,int x,int y)
{
	e[++len]=edge{first[a],b,x,y};
	first[a]=len;
}
struct node{
	int x,y;
};
vector<node>v[N];
ll fastpow(ll a,int b)
{
	ll s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod, b>>=1;
	}
	return s;
}
void update(int x)
{
	if(t[x]<t1[x]) s1=s1*fastpow(x,t1[x]-t[x])%mod,t1[x]=t[x];
}
void Add(int x,int f)
{
	for(node a:v[x])
	{
		s=s*fastpow(a.x,(mod-1)+f*a.y)%mod;
		t[a.x]+=a.y*f;
		update(a.x);
	}
}
void clear(int x)
{
	for(node a:v[x]) t[a.x]=t1[a.x]=0;
}
void dfs(int x)
{
	f[x]=s;
	for(int i=first[x],y;i;i=e[i].next)
	{
		if((y=e[i].to)==fa[x]) continue;
		fa[y]=x;
		Add(e[i].y,1);
		Add(e[i].x,-1);
		dfs(y);
		Add(e[i].x,1);
		Add(e[i].y,-1);
	}
}
int calc(int x,int y)
{
	int s=0;
	while(x%y==0) x/=y,s++;
	return s;
}
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int j=i;j<=n;j+=i)
				v[j].push_back((node){i,calc(j,i)}),vis[j]=1;
		}
	}
}
int T,u,x,y,n;
int main()
{
	int v;
	init(2e5);
	scanf("%d",&T);
	while(T--)
	{
		s=s1=1;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d%d",&u,&v,&x,&y);
			add(u,v,x,y), add(v,u,y,x);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
		{
			ans=(ans+s1*f[i])%mod;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=len;i++) clear(e[i].x);
		for(int i=1;i<=n;i++) first[i]=0;
		ans=len=0;
	}
}