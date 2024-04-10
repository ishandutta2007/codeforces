// Problem: F2. Tree Cutting (Hard Version)
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/F2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
vector<int> e[300003];
int a[300003],d[300003];
int f[300003][19];
void dfs(int x,int fa)
{
	d[x]=d[fa]+1,
	f[x][0]=fa;
	for(int i=1; i<19; ++i) f[x][i]=f[f[x][i-1]][i-1];
	for(int i:e[x]) if(i!=fa) dfs(i,x);
	return ;
}
int LCA(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	for(int i=18; i>=0; --i) if(d[f[x][i]]>=d[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=18; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int ans[300003][2];
//ans0 
//
//
//ans1 
//
//
bool vis[300003];
void dfs1(int x,int qwq)
{
	vis[x]=1;
	ans[x][1]=0,ans[x][0]=0;
	int C1=0,C2=0,S=1;
	vector<int> tmp;
	int Zero=0;
	for(int i:e[x]) if((a[i]==0)&&!vis[i]) 
	{
		dfs1(i,1);++C1;
		if((ans[i][0]+ans[i][1])%p==0) ++Zero;
		else 
		S=S*(ans[i][0]+ans[i][1])%p;
		tmp.push_back(i);
	}
	else if(a[i]!=0) ++C2;
	if(!Zero) ans[x][0]=S*C2%p,ans[x][1]=S;
#ifdef LOCAL1
	printf("%lld %lld %lld\n",x,ans[x][0],ans[x][1]);
#endif
	for(int i:tmp) if(ans[i][1])
	{
		if(!(ans[i][0]+ans[i][1])%p) --Zero; 
		else S=S*qp((ans[i][0]+ans[i][1])%p,p-2)%p;
		if(Zero==0){
		int T=S*ans[i][0]%p;
		ans[x][0]=(ans[x][0]+T)%p;}
		if(!(ans[i][0]+ans[i][1])%p) ++Zero; 
		else S=S*(ans[i][0]+ans[i][1])%p;
	}
#ifdef LOCAL1
	printf("%lld %lld %lld\n",x,ans[x][0],ans[x][1]);
#endif
	return ;
}
int check(int x)
{
	for(int i:e[x])if(a[i]!=0) return 1;
	return 0;
}
vector<int> v[300003];
signed main()
{
	int n=read(),k=read();
	for(int i=1; i<=n; ++i) a[i]=read(),v[a[i]].push_back(i);
	for(int i=1; i<n; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,1);
	for(int i=1; i<=k; ++i)
	{
		assert(!v[i].empty());
		int cur=0;
		for(int j:v[i]) if(!cur) cur=j; else cur=LCA(j,cur);
		if(a[cur]==0) a[cur]=i;
		if(a[cur]!=i) puts("0"),exit(0);
		for(int j:v[i])
		{
			int X=j;
			if(X==cur) continue;
			while(1)
			{
				X=f[X][0];
				if(a[X]==i) break;
				if(a[X]==0) 
				{a[X]=i;continue;}
				puts("0"),exit(0);
			}
		}
	}
	int Ans=1;
	for(int i=1; i<=n; ++i) if(a[i]==0&&(!vis[i])&&check(i))
	dfs1(i,0),Ans=Ans*ans[i][0]%p;
#ifdef LOCAL1
	for(int i=1; i<=n; ++i) printf("%lld ",a[i]);
	puts("");
#endif
	printf("%lld\n",Ans);
	return 0;
}