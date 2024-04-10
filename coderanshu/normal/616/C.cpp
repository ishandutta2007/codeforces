#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1005;
int n,m;
char a[N][N];
bool vis[N][N];
int cnt,ans[N][N];
set<pair<int,int>> v;

void dfs(int i,int j)
{
	if(vis[i][j])
		return ;
	if(a[i][j]=='*')
	{
	    v.insert({i,j});
	    return ;
	}
	++cnt;
	vis[i][j]=true;
	if(i>0)dfs(i-1,j);
	if(i<n-1)dfs(i+1,j);
	if(j>0)dfs(i,j-1);
	if(j<m-1)dfs(i,j+1);
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>a[i][j];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(vis[i][j] || a[i][j]=='*')continue;
			cnt=0;
			dfs(i,j);
			for(auto j:v)
				ans[j.first][j.second]+=cnt;
			v.clear();
		}
	}
	for(int i=0;i<n;++i)
	{
	    for(int j=0;j<m;++j)
	    {
	        if(a[i][j]=='.')cout<<a[i][j];
	        else cout<<(ans[i][j]+1)%10;
	    }
	    cout<<'\n';
	}
	return 0;
}