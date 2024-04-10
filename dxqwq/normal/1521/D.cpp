// Problem: D. Nastia Plays with a Tree
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bool Vis[1000003],f[1000003];
vector<int> e[1000003],ee[1000003];
#define pb push_back
int d[1000003];
int C,U1[1000003],V1[1000003],U2[1000003],V2[1000003];
int CC;
int FIR,LST;
void dfs(int x,int fa)
{
	for(int y:e[x]) if(y!=fa) dfs(y,x);
	int A=0,B=0;
	for(int y:e[x]) if(y!=fa)
	{
		if(!f[y]) 
		{
			if(!A) A=y; 
			else if(!B) B=y;
			else
			{
				U1[++CC]=x,V1[CC]=y;
			}
		}
		else U1[++CC]=x,V1[CC]=y;
	}
	if(A&&B)
	{
		f[x]=1;
		ee[A].pb(x);
		ee[x].pb(A);
		ee[B].pb(x);
		ee[x].pb(B);
		// printf("* %d %d %d\n",A,x,B);
	}
	else if(A)
	{
		ee[A].pb(x);
		ee[x].pb(A);
		// printf("* %d %d\n",x,A);
	}
	return ;
}
void dfs2(int x)
{
	Vis[x]=1,LST=x;
	for(int y:ee[x]) if(!Vis[y]) dfs2(y);
}
void print()
{
	printf("%d\n",C);
	for(int i=1; i<=C; ++i) 
	printf("%d %d %d %d\n",U1[i],V1[i],U2[i],V2[i]);
	return;
}
signed main()
{
    for(int T=read();T--;)
    {
    	C=0;CC=0;
    	int L=0,R=0;
    	int n=read();
    	for(int i=1; i<=n; ++i) e[i].clear(),ee[i].clear();
    	for(int i=1; i<=n; ++i) d[i]=0,Vis[i]=0,f[i]=0;
    	for(int i=1,u,v; i<n; ++i)
    	{
    		u=read(),v=read();
    		e[u].pb(v);e[v].pb(u);
    		++d[u],++d[v];
    	}
    	int rt=1;
    	for(int i=2; i<=n; ++i) if(d[i]>d[rt]) rt=i;
    	
    	// printf("#%d\n",rt);
    	dfs(rt,rt);
    	
    	for(int i=1; i<=n; ++i) if(!Vis[i]&&ee[i].size()<=1)
    	{
    		FIR=i;
    		dfs2(i);
    		// printf("%d %d\n",FIR,LST);
    		if(!L)
    		{
    			L=FIR,R=LST;
    		}
    		else
    		{
    			U2[++C]=R,V2[C]=FIR,R=LST;
    		}
    	}
    	//assert(C==CC);
    	print();
    }
	return 0;
}