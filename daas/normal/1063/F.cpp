#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,dp[MAXN],ans,las=1,cnt=1,mem[MAXN];
char s[MAXN];
struct SAM
{
	int ch[26],fa,len;
}sam[MAXN*2];
void sam_in(int c)
{
	int p=las,np=las=++cnt;
	sam[np].len=sam[p].len+1;
	while(p && !sam[p].ch[c])
	{
		sam[p].ch[c]=np;
		p=sam[p].fa;
	}
	if(!p) sam[np].fa=1;
	else
	{
		int q=sam[p].ch[c];
		if(sam[q].len==sam[p].len+1) sam[np].fa=q;
		else
		{
			int nq=++cnt;
			sam[nq]=sam[q];
			sam[nq].len=sam[p].len+1;
			sam[np].fa=sam[q].fa=nq;
			while(p && sam[p].ch[c]==q)
			{
				sam[p].ch[c]=nq;
				p=sam[p].fa;
			}
		}
	}
}
struct node
{
	int head[MAXN*2],tot;
	int to[MAXN*2],nextn[MAXN*2];
	void ADD(int u,int v)
	{
		to[++tot]=v,nextn[tot]=head[u];
		head[u]=tot;
	}
}Ed;
int dfn[MAXN*2],tim,size[MAXN*2],deep[MAXN*2],jump[MAXN*2][25];
void format(int u,int fa)
{
	dfn[u]=++tim;
	size[u]=1;
	deep[u]=deep[fa]+1;
	int LOG=log2(deep[u]);
	jump[u][0]=fa;
	for(int i=1;i<=LOG;++i) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=Ed.head[u];i!=0;i=Ed.nextn[i])
	{
		int v=Ed.to[i];
		format(v,u);
		size[u]+=size[v];
	}
}
int tree[MAXN*8];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void xg(int l,int r,int zone,int v,int x)
{
	if(l==r)
	{
		tree[x]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(zone<=mid) xg(l,mid,zone,v,ls(x));
	else xg(mid+1,r,zone,v,rs(x));
	tree[x]=max(tree[ls(x)],tree[rs(x)]);
}
int cx(int l,int r,int L,int R,int x)
{
	if(L<=l && r<=R) return tree[x];
	int mid=(l+r)>>1,bck=0;
	if(L<=mid) bck=cx(l,mid,L,R,ls(x));
	if(mid<R) bck=max(bck,cx(mid+1,r,L,R,rs(x)));
	return bck;
}
int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=n;i>=1;--i) sam_in(s[i]-'a'),mem[i]=las;
	for(int i=2;i<=cnt;++i) Ed.ADD(sam[i].fa,i);
	format(1,0);
	for(int i=n,cur=n+1;i>=1;--i)
	{
		dp[i]=dp[i+1]+1;
		int x1=mem[i],x2=mem[i+1];
		while(dp[i]!=1)
		{
			int LOG1=log2(deep[x1]);
			for(int j=LOG1;j>=0;--j) if(sam[jump[x1][j]].len>=dp[i]-1) x1=jump[x1][j];
			int LOG2=log2(deep[x2]);
			for(int j=LOG2;j>=0;--j) if(sam[jump[x2][j]].len>=dp[i]-1) x2=jump[x2][j];
			while(cur-1>=1 && cur-1>=i+dp[i])
			{
				--cur;
				xg(1,tim,dfn[mem[cur]],dp[cur],1);
			}
			if(cx(1,tim,dfn[x1],dfn[x1]+size[x1]-1,1)>=dp[i]-1) break;
			if(cx(1,tim,dfn[x2],dfn[x2]+size[x2]-1,1)>=dp[i]-1) break;
			--dp[i];
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
//ore no turn,draw!