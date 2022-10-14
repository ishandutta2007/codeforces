// Problem: D. Decorate Apple Tree
// Contest: Codeforces - Mail.Ru Cup 2018 Round 3
// URL: https://codeforces.com/contest/1056/problem/D
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
int sz[1000003];
vector<int> v[1000003];
void dfs(int x)
{
	if(v[x].empty()){sz[x]=1;return;}
	for(int i:v[x])
	{
		dfs(i);
		sz[x]+=sz[i];
	}
	return ;
}
int c[1000003];
signed main()
{
	int n=read();
	for(int i=2; i<=n; ++i)
	{
		int A=read();
		v[A].push_back(i);
	}
	dfs(1);
    for(int i=1; i<=n; ++i) ++c[sz[i]];
    for(int i=1; i<=n; ++i) c[i]+=c[i-1];
    for(int i=1; i<=n; ++i) printf("%d ",lower_bound(c+1,c+n+1,i)-c);
    return 0;
}