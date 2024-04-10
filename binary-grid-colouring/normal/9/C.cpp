#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
map<int,bool>vis;
void dfs(ll x)
{
	if(x>n)return ;
	if(vis[x]==true)return ;
	vis[x]=true;
	ans++;
	dfs(x*10);
	dfs(x*10+1);
}
int main()
{
	cin>>n;
//	memset(vis,false,sizeof(vis));
	dfs(1);
	cout<<ans<<endl;
	return 0;
}