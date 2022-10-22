#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
int a[N];
int l[N],r[N],dp[N];
int ans;
vector<int> g[N];
void dfs(int u){
	if(g[u].empty()){
		ans++;
		dp[u]=r[u];
		return;
	}
	ll sum=0;
	for(auto v:g[u]){
		dfs(v);
		sum+=dp[v];
	}
	if(sum<l[u]){
		dp[u]=r[u];
		ans++;
	}
	else dp[u]=min((ll)r[u],sum);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=2;i<=n;i++){
			int fa;cin>>fa;
			g[fa].push_back(i);
		}
		for(i=1;i<=n;i++) cin>>l[i]>>r[i];
		dfs(1);
		cout<<ans<<endl;
		ans=0;
		for(i=1;i<=n;i++){
			dp[i]=0;
			g[i].clear();
		}
	}
	return 0;
}