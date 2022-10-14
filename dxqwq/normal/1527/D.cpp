// Problem: D. MEX Tree
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define ll long long
vector<int> e[1000003];
int d[1000003],sz[1000003];
int f[1000003][20];
void dfs(int x,int fa)
{
	d[x]=d[fa]+1,sz[x]=1;
	f[x][0]=fa;
	for(int i=1; i<20; ++i) f[x][i]=f[f[x][i-1]][i-1];
	for(int y:e[x]) if(y!=fa)dfs(y,x),sz[x]+=sz[y];
	return ;
}
bool vis[1000003];
int dfs1(int x,int fa)
{
	if(x==1) return 0;
	int res=1;
	for(int y:e[x]) if(y!=fa)res+=dfs1(y,x);
	return res;
}
int dfs0(int x)
{
	if(x==0) return 0;
	vis[x]=1;
	int res=1;
	for(int y:e[x]) if(!vis[y]) res+=dfs0(y);
	return res;
}
int UP(int x,int d)
{
	for(int i=19; i>=0; --i) if(d&(1<<i)) x=f[x][i];
	return x;
}
int deg[1000003];
bool isparent(int x,int y)
{
	if(d[x]>d[y]) return 0;
	if(d[x]==d[y])
	{
		if(x==y) return 1;
		return 0;
	}
	return (UP(y,d[y]-d[x])==x);
}
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	d[0]=-1;
    	for(int i=0; i<n; ++i) 
    	e[i].clear(),deg[i]=0,vis[i]=0;
    	for(int i=1; i<n; ++i)
    	{
    		int u=read(),v=read();
    		e[u].push_back(v);
    		e[v].push_back(u);
    		++deg[u],++deg[v];
    	}
    	dfs(0,0);
    	ll AAA=0;
    	for(int i=1; i<n; ++i) if(!vis[i])
    	{
    		ll S=dfs0(i);
    		if(S>1) AAA+=S*(S-1)/2;
    	}
    	printf("%lld ",AAA);
    	ll S=1;
    	ll ans=0;
    	for(int i:e[0]) 
    	{
    		int A=dfs1(i,0);
    		ans+=S*A,S+=A;
    	}
    	printf("%lld ",ans);
    	int S1=0,S2=0;//
    	for(int i=1; i+1<n; ++i)
    	{
    		int C=0;
    		//A  B 
    		
    		if(isparent(i,S1))
    		{
    			++C;
    		}
    		else if(isparent(i,S2))
    		{
    			++C;
    		}
    		else if(isparent(S1,i)) S1=i;
    		else 
    		{
    			if(S2==0)
    			{
    				if(!isparent(UP(S1,d[S1]-1),i))
    				{
    					S2=i;
    				} 
    				else
    				{
		    			for(int j=i; j+1<n; ++j) printf("0 ");
		    			break;
    				}
    			}
    			else
    			{
    				if(isparent(S2,i)) S2=i;
    				else
    				{
		    			for(int j=i; j+1<n; ++j) printf("0 ");
		    			break;
    				}
    			}
    			
    		}
    		if(isparent(i+1,S1)||isparent(i+1,S2))
    		{
    			printf("0 ");
    			continue;
    		} 
    		ll sz1=sz[S1],sz2=sz[S2];
    		if(S2==0) sz2=n-sz[UP(S1,d[S1]-1)];
    		if(isparent(S1,i+1)) sz1-=sz[i+1];
    		if(isparent(S2,i+1))
    		if(S2==0)
    		{
    			if(!isparent(UP(S1,d[S1]-1),i+1)) 
    			sz2-=sz[i+1];
    		}
    		else
    		{
    			sz2-=sz[i+1];
    		}
    		printf("%lld ",sz1*sz2);
    	}
    	int F=1;
    	for(int i=0; i<n; ++i) if(deg[i]>2) 
    	{
    		F=0;
    		break;
    	}
    	printf("%d\n",F);
    }
	return 0;
}