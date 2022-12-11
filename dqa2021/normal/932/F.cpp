#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
const int Base=1e5,MAXW=2e5;   //caution seg ranges!!!
typedef long long ll;
const ll INF=0x7fffffffffffffffLL;

int n,a[100010],b[100010];
ll dp[100010];
struct Rec{
	ll b;  //dp
	int k;  //b
}rec[100010];
ll getval(int id,int pos)
{
	pos-=Base;
	return 1LL*pos*rec[id].k+rec[id].b;
}
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
#define mid (l+r>>1)
struct Node{
	int lson,rson,id;
}node[100010];  //enough?
int idtot,rt[100010];
void update(int &cur,int l,int r,int y)
{
	if (!cur) return node[cur=y]=(Node){0,0,node[y].id},void();
	//if (l==r) return node[cur].id=node[getval(node[cur].id,l)>getval(node[y].id,l)?y:cur].id,void();
	if (getval(node[cur].id,l)>=getval(node[y].id,l)&&getval(node[cur].id,r)>=getval(node[y].id,r))
		return node[cur].id=node[y].id,void();
	if (getval(node[cur].id,l)<=getval(node[y].id,l)&&getval(node[cur].id,r)<=getval(node[y].id,r))
		return;
	int &a=node[cur].id,&b=node[y].id;
	if (rec[a].k<rec[b].k)
		if (getval(a,mid)>getval(b,mid)) swap(a,b),update(node[cur].rson,mid+1,r,y);  //4
		else update(node[cur].lson,l,mid,y);  //3
	else
		if (getval(a,mid)>getval(b,mid)) swap(a,b),update(node[cur].lson,l,mid,y);  //1
		else update(node[cur].rson,mid+1,r,y); //2
}
int merge(int x,int y,int l,int r)
{
	if (!x||!y) return x|y;
	if (l==r) return getval(node[x].id,l)>getval(node[y].id,l)?y:x;
	node[x].lson=merge(node[x].lson,node[y].lson,l,mid);
	node[x].rson=merge(node[x].rson,node[y].rson,mid+1,r);
	update(x,l,r,y);
	return x;
}
ll query(int cur,int l,int r,int pos)
{
	if (!cur) return INF;
	ll res=getval(node[cur].id,pos);
	if (l==r) return res;
	if (pos<=mid) return min(res,query(node[cur].lson,l,mid,pos));
	return min(res,query(node[cur].rson,mid+1,r,pos));
}
#undef mid
void dfs(int cur,int fat)
{
	for (int i=last[cur];i;i=edge[i].nxt)
		if (edge[i].to^fat)
			dfs(edge[i].to,cur),rt[cur]=merge(rt[cur],rt[edge[i].to],0,MAXW);
	if (rt[cur]) dp[cur]=query(rt[cur],0,MAXW,a[cur]+Base);
	rec[cur]=(Rec){dp[cur],b[cur]};
	node[++idtot]=(Node){0,0,cur};
	update(rt[cur],0,MAXW,idtot);
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);

	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=2;i<=n;i++) addedge(read(),read());
	dfs(1,0);
	for (int i=1;i<=n;i++) printf("%I64d ",dp[i]); putchar('\n');  //caution I64d!!!
	return 0;
}