#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int ans[234567];
vector<int>g[234567];
int fa[234567];
int n;
int sz;
void dfs(int u,int pre)
{
	int now = 1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==pre)continue;
		while(now == ans[u] || now==ans[pre]) now++;
		ans[v] = now;
		sz = max(sz,now);
		now++;
		dfs(v,u);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans[1] = 1;
	sz = 1;
	dfs(1,0);
	
	cout<<sz<<endl;
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}