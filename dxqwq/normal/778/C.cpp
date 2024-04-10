// Problem: C. Peterson Polyglot
// Contest: Codeforces - Codeforces Round #402 (Div. 1)
// URL: https://codeforces.com/contest/778/problem/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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
int nxt[1500003][26];
int v[1500003];
int w[1500003],hs[1500003];
int X[1500003],Y[1500003],C=0;
int CNT=700000;
int qwq;
void merge(int x,int y)
//merge x to y
{
	//printf("%d %d\n",x,y);
	for(int i=0; i<26; ++i)
	{
		if(nxt[x][i])
		{
			if(!nxt[y][i]) 
			{
				X[++C]=y,Y[C]=i;
				nxt[y][i]=++CNT;
				//return ;
			}
			else ++v[qwq];
			merge(nxt[x][i],nxt[y][i]);
		}
	}
	return ;
}
void clear()
{
	for(int i=1; i<=C; i++)
	nxt[X[i]][Y[i]]=0;
	C=0;
	return ;
}
void dfs(int d,int x)
{
	for(int i=0; i<26; i++) 
	if(nxt[x][i]) ++v[d],dfs(d+1,nxt[x][i]);
	qwq=d;CNT=700000;
	for(int i=0; i<26; i++) 
	if(nxt[x][i]&&(nxt[x][i]!=hs[x])) merge(nxt[x][i],hs[x]);
	clear(); 
	return ;
}
void init(int x)
{
	for(int i=0,g=-1; i<26; i++) 
	if(nxt[x][i]) 
	{
		init(nxt[x][i]),w[x]+=w[nxt[x][i]];
		if(w[nxt[x][i]]>g) hs[x]=nxt[x][i],g=w[nxt[x][i]];
	}
	return ;
}
int to[1000003],Nxt[1000003],c[1000003],head[1000003];
int Q=0;
void DFS(int x,int y)
{
	for(int i=head[x]; i; i=Nxt[i]) if(to[i]!=y)
	{
		nxt[x][c[i]]=to[i];
		DFS(to[i],x);
	}
	return ;
}
signed main()
{
    int n=read();
    char s;
    for(int i=1; i<=n; i++) w[i]=1;
    for(int i=1,u,v; i<n; i++) 
    {
    	u=read(),v=read(),s=getchar();
    	while(!islower(s)) s=getchar();
    	s-='a';
    	to[++Q]=v,Nxt[Q]=head[u],head[u]=Q,c[Q]=s;
    	//nxt[u][s-'a']=v;c=c;
    }
    DFS(1,1);
	init(1);
    dfs(1,1);
    int mx=99999999,id=1;
    for(int i=n; i>=1; i--)
    {
    	if(n-v[i]<=mx)
    	{
    		mx=n-v[i];
    		id=i;
    	}
    }
    printf("%d\n%d\n",mx,id);
	return 0;
}