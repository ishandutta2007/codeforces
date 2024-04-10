#include<cstdio>
#include<vector>
using namespace std;
const int N=5e5+10;
struct edge{
	int next,to;
}e[N<<2];
int first[N],vis[N],len,t[N],p,k;
vector<int>v[N];
void add(int a,int b)
{
	e[++len]=(edge){first[a],b};
	first[a]=len;
}
void dfs(int x)
{
	if(p) return;
	vis[x]=1;
	t[++len]=x;
	v[len].push_back(x);
	if(len>=k)
	{
		printf("PATH\n%d\n",len);
		for(int i=1;i<=len;i++) printf("%d ",t[i]);
		printf("\n");
		p=1;
	}
	for(int i=first[x];i;i=e[i].next)
		if(!vis[e[i].to]) dfs(e[i].to);
	len--;
}
int n,m,x,y,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;i++)
			v[i].clear(),first[i]=vis[i]=0;
		p=len=0;
		scanf("%d%d",&n,&m);
		k=n/2+(n&1);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&x,&y),add(x,y),add(y,x);
		len=0,dfs(1);
		if(p) continue;
		printf("PAIRING\n");
		for(int i=1;i<=n;i++) len+=v[i].size()/2;
		printf("%d\n",len);
		for(int i=1;i<=n;i++)
			for(int j=0;j+1<v[i].size();j+=2)
				printf("%d %d\n",v[i][j],v[i][j+1]);
	}
}