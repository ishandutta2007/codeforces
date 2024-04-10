// Problem: E. You
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
vector<int> e[100003];
int prim[100003];
int mu[100003],cnt=0;
bool vis[100003];
vector<int> d[100003];
void init()
{
    mu[1]=1;
    for(int i=2;i<=100000;i++)
    {
        if(!vis[i]) prim[++cnt]=i,mu[i]=-1;
        for(int j=1; j<=cnt&&prim[j]*i<=100000; j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break; 
            else mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=2; i<=100000; ++i)
    	for(int j=1; i*j<=100000; ++j)
    		d[i*j].push_back(i);
}
int sz[100003],ans[100003];
int val[100003],top;
bool f[100003];
bool dfs(int x,int y,int k)
{
	sz[x]=0;
	for(int i:e[x]) if(i!=y) 
	{
		if(!dfs(i,x,k)) return 0;
		sz[x]+=sz[i];
	}
	if(!(sz[x]%k)) {sz[x]=1;return 1;}
	if(!((sz[x]+1)%k)) {sz[x]=0;return 1;}
	return 0;
}
signed main()
{
	init();
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) e[i].clear(),ans[i]=0;
		for(int i=1; i<n; ++i)
		{
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		top=0;
		ans[1]=qp(2,n-1);
		for(int i:d[n-1])
		{
			if(dfs(1,1,i)) ans[i]=1;
		}
		for(int i=1; i<=n; ++i)
		{
			int sum=0;
			for(int j=1; i*j<=n; ++j) sum+=ans[i*j]*mu[j];
			printf("%lld ",sum);
		}
		puts("");
	}

	return 0;
}