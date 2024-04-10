#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
ll n,cnt=0;
void dfs(ll s)
{
	if(s>1e9)return ;
	if(s<=n)cnt++;
	dfs(s*10);
	dfs(s*10+1);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	dfs(1);
	cout<<cnt;
	return 0;
}