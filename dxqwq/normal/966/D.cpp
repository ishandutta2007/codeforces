// Problem: D. Aztec Catacombs
// Contest: Codeforces - Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3)
// URL: https://codeforces.com/contest/966/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
unordered_set<int> e[1000003];
int d[1000003],fa[1000003];
int f[1000003][20];
void bfs()
{
	memset(d,0x3f,sizeof(d));
	queue<int> q;
	d[1]=0;q.push(1);
	for(int i=0; i<20; ++i) f[1][i]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i:e[x]) if(d[i]>d[x]+1)
		{
			d[i]=d[x]+1;
			fa[i]=x;
			f[i][0]=x;
			for(int j=1; j<20; ++j) f[i][j]=f[f[i][j-1]][j-1];
			q.push(i);
		}
	}
	return ;
}
int U[1000003],V[1000003];
signed main()
{
#define s e
	int n=read(),m=read();
	for(int i=1,u,v; i<=m; ++i) u=read(),v=read(),U[i]=u,V[i]=v,e[u].insert(v),e[v].insert(u);
	bfs();
	if(e[1].empty())
	{
		puts("-1");
		return 0;
	}
	if(s[1].find(n)!=s[1].end())
	{
		puts("1");
		printf("1 %d\n",n);
		return 0;
	}
	for(int i:e[1]) if(s[i].find(n)!=s[i].end())
	{
		puts("2");
		printf("1 %d %d\n",i,n);
		return 0;
	}
	for(int i:e[1]) for(int j:e[i]) if(j!=1) if(s[j].find(n)!=s[j].end())
	{
		puts("3");
		printf("1 %d %d %d\n",i,j,n);
		return 0;
	}
	for(int i:e[1]) for(int j:e[i]) if(j!=1) if(s[j].find(1)==s[j].end())
	{
		puts("4");
		printf("1 %d %d 1 %d\n",i,j,n);
		return 0;
	}
	//1ab1n
	if(d[n]==4)
	{
		int A=n;
		stack<int> s;
		while(A!=1)
		{
			s.push(A);
			A=fa[A];
		}
		assert((int)s.size()==d[n]);
		printf("%d\n1 ",d[n]);
		while(!s.empty())
		{
			printf("%d ",s.top());
			s.pop();
		}
		return 0;
	}
	int SSS=0;
	for(int i=1; i<=n; ++i) SSS+=(d[i]==1);
	for(int i=1; i<=n; ++i) if(d[i]==1)
	{
		unordered_map<int,int> vis;
		vis[i]=1;
		int sss=1;
		for(int j:s[i]) if(d[j]==1) ++sss,vis[j]=1;
		if(sss<SSS)
		{
			for(int j:s[i]) if(d[j])
			for(int k:s[j]) if(!vis[k]&&d[k])
			{
				puts("5");
				printf("1 %d %d %d %d %d\n",i,j,k,i,n);
				return 0;
			}
		}
	}
	//1abc1n
	//1 -> b
	//1bc1n
	if(d[n]<=1e9)
	{
		int A=n;
		stack<int> s;
		while(A!=1)
		{
			s.push(A);
			A=fa[A];
		}
		assert((int)s.size()==d[n]);
		printf("%d\n1 ",d[n]);
		while(!s.empty())
		{
			printf("%d ",s.top());
			s.pop();
		}
		return 0;
	}
	//1abcdbn
	//1bcdbn
	puts("-1");
	return 0;
}
//1 2 0
//1 3 0
//1 4 1
//2 3 1
//2 4 0
//3 4 0
//current 2