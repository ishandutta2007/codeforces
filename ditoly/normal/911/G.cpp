#include<cstdio>
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
#define MN 200000
#define MX 100
#define K 500
int a[MN+5],c[MN/K+5][101],t[101];
vector<int> v[MN/K+5][101];
void build(int x)
{
	for(int i=1;i<=100;++i)
		v[x/K][c[x/K][i]=i].push_back(i);
}
void rebuild(int x)
{
	for(int i=1;i<=100;v[x/K][c[x/K][i++]].clear())
		for(int j=0;j<v[x/K][c[x/K][i]].size();++j)t[v[x/K][c[x/K][i]][j]]=i;
	for(int i=0;i<K;++i)a[x+i]=t[a[x+i]];
}
void solve(int k,int x,int y)
{
	if(x==y)return;
	if(v[k/K][c[k/K][x]].size()>v[k/K][c[k/K][y]].size())swap(c[k/K][x],c[k/K][y]);
	for(int i=0;i<v[k/K][c[k/K][x]].size();++i)v[k/K][c[k/K][y]].push_back(v[k/K][c[k/K][x]][i]);
	v[k/K][c[k/K][x]].clear();
}
int main()
{
	int n=read(),i,q,l,r,x,y;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=MN;i+=K)build(i);
	for(q=read();q--;)
	{
		l=read();r=read();x=read();y=read();
		int lk=(l-1)/K*K+1,rk=(r-1)/K*K+1;
		rebuild(lk);if(lk!=rk)rebuild(rk);
		for(i=l;i<=r&&i<lk+K;++i)if(a[i]==x)a[i]=y;
		for(i=lk;(i+=K)<rk;)solve(i,x,y);
		if(lk!=rk)for(i=rk;i<=r;++i)if(a[i]==x)a[i]=y;
		build(lk);if(lk!=rk)build(rk);
	}
	for(i=1;i<=MN;i+=K)rebuild(i);
	for(i=1;i<=n;++i)printf("%d ",a[i]);
}