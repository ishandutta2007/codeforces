#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int siz=300;
struct query
{
	int x,k,id,op;
	friend bool operator < (query a,query b){return a.x<b.x;}
}q[200020];
struct tree
{
	vector<int>E[100010];
	int id[100010],idnum,dy[100010],siz[100010],f[100010];
	void dfs(int v)
	{
		dy[id[v]=++idnum]=v,siz[v]=1;
		for(auto u:E[v])dfs(u),siz[v]+=siz[u];	
	}
}trie,fail;
int n,qnum,ch[100010][26],tot=1,pos[100010],bg[100010],len[100010];
int bl[100010],cnt[100010][350],bw[350],st[350],ed[350],bnum,bw1[350],w[100010];
char s[100010];
long long ans[100010];
int ins(char a[],int l)
{
	int u=1,c;
	for(int i=1;i<=l;++i)
	{
		c=a[i]-'a';
		if(!ch[u][c])ch[u][c]=++tot;
		u=ch[u][c];
	}
	return u;
}
void build()
{
	for(int i=1;i<=tot;++i)
		for(int j=0;j<26;++j)
			if(ch[i][j])trie.E[i].push_back(ch[i][j]);
	trie.dfs(1);
	queue<int>d;d.push(1);
	for(int i=0;i<26;++i)ch[0][i]=1;
	int x;
	while(!d.empty())
	{
		x=d.front();d.pop();
		for(int i=0;i<26;++i)
			if(ch[x][i])fail.f[ch[x][i]]=ch[fail.f[x]][i],d.push(ch[x][i]);
			else ch[x][i]=ch[fail.f[x]][i];
	}
	for(int i=2;i<=tot;++i)fail.E[fail.f[i]].push_back(i);
	fail.dfs(1);
	int u,c;
	for(int i=1;i<=n;++i)
	{
		u=1;
		for(int j=1;j<=len[i];++j)
		{
			c=s[bg[i]+j]-'a';
			u=ch[u][c];
			++cnt[i][bl[fail.id[u]]];
		}
	}
}
inline void work1(int p)
{
	int x=trie.id[p],y=trie.id[p]+trie.siz[p];
//	printf("%d\n",p);
	++w[x],--w[y];++bw1[bl[x]],--bw1[bl[y]];
}
void work(int p)
{
	int x=fail.id[p],y=fail.id[p]+fail.siz[p]-1,l=bl[x],r=bl[y];
	if(l==r)
	{
		for(int i=x;i<=y;++i)work1(fail.dy[i]);
	}
	else
	{
		for(int i=x;i<=ed[l];++i)work1(fail.dy[i]);
		for(int i=st[r];i<=y;++i)work1(fail.dy[i]);
		for(int i=l+1;i<r;++i)++bw[i];
	}
}
long long qry(int k)
{
	long long res=0;
	for(int i=1;i<=bnum;++i)res+=1ll*cnt[k][i]*bw[i];
	int x=trie.id[pos[k]];
	for(int i=1;i*siz<=x;++i)res+=bw1[i];
	for(int i=x/siz*siz+1;i<=x;++i)res+=w[i];
	return res;
}
int main()
{
	scanf("%d %d",&n,&qnum);
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+sum+1);
		len[i]=strlen(s+sum+1);
		bg[i]=sum;
		pos[i]=ins(s+sum,len[i]);
		sum+=len[i];
	}
	for(int i=1;i<=tot;i+=siz)
	{
		st[++bnum]=i,ed[bnum]=min(i+siz-1,tot);
		for(int j=st[bnum];j<=ed[bnum];++j)bl[j]=bnum;
	}
	build();
	int x,y,k;
	for(int i=1;i<=qnum;++i)
	{
		scanf("%d %d %d",&x,&y,&k);
		q[2*i-1]=query{y,k,i,1};
		q[2*i]=query{x-1,k,i,-1};
	}
	sort(q+1,q+1+2*qnum);
	int last=1;
	while(!q[last].x)++last;
	for(int i=1;i<=n;++i)
	{
		work(pos[i]);
		while(q[last].x==i)ans[q[last].id]+=q[last].op*qry(q[last].k),++last;
	}
	for(int i=1;i<=qnum;++i)printf("%lld\n",ans[i]);
	return 0;
}