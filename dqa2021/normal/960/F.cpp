//based on input order

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
const int MAXW=100000;

int n,m; int dp[100010];
struct Rec{
	int u,v,w;
}rec[100010];
#define mid (l+r>>1)
struct Node{
	int lson,rson,val;
}node[100000*18+10];
int idtot,rt[100010];
void ins(int &cur,int l,int r,int pos,int val)
{
	if (!cur) cur=++idtot;
	node[cur].val=max(node[cur].val,val);
	if (l==r) return/* node[cur].val=max(node[cur].val,val),void()*/;
	if (pos<=mid) ins(node[cur].lson,l,mid,pos,val);
	else ins(node[cur].rson,mid+1,r,pos,val);
	//node[cur].val=max(node[node[cur].lson].val,node[node[cur].rson].val);
}
int query(int cur,int l,int r,int ql,int qr)
{
	if (!cur) return 0;
	if (l==ql&&r==qr) return node[cur].val;
	if (qr<=mid) return query(node[cur].lson,l,mid,ql,qr);
	//if (ql>mid) return query(node[cur].rson,mid+1,r,ql,qr);
	return max(query(node[cur].lson,l,mid,ql,mid),query(node[cur].rson,mid+1,r,mid+1,qr));
}
#undef mid
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("B.out","w",stdout);
	
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		rec[i].u=read(),rec[i].v=read(),rec[i].w=read();
		if (!rec[i].w) dp[i]=1;
		else dp[i]=query(rt[rec[i].u],0,MAXW,0,rec[i].w-1)+1;
		ins(rt[rec[i].v],0,MAXW,rec[i].w,dp[i]);
		dp[0]=max(dp[0],dp[i]);
		//printf("dp %d = %d\n",i,dp[i]);
	}
	printf("%d\n",dp[0]);
	return 0;
}