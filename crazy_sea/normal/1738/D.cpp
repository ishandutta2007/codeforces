#include<cstdio>
#include<vector>
using namespace std;
const int N=1e6+10;
int n,T,k,a[N],first[N],len,cnt,x,deg[N];
struct edge{
	int next,to;
}e[N];
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len,deg[a]++;
}
struct my_queue{
	int head,tail,q[N];
	void push(int x){q[tail++]=x;}
	int size(){return tail-head;}
	int top(){return q[head++];} 
}q;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>i) k=i;
			add(x,i);
		}
		q.push(0),q.push(n+1);
		while(q.size())
		{
			x=q.top();
			for(int i=first[x];i;i=e[i].next)
				if(deg[e[i].to]==0) a[++cnt]=e[i].to;
			for(int i=first[x];i;i=e[i].next)
				if(deg[e[i].to]!=0)
					a[++cnt]=e[i].to,q.push(e[i].to);
		}
		printf("%d\n",k);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		cnt=len=k=q.head=q.tail=0;
		for(int i=0;i<=n+1;i++) first[i]=deg[i]=0;
	}
}