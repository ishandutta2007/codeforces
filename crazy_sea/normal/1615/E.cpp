#include<cstdio>
#include<algorithm>
#define ll long long
#define N 200010
using namespace std;
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,dep[N],fa[N],p[N],c[N],a[N];
int k,n,x,y,s;
bool cmp1(int a,int b){return dep[a]>dep[b];}
bool cmp2(int a,int b){return c[a]>c[b];}
ll ans;
void Add(int a,int b)
{
	e[++len]=(edge){first[a],b};
	first[a]=len;
	e[++len]=(edge){first[b],a};
	first[b]=len;
}
void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	for(int i=first[x],y;i;i=e[i].next)
		if((y=e[i].to)!=fa[x]) fa[y]=x,dfs(y);
}
void work(int x)
{
	int y=x;
	while(y&&!p[y]) p[y]=1,y=fa[y],c[x]++;
}
void calc(int x,ll s)
{
	if(x>n/2) x=n/2;
	s-=1ll*x*(n-x);
	if(s>ans) ans=s;
}
int main()
{
	scanf("%d%d",&n,&k);
	ans=-1ll*n*n;
	for(int i=1;i<n;i++) scanf("%d%d",&x,&y),Add(x,y);
	dfs(1);
	for(int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) work(a[i]);
	sort(a+1,a+n+1,cmp2);
	calc(n,0);
	for(int i=1;i<=k;i++) s+=c[a[i]],calc(n-s,1ll*i*(n-i));
	printf("%lld",ans);
}