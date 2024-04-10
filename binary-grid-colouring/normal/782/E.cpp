#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <unistd.h> 
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

vector<int>g[234567];
int route[234567*2];
int cnt;
int n,m,k;
bool vis[234567];

void dfs(int u,int pre)
{
	route[++cnt] = u;
	vis[u] = true;
	for(int i=0;i<g[u].size();i++)
	{
		int v = g[u][i];
		if(vis[v]==true ||v==pre)continue;
		dfs(v,u);
		route[++cnt] = u;
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int sz = (2*n+k-1)/k;
	int l,r;
	for(int i=1;i<=k;i++)
	{
		l = min(2*n-1,(i-1)*sz+1);
		r = min(2*n-1,i*sz);
		
		cout << r-l+1 ;
		for(int j=l;j<=r;j++)
		{
			cout<<" "<<route[j];
		}
		cout<<endl;
	 } 
	return 0;
}