#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,trie[500001][26],num,father[500001],id[500001],col[500001],cnt,root[1000001],pcnt,zone[500001],mem[500001],head[1000001],tot;
int jump[1000001][23],deep[1000001],dl[500001],h,t,ans1,ans2;
vector<int> Q[500001];
char s[5000001],T[500001];
struct node
{
	int l,r,maxn,maxid;
}tree[16000001];
struct sb
{
	int to,nextn;
}a[1000001];
inline void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
struct data
{
	int len,fa,ch[26];
}sam[1000001];
inline void insert(int k)
{
	scanf("%s",T);
	int len=strlen(T),bj=0;
	for(register int i=0;i<len;++i)
	{
		int c=T[i]-'a';
		if(!trie[bj][c])
			trie[bj][c]=++num,col[num]=c,father[num]=bj;
		bj=trie[bj][c];
		Q[bj].push_back(k);
	}
}
inline int sam_in(int c,int p)
{
	int np=++cnt;
	sam[np].len=sam[p].len+1;
	while(p && !sam[p].ch[c])
	{
		sam[p].ch[c]=np;
		p=sam[p].fa;
	}
	if(!p)
		sam[np].fa=1;
	else
	{
		int q=sam[p].ch[c];
		if(sam[q].len==sam[p].len+1)
			sam[np].fa=q;
		else
		{
			int nq=++cnt;
			sam[nq]=sam[q];
			sam[nq].len=sam[p].len+1;
			sam[q].fa=sam[np].fa=nq;
			while(p && sam[p].ch[c]==q)
			{
				sam[p].ch[c]=nq;
				p=sam[p].fa;
			}
		}
	}
	return np;
}
inline void xg(int l,int r,int zone,int &bj)
{
	if(!bj)
		bj=++pcnt;
	if(l==r)
	{
		tree[bj].maxn+=1;
		tree[bj].maxid=l;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
		xg(l,mid,zone,tree[bj].l);
	else
		xg(mid+1,r,zone,tree[bj].r);
	if(tree[tree[bj].l].maxn>=tree[tree[bj].r].maxn)
		tree[bj].maxn=tree[tree[bj].l].maxn,tree[bj].maxid=tree[tree[bj].l].maxid;
	else
		tree[bj].maxn=tree[tree[bj].r].maxn,tree[bj].maxid=tree[tree[bj].r].maxid;
}
inline void merge(int l,int r,int pre,int &bj)
{
	if(!tree[pre].maxn)
		return;
	if(!tree[bj].maxn)
	{
		bj=pre;
		return;
	}
	int NOW=++pcnt;
	tree[NOW]=tree[bj];
	if(l==r)
	{
		tree[NOW].maxn+=tree[pre].maxn;
		bj=NOW;
		return;
	}
	int mid=(l+r)/2;
	merge(l,mid,tree[pre].l,tree[NOW].l);
	merge(mid+1,r,tree[pre].r,tree[NOW].r);
	if(tree[tree[NOW].l].maxn>=tree[tree[NOW].r].maxn)
		tree[NOW].maxn=tree[tree[NOW].l].maxn,tree[NOW].maxid=tree[tree[NOW].l].maxid;
	else
		tree[NOW].maxn=tree[tree[NOW].r].maxn,tree[NOW].maxid=tree[tree[NOW].r].maxid;
	bj=NOW;
}
inline void cx(int l,int r,int L,int R,int bj)
{
	if(!tree[bj].maxn)
		return;
	if(L<=l && r<=R)
	{
		if(tree[bj].maxn==ans1)
			ans2=min(ans2,tree[bj].maxid);
		if(tree[bj].maxn>ans1)
			ans1=tree[bj].maxn,ans2=tree[bj].maxid;
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid)
		cx(l,mid,L,R,tree[bj].l);
	if(mid<R)
		cx(mid+1,r,L,R,tree[bj].r);
}
inline void fun(int u)
{
	int LOG=log2(deep[u]);
	for(register int i=1;i<=LOG;++i)
		jump[u][i]=jump[jump[u][i-1]][i-1];
	for(register int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		deep[v]=deep[u]+1;
		jump[v][0]=u;
		fun(v);
		merge(1,n,root[v],root[u]);
	}
}
int main()
{
	scanf("%s",s);
	n=read();
	for(register int i=1;i<=n;++i)
		insert(i);
	id[0]=cnt=1;
	for(register int i=0;i<26;++i)
		if(trie[0][i])
			dl[++t]=trie[0][i];
	while(h!=t)
	{
		int u=dl[++h];
		id[u]=sam_in(col[u],id[father[u]]);
		for(register int i=0;i<Q[u].size();++i)
			xg(1,n,Q[u][i],root[id[u]]);
		for(register int i=0;i<26;++i)
			if(trie[u][i])
				dl[++t]=trie[u][i];
	}
	int len=strlen(s),bj=1,meml=0;
	for(register int i=0;i<len;++i)
	{
		while(bj!=1 && !sam[bj].ch[s[i]-'a'])
		{
			bj=sam[bj].fa;
			meml=sam[bj].len;
		}
		if(sam[bj].ch[s[i]-'a'])
			bj=sam[bj].ch[s[i]-'a'],++meml;
		zone[i]=bj;
		mem[i]=meml;
	}
	for(register int i=2;i<=cnt;++i)
		ADD(sam[i].fa,i);
	deep[1]=1;
	fun(1);
	m=read();
	while(m--)
	{
		int l=read(),r=read(),pl=read(),pr=read(),len=pr-pl+1,bj=zone[pr-1];
		if(mem[pr-1]<len)
		{
			printf("%d 0\n",l);
			continue;
		}
		int LOG=log2(deep[bj]);
		for(register int i=LOG;i>=0;--i)
			if(sam[jump[bj][i]].len>=len)
				bj=jump[bj][i];
		ans1=0,ans2=l;
		cx(1,n,l,r,root[bj]);
		printf("%d %d\n",ans2,ans1);
	}
	return 0;
}