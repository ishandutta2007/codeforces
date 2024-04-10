#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define ND 200000
#define K 350
int a[MN+5],L[K+5],R[K+5],qn;
int rt[MN+5],u[MN+5],l[ND+5],r[ND+5],w[ND+5],s[ND+5],mk[ND+5],q[ND+5],z[MN+5],zn;
vector< pair<int,int> > v[MN+5];
inline int ran()
{
	static int x=23333;
	return x^=x<<13,x^=x>>17,x^=x<<5;
}
inline void up(int x){s[x]=s[l[x]]+s[r[x]]+1;}
inline void add(int x,int z){w[x]+=z;mk[x]+=z;}
inline void down(int x){if(mk[x])add(l[x],mk[x]),add(r[x],mk[x]),mk[x]=0;}
int merge(int a,int b)
{
	if(!a||!b)return a+b;
	if(q[a]>q[b])return down(a),r[a]=merge(r[a],b),up(a),a;
	else return down(b),l[b]=merge(a,l[b]),up(b),b;
}
void split(int x,int k,int&a,int&b)
{
	if(!x){a=b=0;return;}down(x);
	if(w[x]<=k)a=x,split(r[x],k,r[x],b);
	else b=x,split(l[x],k,a,l[x]);up(x);
}
void build(int x)
{
	rt[x]=0;
	for(int i=0;i<v[x].size();++i)
	{
		int p=v[x][i].first;q[p]=ran();
		r[p]=mk[p]=0;w[p]=v[x][i].second;s[p]=1; 
		for(z[zn+1]=0;zn&&q[p]>q[z[zn]];)up(z[zn--]);
		l[p]=z[zn+1];
		if(zn)r[z[zn]]=p;else rt[x]=p;
		z[++zn]=p;
	}
	while(zn)up(z[zn--]);
	v[x].clear();
}
void shift(int x,int l,int r)
{
	int a,b,c,d;
	split(rt[x],r,a,b);
	split(a,l-1,a,c);
	split(c,r-1,c,d);
	add(c,1);w[d]=l;
	rt[x]=merge(merge(a,d),merge(c,b));
}
void dfs(int x)
{
	down(x);
	if(l[x])dfs(l[x]);
	v[a[x]].push_back(make_pair(x+MN,w[x]));
	if(r[x])dfs(r[x]);
}
int main()
{
	int n=read(),q,i,t,l,r,k,ls=0;
	for(i=1;i<=n;++i)
		v[0].push_back(make_pair(i,i)),
		v[a[i]=read()].push_back(make_pair(i+MN,i));
	for(i=0;i<=n;++i)build(i);
	for(q=read();q--;)
	{
		t=read();l=(read()+ls-1)%n+1;r=(read()+ls-1)%n+1;if(l>r)swap(l,r);
		if(t==1)
		{
			L[++qn]=l;R[qn]=r;shift(0,l,r);
			if(qn==K)
			{
				dfs(rt[0]);
				memset(u,qn=0,sizeof(u));
				for(i=1;i<=n;++i)build(i);
			}
		}
		else
		{
			k=(read()+ls-1)%n+1;
			while(u[k]<qn)++u[k],shift(k,L[u[k]],R[u[k]]);
			int a,b,c;
			split(rt[k],r,a,b);
			split(a,l-1,a,c);
			printf("%d\n",ls=s[c]);
			rt[k]=merge(merge(a,c),b);
		}
	}
}