#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}
typedef long long ll;

int n;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
#define mid (l+r>>1)
struct Node{
	int lson,rson,maxnum;
	ll maxtot;
}node[18*100000+10];
int rt[100010],idtot,stk[18*100000+10];
int newnode()
{
	if (*stk) return stk[(*stk)--];
	return ++idtot;
}
void update(int &cur,int l,int r,int pos,int val)
{
	if (!cur) cur=newnode(),node[cur]=(Node){0,0,0,0};
	if (l==r) return node[cur].maxnum+=val,node[cur].maxtot=l,void();
	if (pos<=mid) update(node[cur].lson,l,mid,pos,val);
	else update(node[cur].rson,mid+1,r,pos,val);
	if (node[node[cur].lson].maxnum==node[node[cur].rson].maxnum)
		node[cur].maxnum=node[node[cur].lson].maxnum,
		node[cur].maxtot=node[node[cur].lson].maxtot+node[node[cur].rson].maxtot;
	else if (node[node[cur].lson].maxnum<node[node[cur].rson].maxnum)
		node[cur].maxnum=node[node[cur].rson].maxnum,
		node[cur].maxtot=node[node[cur].rson].maxtot;
	else node[cur].maxnum=node[node[cur].lson].maxnum,
		 node[cur].maxtot=node[node[cur].lson].maxtot;
}
int rec[100010][2],rectop;   //rectop=0 initly
void segdfs(int cur,int l,int r)   //segdfs not dfs
{
	if (!cur) return; stk[++*stk]=cur;
	if (l==r) return rec[++rectop][0]=l,rec[rectop][1]=node[cur].maxnum,void();
	segdfs(node[cur].lson,l,mid); segdfs(node[cur].rson,mid+1,r);
}
#undef mid
int siz[100010];
ll ans[100010];
void dfs(int cur,int fat)
{
	siz[cur]=1;
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to!=fat)
		{
			dfs(edge[i].to,cur);
			if (siz[cur]<siz[edge[i].to])
			{
				rectop=0;
				segdfs(rt[cur],1,n);
				for (int j=1;j<=rectop;j++) update(rt[edge[i].to],1,n,rec[j][0],rec[j][1]);
				rt[cur]=rt[edge[i].to];
			}
			else
			{
				rectop=0;
				segdfs(rt[edge[i].to],1,n);
				for (int j=1;j<=rectop;j++) update(rt[cur],1,n,rec[j][0],rec[j][1]);
			}
			siz[cur]+=siz[edge[i].to];
		}
	ans[cur]=node[rt[cur]].maxtot;
}

int main()
{
	read(n);
	for (int i=1,x;i<=n;i++)
	{
		read(x);
		update(rt[i],1,n,x,1);
	}
	for (int i=2,x,y;i<=n;i++)
	{
		read(x);read(y); addedge(x,y);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) printf("%I64d",ans[i]),putchar(i==n?'\n':' ');
	return 0;
}