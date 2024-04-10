//  zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int u[1000003],v[1000003];
vector<int> e[1000003];
bool f[1000003];
void dfs(int x)
{
	f[x]=1;
	for(int y:e[x]) if(!f[y]) dfs(y);
}
int deg[1000003];
signed main()
{
	int n=read(),m=read(),C=0;
	for(int i=1; i<=m; i++) 
	{
		u[i]=read(),v[i]=read(),++deg[u[i]],++deg[v[i]],e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]); 
		if(u[i]==v[i]) deg[u[i]]-=2,++C;
	}
	for(int i=1; i<=n; i++) if(!e[i].empty()) {dfs(i);break;}
	for(int i=1; i<=n; i++) if((!e[i].empty())&&(!f[i])) puts("0"),exit(0);
	int ans=C*(m-C);
	ans+=C*(C-1)/2;
	for(int i=1; i<=n; i++) ans+=deg[i]*(deg[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
}