#include<cstdio>
#define N 400010
#include<algorithm>
using namespace std;
namespace seg{
	#define mid ((l+r)>>1)
	int ls[N<<6],rs[N<<6],cnt,L,R;
	int merge(int l,int r,int x,int y)
	{
		if(!x||!y) return x+y;
		int now=++cnt;
		ls[now]=merge(l,mid,ls[x],ls[y]);
		rs[now]=merge(mid+1,r,rs[x],rs[y]);
		return now;
	}
	void modify(int l,int r,int&now,int w)
	{
		if(!now) now=++cnt;
		if(l==r) return;
		if(w<=mid) modify(l,mid,ls[now],w);
		else modify(mid+1,r,rs[now],w);	
	}
	int query(int l,int r,int now)
	{
		if(l>R||r<L||now==0) return 0;
		if(L<=l&&r<=R) return 1;
		return query(l,mid,ls[now])|query(mid+1,r,rs[now]);
	}
}
struct edge{
	int next,to;
}e[N];
struct node{
	int ch[27],len,fa,pos;
};
int first[N],len,n,rt[N];
void add(int a,int b)
{
	e[++len]=(edge){first[a],b};
	first[a]=len;
}
namespace sam{
	node tr[N];
	int cnt,now,p,q,ans,f[N],lst[N];
	void init(){now=cnt=0,tr[0].fa=-1;}
	void insert(int c,int x)
	{
		p=now;
		tr[now=++cnt].pos=x;
		tr[now].len=tr[p].len+1; 
		while(p!=-1&&!tr[p].ch[c])
			tr[p].ch[c]=now,p=tr[p].fa;
		if(p>=0)
		{
			q=tr[p].ch[c];
			if(tr[q].len==tr[p].len+1) tr[now].fa=q;
			else
			{
				tr[++cnt]=tr[q];
				tr[cnt].len=tr[p].len+1;
				tr[q].fa=tr[now].fa=cnt;
				while(p!=-1&&tr[p].ch[c]==q)
					tr[p].ch[c]=cnt,p=tr[p].fa;
			}
		}
	}
	void dfs(int x)
	{
		if(tr[x].pos) seg::modify(1,n,rt[x],tr[x].pos);
		for(int i=first[x];i;i=e[i].next)
		{
			dfs(e[i].to);
			rt[x]=seg::merge(1,n,rt[x],rt[e[i].to]);
		}
	}
	void dfs2(int x)
	{
		if(f[x]>ans) ans=f[x];
		for(int i=first[x],y;i;i=e[i].next)
		{
			y=e[i].to;
			seg::L=tr[y].pos-tr[y].len+tr[lst[x]].len;
			seg::R=tr[y].pos-1;
			if(seg::query(1,n,rt[lst[x]])) f[y]=f[x]+1,lst[y]=y;
			else f[y]=f[x],lst[y]=lst[x];
			dfs2(e[i].to);
		}
	}
	void build()
	{
		for(int i=1;i<=cnt;i++) add(tr[i].fa,i);
		dfs(0);
		for(int i=first[0];i;i=e[i].next)
		{
			lst[e[i].to]=e[i].to;
			f[e[i].to]=1;
			dfs2(e[i].to);
		}
	}
}
char str[N];
int main()
{
	scanf("%d%s",&n,str+1);
	sam::init();
	for(int i=1;i<=n;i++) sam::insert(str[i]-'a',i);
	sam::build();
	printf("%d",sam::ans);
}