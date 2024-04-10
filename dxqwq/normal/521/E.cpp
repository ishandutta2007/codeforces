// Problem: CF521E Cycling City
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF521E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
int u[200003],v[200003],fa[200003],dep[200003];
bool vis[200003],vv[200003];
vector<int> e[200003];
int find(int x)
{
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
int col[200003],f[200003];
void dfs(int x,int fa)
{
	f[x]=fa,dep[x]=dep[fa]+1,vv[x]=1;
	for(int i:e[x]) if(i!=fa) dfs(i,x);
}
int cc[200003];
int calc(int P,int Q)
{	
	puts("YES");
	dep[u[P]]=0,dfs(u[P],u[P]);
	
	// printf("%d\n",u[P]);
	// for(int i=1; i<=5; ++i) printf("%d ",f[i]);
	// exit(0);
	
	int G=v[P];
	cc[u[P]]=1;
	while(G!=u[P]) cc[G]=1,G=f[G];
	
	int A=u[Q],B=v[Q];
	vector<int> V1,V2,V3;
	stack<int> stk;
	
	while(!cc[A]) V1.push_back(A),A=f[A];
	while(!cc[B]) V2.push_back(B),B=f[B];
	assert(dep[A]!=dep[B]);
	if(dep[A]<dep[B]) swap(V1,V2),swap(A,B),swap(u[Q],v[Q]);
	
	vector<int> A1,A2,A3;
	
	G=A;
	while(G!=B) A1.push_back(G),G=f[G];
	A1.push_back(B);
	
	G=v[P];
	while(G!=A) stk.push(G),G=f[G];
	A2.push_back(A);
	while(!stk.empty()) A2.push_back(stk.top()),stk.pop();
	G=B;
	while(G!=u[P]) stk.push(G),G=f[G];
	A2.push_back(u[P]);
	while(!stk.empty()) A2.push_back(stk.top()),stk.pop();
	
	G=u[Q];
	while(G!=A) stk.push(G),G=f[G];
	A3.push_back(A);
	while(!stk.empty()) A3.push_back(stk.top()),stk.pop();
	G=v[Q];
	while(G!=B) A3.push_back(G),G=f[G];
	A3.push_back(B);
	while(!stk.empty()) A3.push_back(stk.top()),stk.pop();
	
	printf("%d ",(int)A1.size());
	for(int i:A1) printf("%d ",i);
	puts("");
	printf("%d ",(int)A2.size());
	for(int i:A2) printf("%d ",i);
	puts("");
	printf("%d ",(int)A3.size());
	for(int i:A3) printf("%d ",i);
	puts("");
	
	exit(0);
	return ~(0-0);
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int i=1; i<=m; ++i) 
	{
		u[i]=read(),v[i]=read();
		int X=find(u[i]),Y=find(v[i]);
		if(X!=Y) e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]),fa[Y]=X,vis[i]=1;	
	}
	for(int i=1; i<=n; ++i) if(!vv[i]) dfs(i,i);
	for(int i=1; i<=m; ++i) if(!vis[i]) 
	{
		int A=u[i],B=v[i];
		while(dep[A]>dep[B]) (col[A])&&(calc(col[A],i)),col[A]=i,A=f[A];
		while(dep[A]<dep[B]) (col[B])&&(calc(col[B],i)),col[B]=i,B=f[B];
		while(A!=B) (col[A])&&(calc(col[A],i)),(col[B])&&(calc(col[B],i)),col[A]=col[B]=i,A=f[A],B=f[B];
	}
	puts("NO");
	return 0;
}