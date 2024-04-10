#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10,M=6e6+10;
struct node{
	int ch[26],fa,len;
}tr[N];
struct edge{
	int next,to;
}e[N];
int lst,cnt,rt[N],len,n,first[N];
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
}
namespace seg
{
	#define mid ((l+r)>>1)
	int tr[M],ls[M],rs[M],cnt,L,R;
	void update(int now)
	{
		tr[now]=tr[ls[now]]|tr[rs[now]];
	}
	int merge(int x,int y,int l,int r)
	{
		if(l==r) {tr[++cnt]=tr[x]|tr[y];return cnt;}
		if(!x||!y) return x|y;
		int now=++cnt;
		ls[now]=merge(ls[x],ls[y],l,mid);
		rs[now]=merge(rs[x],rs[y],mid+1,r);
		update(now);
		return now;
	}
	int query(int l,int r,int now)
	{
		if(!now||l>R||r<L) return 0;
		if(L<=l&&r<=R) return tr[now];
		return query(l,mid,ls[now])|query(mid+1,r,rs[now]);
	}
	int query(int now,int a,int l,int r)
	{
		L=l,R=r;
		int x=query(1,n,now);
		for(int i=a+1;i<26;i++)
			if(x&(1<<i)) return i;
		return -1;
	}
	void merge(int x,int y,int z)
	{
		rt[x]=merge(rt[y],rt[z],1,n);
	}
	void modify(int l,int r,int&now,int w,int a)
	{
		if(!now) now=++cnt;
		if(l==r){tr[now]=(1<<a);return;}
		if(w<=mid) modify(l,mid,ls[now],w,a);
		else modify(mid+1,r,rs[now],w,a);
		update(now);
	}
}
char str[N],c;
void insert(int a,int w)
{
	int now=++cnt,p=lst,q;lst=now;
	tr[now].len=tr[p].len+1;
	if(w<n) seg::modify(1,n,rt[now],w+1,str[w]-'a');
	while(p!=-1&&!tr[p].ch[a]) tr[p].ch[a]=now,p=tr[p].fa;
	if(p==-1) return;
	q=tr[p].ch[a];
	if(tr[q].len==tr[p].len+1) tr[now].fa=q;
	else
	{
		tr[++cnt]=tr[q];
		tr[cnt].len=tr[p].len+1;
		tr[q].fa=tr[now].fa=cnt;
		while(p!=-1&&tr[p].ch[a]==q) tr[p].ch[a]=cnt,p=tr[p].fa;
	}
}
void init(){tr[0].fa=-1;}
void build()
{
	for(int i=1;i<=cnt;i++) add(tr[i].fa,i);
}
void dfs(int x)
{
	for(int y,i=first[x];i;i=e[i].next)
		y=e[i].to,dfs(y),seg::merge(x,x,y);
}
int Q,l,r,s1,s2,w;
int main()
{
	scanf("%s",str);
	n=strlen(str);
	init();
	for(int i=0;i<n;i++) insert(str[i]-'a',i+1);
	c=str[0];
	scanf("%d",&Q);
	build();
	dfs(0);
	while(Q--)
	{
		scanf("%d%d%s",&l,&r,str);
		int now=0;
		len=strlen(str);
		s1=-1;
		if(l==1&&c>str[0]) s1=0,s2=c-'a';
		for(int i=0;i<len;i++)
		{
			w=seg::query(rt[now],str[i]-'a',l+i,r);
			if(w>=0)
			{
				if(i==0&&s1==0) s2=s2<w?s2:w;
				else s1=i,s2=w;
			}
			now=tr[now].ch[str[i]-'a'];
			if(!now) break;
		}
		if(now)
		{
			w=seg::query(rt[now],-1,l+len,r);
			if(w>=0) s1=len,s2=w;
		}
		if(s1==-1) printf("-1\n");
		else
		{
			for(int i=0;i<s1;i++) printf("%c",str[i]);
			printf("%c\n",s2+'a');
		}
	}
}