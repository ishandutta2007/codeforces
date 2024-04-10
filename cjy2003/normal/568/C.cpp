#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct bian
{
	int nxt,to;
}bi[400000];
char a[30],s[210],ans[210];//C:0,V:1
int l,n,m,head[410],num,dfn[410],low[410],dfnum,st[410],tp,bl[410],cnt,ok[210],cur[210],bj[2];
bool mp[410][410];
vector<int>E[410];
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
void tarjan(int v)
{
	st[++tp]=v;dfn[v]=low[v]=++dfnum;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(!dfn[u])
		{
			tarjan(u);
			low[v]=min(low[v],low[u]);
		}
		else if(!bl[u])low[v]=min(low[v],dfn[u]);
	}
	if(low[v]==dfn[v])
	{
		++cnt;
		while(st[tp]!=v)bl[st[tp]]=cnt,--tp;
		bl[v]=cnt,--tp;
	}
}
void work(int v)
{
//	printf("%d:",v);
	queue<int>q;
	q.push(v);mp[v][v]=1;
	int x;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(auto y:E[x])if(!mp[v][y])/*printf("%d ",y),*/mp[v][y]=1,q.push(y);
	}
//	printf("\n");
}
bool check2(int x,int w)
{
	if((~cur[x]&&cur[x]!=w)||!bj[w])return 0;
	return 1;
}
bool check1(int x)
{
	if(x==n)return 1;
	for(int i=s[x+1]+1;i<l;++i)if(check2(x+1,a[i]))return 1;
	return 0;
}
int main()
{
	scanf("%s",a);l=strlen(a);
	for(int i=0;i<l;++i)a[i]=a[i]=='V'?1:0,bj[a[i]]=1;
	scanf("%d %d",&n,&m);
	memset(cur,-1,sizeof(cur));
	int p1,p2;
	char t1,t2;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %c %d %c",&p1,&t1,&p2,&t2);
		add(p1+n*(t1=='V'),p2+n*(t2=='V'));
		add(p2+n*(t2!='V'),p1+n*(t1!='V'));
	}
	for(int i=1;i<=2*n;++i)if(!dfn[i])tarjan(i);
//	for(int i=1;i<=2*n;++i)printf("%d ",bl[i]);printf("\n");
	for(int i=1;i<=2*n;++i)
		for(int j=head[i];j;j=bi[j].nxt)
			if(bl[i]!=bl[bi[j].to])E[bl[i]].push_back(bl[bi[j].to]);
	for(int i=1;i<=cnt;++i)work(i);
	for(int i=1;i<=n;++i)
	{
		if(bl[i]==bl[i+n])return printf("-1"),0;
		if(mp[bl[i]][bl[i+n]])cur[i]=1;
		if(mp[bl[i+n]][bl[i]])cur[i]=0;
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)s[i]-='a';
	int p=-1;
	for(int i=0;i<=n;++i)
	{
		if(~cur[i]&&cur[i]!=a[s[i]])break;
		if(i)
		{
			int now=i+n*a[s[i]];
			for(int j=i+1;j<=n;++j)
				if(mp[bl[now]][bl[j]])cur[j]=0;
				else if(mp[bl[now]][bl[j+n]])cur[j]=1;
		}
		if(check1(i))p=i;
	}
	if(p<0)return printf("-1"),0;
	memset(cur,-1,sizeof(cur));
	for(int i=1;i<=n;++i)
	{
		if(mp[bl[i]][bl[i+n]])cur[i]=1;
		if(mp[bl[i+n]][bl[i]])cur[i]=0;
	}	
	for(int i=1;i<=p;++i)
	{
		ans[i]=s[i]+'a';
		int now=i+n*a[s[i]];
		for(int j=i+1;j<=n;++j)
			if(mp[bl[now]][bl[j]])cur[j]=0;
			else if(mp[bl[now]][bl[j+n]])cur[j]=1;
	}
	for(int i=p+1;i<=n;++i)
	{
		bool flag=0;
		for(int j=i==p+1?s[i]+1:0;j<l;++j)
			if(check2(i,a[j]))
			{
				flag=1;
				ans[i]=j+'a';
				int now=i+n*a[j];
				for(int k=j+1;k<=n;++k)
					if(mp[bl[now]][bl[k]])cur[k]=0;
					else if(mp[bl[now]][bl[k+n]])cur[k]=1;
				break;
			}
		if(!flag)return printf("-1"),0;
	}
	puts(ans+1);	
	return 0;
}