/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100000;
int n,a,b,da,db;
vector<int> nei[N+1];
int dep[N+1],dp[N+1];
int ans;
void dfs(int x=a,int fa=0){
	vector<int> v;
	v.pb(dep[x]);
	dp[x]=dep[x];
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
		v.pb(dp[y]);
		dp[x]=max(dp[x],dp[y]);
	}
	sort(v.begin(),v.end(),greater<int>());
	if(v.size()>=2)ans=max(ans,v[0]+v[1]-2*dep[x]);
}
void mian(){
	//clear
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	for(int i=1;i<=n;i++)nei[i].clear();
	for(int i=1;i<=n;i++)dep[i]=dp[i]=0;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		nei[x].pb(y);
		nei[y].pb(x);
	}
	if(db<2*da+1)return puts("Alice"),void();
	ans=0;
	dfs();
	if(ans>=2*da+1&&dep[b]>da)puts("Bob");
	else puts("Alice");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}