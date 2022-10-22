#include<cstdio>
#include<cstring>
#define N 1000010
#define nxt sam::tr[x].ch[c]
using namespace std;
struct node{
	int ch[27],len,fa;
};
struct node2{
	int s,w;
}a;
node2 max(node2 a,node2 b)
{
	if(a.s==b.s) return a.w<b.w?a:b;
	else return a.s>b.s?a:b;
}
namespace seg
{
	#define mid ((l+r)>>1)
	int ls[N*20],rs[N*20],L,R,cnt;
	node2 tr[N*20];
	void update(int x){tr[x]=max(tr[ls[x]],tr[rs[x]]);}
	void modify(int l,int r,int&now,int w)
	{
		if(!now) now=++cnt;
		if(l==r){tr[now].s++,tr[now].w=l;return;}
		if(w<=mid) modify(l,mid,ls[now],w);
		else modify(mid+1,r,rs[now],w);
		update(now);
	}
	int merge(int l,int r,int x,int y)
	{
		if(!x||!y) return x|y;
		int now=++cnt;
		if(l==r){tr[now].s=tr[x].s+tr[y].s,tr[now].w=l;return now;}
		ls[now]=merge(l,mid,ls[x],ls[y]);
		rs[now]=merge(mid+1,r,rs[x],rs[y]);
		update(now);
		return now;
	}
	node2 query(int l,int r,int now)
	{
		if(l>R||r<L||!now) return (node2){0,0};
		if(L<=l&&r<=R) return tr[now];
		return max(query(l,mid,ls[now]),query(mid+1,r,rs[now]));
	}
}
struct edge{
	int next,to;
}e[N];
int lca[N][22],first[N],len,rt[N],n,m;
void add(int a,int b)
{
	e[++len].to=b;
	e[len].next=first[a];
	first[a]=len;
}
namespace sam
{
	int cnt,now,q;
	node tr[N];
	void init(){tr[0].fa=-1,now=cnt=0;}
	int insert(int c,int p)
	{
		tr[now=++cnt].len=tr[p].len+1;
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
		return now;
	}
	void dfs(int x)
	{
		if(x) for(int i=1;i<=20;i++) lca[x][i]=lca[lca[x][i-1]][i-1];
		for(int i=first[x];i;i=e[i].next)
		{
			lca[e[i].to][0]=x;
			dfs(e[i].to);
			rt[x]=seg::merge(1,m,rt[x],rt[e[i].to]);
		}
	}
	void build()
	{
		for(int i=1;i<=cnt;i++) add(tr[i].fa,i);
		dfs(0);
	}
	int jump(int x,int len)
	{
		for(int i=20;i>=0;i--)
			if(tr[lca[x][i]].len>=len) x=lca[x][i];
		return x;
	}
}
char s[N],str[N];
int w[N],l,r,T,maxlen[N];
int main()
{
	scanf("%s%d",s+1,&m);
	sam::init();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",str+1);
		len=strlen(str+1);
		for(int j=1,lst=0;j<=len;j++)
			lst=sam::insert(str[j]-'a',lst),
			seg::modify(1,m,rt[lst],i);
	}
	len=0;
	sam::build();
	n=strlen(s+1);
	int x=0;
	for(int i=1,c;i<=n;i++)
	{
		c=s[i]-'a';
		if(nxt) maxlen[i]=maxlen[i-1]+1,x=nxt;
		else
		{
			while(x!=-1&&!nxt) x=sam::tr[x].fa;
			if(x<0) maxlen[i]=0,x=0;
			else maxlen[i]=sam::tr[x].len+1,x=nxt;
		}
		w[i]=x;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&seg::L,&seg::R,&l,&r);
		if(maxlen[r]<r-l+1){printf("%d 0\n",seg::L);continue;}
		a=seg::query(1,m,rt[sam::jump(w[r],r-l+1)]);
		if(a.s==0) printf("%d 0\n",seg::L);
		else printf("%d %d\n",a.w,a.s);
	}
}