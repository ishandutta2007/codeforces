// Problem: CF1540B Tree Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1540B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int n=read();
vector<int> e[1003];
int s;
int sz[1003];
int f[1003][1003];
//x steps,y steps,x first
void init(int n)
{
	for(int i=1; i<=n; ++i) f[0][i]=1;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)
	f[i][j]=(f[i-1][j]+f[i][j-1])*qp(2,p-2)%p;
	return ;
}
void getd(int x,int fa,int v)
{
	if(x<v) ++s;
	for(int i:e[x]) if(i!=fa) getd(i,x,v);
}
void dfs(int x,int fa)
{
	getd(x,fa,x);
	for(int i:e[x]) if(i!=fa) dfs(i,x);
}
vector<pair<int,int> > c[1003];
void calc(int x,int fa,int id,int d)
{
	for(pair<int,int> i:c[id]) if(x>i.first)
		s=(s+f[d][i.second])%p;
	else s=(s+f[i.second][d])%p;
	for(int i:e[x]) if(i!=fa) calc(i,x,id,d+1);
}
void add(int x,int fa,int id,int d)
{
	c[id].push_back(make_pair(x,d));
	for(int i:e[x]) if(i!=fa) add(i,x,id,d+1);
}
void dfs2(int x,int fa)
{
	for(int i:e[x]) if(i!=fa) calc(i,x,x,1),add(i,x,x,1);
	for(int i:e[x]) if(i!=fa) dfs2(i,x);
}
void calc(int x)
{
	for(int i=1; i<=n; ++i) c[i].clear();
	dfs(x,x);
	//cout<<s<<" ";
	dfs2(x,x);
	//cout<<s<<endl;
}
signed main()
{
	init(n);
	for(int i=1,p,q; i<n; ++i) 
	p=read(),q=read(),e[p].push_back(q),e[q].push_back(p); 
	for(int i=1; i<=n; ++i)
	calc(i);
	printf("%lld\n",s*qp(n,p-2)%p);
	return 0;
}