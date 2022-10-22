#include<cstdio>
#include<map>
using namespace std;
const int N=1e6+10;
int fa[N];
int getfa(int a)
{
	if(a==fa[a]) return a;
	else return (fa[a]=getfa(fa[a]));
}
void merge(int x)
{
	fa[getfa(x)]=getfa(x+1);
}
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,q[N],t[N],T,l[N],r[N],a[N],b;
long long s[N];
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
}
void push(int x)
{
	if(getfa(x)==x) merge(x),q[++len]=x;
}
void work(int id)
{
	if(++t[id]==2)
	{
		int x=getfa(l[id]);
		while(x<=r[id]) push(x),x=getfa(x);
	}
}
int n,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=0;i<=n+1;i++) fa[i]=i,first[i]=0;
		len=0;
		for(int i=1;i<=n;i++) scanf("%d",&b),a[i]-=b;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			add(l[i]-1,i),add(r[i],i);
			t[i]=0;
		}
		len=0;
		for(int i=0;i<=n;i++)
			if(s[i]==0) push(i);
		while(len)
		{
			int x=q[len--];
			for(int i=first[x];i;i=e[i].next)
				work(e[i].to);
		}
		printf("%s\n",getfa(0)==n+1?"YES":"NO");
	}
}