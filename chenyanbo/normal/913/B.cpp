#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int tot,n,op[3000],c[3000][2],a[3000],fa[3000];

void dfs(int p)
{
	int y=0; 
	for(int o=a[p]; o; o=c[o][1])
	{
		dfs(c[o][0]);
		if(!op[c[o][0]])++y;
	}
	if(y<=2 && op[p]){
		puts("No");
		exit(0);
	}
}

int main()
{
	n=read();
	for(int i=2; i<=n; ++i)
	{
	    fa[i]=read();
	    op[fa[i]]=1; 
	    c[++tot][0]=i; c[tot][1]=a[fa[i]]; a[fa[i]]=tot;
	}
	dfs(1);
	puts("Yes");
}