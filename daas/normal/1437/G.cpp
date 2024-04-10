#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<set>
using namespace std;
int read()
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
int n,m,trie[300010][26],fail[300010],cnt,head[300010],tot,point[300010],value[300010],dl[300010],h,t;
int top[300010],father[300010],size[300010],son[300010],V[300010],id[300010],tim,tree[1200010];
int turev[300010];
char s[300010];
multiset<int> mem[300010];
struct sb
{
	int to,nextn;
}a[300010];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void insert(int id)
{
	int bj=0,len=strlen(s);
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		if(!trie[bj][c])
			trie[bj][c]=++cnt,value[cnt]=-1;
		bj=trie[bj][c];
	}
	turev[id]=0;
	mem[bj].insert(0);
	value[bj]=0;
	point[id]=bj;
}
void fun1(int u)
{
	size[u]=1;
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		father[v]=u;
		fun1(v);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
	}
}
void fun2(int u,int toop)
{
	top[u]=toop,id[u]=++tim,V[tim]=value[u-1];
	if(!son[u])
		return;
	fun2(son[u],toop);
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==son[u])
			continue;
		fun2(v,v);
	}
}
void build(int l,int r,int bj)
{
	if(l==r)
	{
		tree[bj]=V[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,bj*2);
	build(mid+1,r,bj*2+1);
	tree[bj]=max(tree[bj*2],tree[bj*2+1]);
}
void xg(int l,int r,int zone,int v,int bj)
{
	if(l==r)
	{
		tree[bj]=v;
		return;
	}
	int mid=(l+r)/2;
	if(zone<=mid)
		xg(l,mid,zone,v,bj*2);
	else
		xg(mid+1,r,zone,v,bj*2+1);
	tree[bj]=max(tree[bj*2],tree[bj*2+1]);
}
int cx(int l,int r,int L,int R,int bj)
{
	if(L<=l && r<=R)
		return tree[bj];
	int mid=(l+r)/2,bck=-1;
	if(L<=mid)
		bck=cx(l,mid,L,R,bj*2);
	if(mid<R)
		bck=max(bck,cx(mid+1,r,L,R,bj*2+1));
	return bck;
}
int qcx(int x)
{
	int bck=-1;
	while(top[x]!=1)
	{
		bck=max(bck,cx(1,cnt+1,id[top[x]],id[x],1));
		x=father[top[x]];
	}
	bck=max(bck,cx(1,cnt+1,1,id[x],1));
	return bck;
}
int main()
{
	n=read(),m=read();
	value[0]=-1;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		insert(i);
	}
	for(int i=0;i<26;++i)
		if(trie[0][i])
			dl[++t]=trie[0][i];
	while(h!=t)
	{
		int u=dl[++h];
		for(int i=0;i<26;++i)
			if(trie[u][i])
			{
				fail[trie[u][i]]=trie[fail[u]][i];
				dl[++t]=trie[u][i];
			}
			else
				trie[u][i]=trie[fail[u]][i];
	}
	for(int i=1;i<=cnt;++i)
		ADD(fail[i]+1,i+1);
	fun1(1);
	fun2(1,1);
	build(1,cnt+1,1);
	for(int i=1;i<=m;++i)
	{
		int type=read();
		if(type==1)
		{
			int isr=read(),ior=point[isr],v=read();
			multiset<int> :: iterator ID=mem[ior].end();
			--ID;
			int NV=(*ID);
			ID=mem[ior].lower_bound(turev[isr]);
			mem[ior].erase(ID);
			turev[isr]=v;
			mem[ior].insert(v);
			ID=mem[ior].end();
			--ID;
			if(NV!=(*ID))
				xg(1,cnt+1,id[ior+1],(*ID),1);
		}
		else
		{
			scanf("%s",s);
			int bj=0,len=strlen(s),ans=-1;
			for(int j=0;j<len;++j)
			{
				int c=s[j]-'a';
				bj=trie[bj][c];
				ans=max(ans,qcx(bj+1));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}