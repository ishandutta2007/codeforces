// Problem: B. Tree Tag
// Contest: Codeforces - Codeforces Round #668 (Div. 1)
// URL: https://codeforces.com/contest/1404/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
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
int d[1000003];
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	for(int i:v[x]) if(i!=fa) dfs(i,x);
	return ;
}
signed main()
{
	d[0]=-1;
	for(int T=read();T--;)
	{
		int n=read(),a=read(),b=read(),A=read(),B=read();
		for(int i=1; i<=n; ++i) v[i].clear();
		for(int i=1; i<n; ++i) 
		{
			int x=read(),y=read();
			v[x].push_back(y),
			v[y].push_back(x);
			
		}
		dfs(a,0);
		if(d[b]<=A)
		{
			puts("Alice");
			continue;
		}
		int t=1;
		for(int i=1; i<=n; ++i) if(d[i]>d[t]) t=i;
		dfs(t,0);
		t=0;
		for(int i=1; i<=n; ++i) if(d[i]>t) t=d[i];
		if(A*2>=t)
		{
			puts("Alice");
			continue;
		}
		if(A*2<B)
		{
			puts("Bob");
		}
		else puts("Alice");
	}
    return 0;
}