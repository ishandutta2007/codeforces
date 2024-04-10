// Problem: C. Rumor
// Contest: Codeforces - Educational Codeforces Round 33 (Rated for Div. 2)
// URL: https://codeforces.com/contest/893/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
vector<int> v[1000003];
int a[1000003],mx;
bool f[1000003];
void dfs(int x)
{
	f[x]=1;mx=min(mx,a[x]);
	for(int i:v[x]) if(!f[i]) dfs(i);
	return ;
}
signed main()
{
 	int n=read(),m=read();
 	for(int i=1; i<=n; i++) a[i]=read();
 	for(int i=1,x,y; i<=m; i++) x=read(),y=read(),v[x].push_back(y),v[y].push_back(x); 
	int ans=0;
	for(int i=1; i<=n; i++) if(!f[i])
	{
		mx=1000000000;
		dfs(i);
		ans+=mx;
	}
	printf("%lld\n",ans);
	return 0;
}