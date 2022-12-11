#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,qnum,len[200020],tot,p[200020],ch[200020][26],cnt=1,fail[200020],id[200020],idnum,siz[200020],ed[200020],ans[500050];
char s[200020];
vector<int>E[200020];
int ins(char *a,int l)
{
	int u=1,c;
	for(int i=1;i<=l;++i)
	{
		c=a[i]-'a';
		if(!ch[u][c])ch[u][c]=++cnt;
		u=ch[u][c];
	}
	return u;
}
void dfs(int v)
{
	id[v]=++idnum;siz[v]=1;
	for(auto u:E[v])dfs(u),siz[v]+=siz[u];
}
void build()
{
	for(int i=0;i<26;++i)ch[0][i]=1;
	queue<int>q;
	q.push(1);
	int x,y;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(int i=0;i<26;++i)
			if(ch[x][i])fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
	}
	for(int i=2;i<=cnt;++i)E[fail[i]].push_back(i);
	dfs(1);
}
struct qry
{
	int x,y,id,op;
	friend bool operator < (qry a,qry b){return a.x<b.x;}
}q[1000010];
int sum[200020];
inline void add(int p,int w)
{
	while(p<=cnt)sum[p]+=w,p+=p&-p;
}
inline int query(int p)
{
	int s=0;
	while(p)s+=sum[p],p-=p&-p;
	return s;
}
void solve(char *a,int l)
{
	int u=1,c;
	for(int i=1;i<=l;++i)
	{
		c=a[i]-'a';
		u=ch[u][c];
		add(id[u],1);
	}
}
int main()
{
	scanf("%d %d",&n,&qnum);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+tot+1);
		len[i]=strlen(s+tot+1);
		p[i]=tot;
		ed[i]=ins(s+tot,len[i]);
		tot+=len[i];
	}
	build();
	int x,y,k;
	for(int i=1;i<=qnum;++i)
	{
		scanf("%d %d %d",&x,&y,&k);
		q[i*2-1]=qry{x-1,ed[k],i,-1};
		q[i*2]=qry{y,ed[k],i,1};
	}
	sort(q+1,q+1+2*qnum);
//	for(int i=1;i<=2*qnum;++i)printf("%d %d %d %d\n",q[i].x,q[i].y,q[i].id,q[i].op);
	int last=1;
	while(!q[last].x)++last;
	for(int i=1;i<=n;++i)
	{
//		printf("%d:",i);
		solve(s+p[i],len[i]);
//		printf("\n");
		while(q[last].x==i)ans[q[last].id]+=q[last].op*(query(id[q[last].y]+siz[q[last].y]-1)-query(id[q[last].y]-1)),++last;
	}
	for(int i=1;i<=qnum;++i)printf("%d\n",ans[i]);
	return 0;
}