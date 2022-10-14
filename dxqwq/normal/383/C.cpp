#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
int tree[400003],d[200003];
int I[200003],O[200003],val[200003];
int n=read(),m=read(),cnt;
void add(int x,int k)
{
	while(x<=n) tree[x]+=k,x+=x&(-x);
	return ;
}
int query(int x)
{
	int res=0;
	while(x) res+=tree[x],x^=x&(-x);
	return res;
}
vector<int> e[200003];
void dfs(int x,int fa)
{
	d[x]=d[fa]^1,I[x]=++cnt;
	for(auto y:e[x]) if(y!=fa) dfs(y,x);
	O[x]=cnt+1;
	return ;
}
signed main()
{
	for(int i=1; i<=n; i++) val[i]=read();
	for(int i=1,u,v; i<n; i++) u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs(1,1);
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),y=read()*(d[x]*2-1);
			add(I[x],y),add(O[x],-y);
		}
		else
		{
			int x=read();
			printf("%d\n",val[x]+query(I[x])*(d[x]*2-1));	
		}
	}	
	return 0;
}