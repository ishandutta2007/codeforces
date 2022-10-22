#include<cstdio>
using namespace std;
const int mod=998244353,N=1e6+10;
inline int Mod(int a){return a<mod?a:a-mod;}
struct my_queue{
	int head,tail,q[N];
	int top(){return q[head++];}
	int size(){return tail-head;}
	void push(int x){q[tail++]=x;}
}q;
struct edge{
	int next,to;
}e[N];
int first[N],len,deg[N],t[N];
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len,deg[b]++;
}
int T,n,m,a[N];
void work(int x)
{
	a[x]--;
	for(int i=first[x];i;i=e[i].next)
		a[e[i].to]++;
}
int solve()
{
	int x,y;
	for(int i=1;i<=n;i++)
	{
		len=0;
		for(int j=1;j<=n;j++)
			if(a[j]>0) t[++len]=j;
		if(len==0) return i-1;
		for(int j=1;j<=len;j++) work(t[j]);
	}
	for(int i=1;i<=n;i++) a[i]=Mod(a[i]);
	for(int i=1;i<=n;i++)
		if(!deg[i]) q.push(i);
	while(q.size())
	{
		x=q.top();
		for(int i=first[x];i;i=e[i].next)
		{
			y=e[i].to,a[y]=Mod(a[y]+a[x]);
			if(!--deg[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!first[i]) return Mod(a[i]+n);
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&n,&m);
		len=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&x,&y),add(x,y);
		printf("%d\n",solve());
		for(int i=1;i<=n;i++)
			first[i]=deg[i]=0;
	}
}