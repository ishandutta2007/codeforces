#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
vector<int> g[N];
bool vis[N];
bool c[N];
ll ans,ans1,ans2;
void dfs(int cur){
	ans1*=c[cur]?2:1;
	ans2*=c[cur]?1:2;
	ans1%=mod;
	ans2%=mod;
	for(auto v:g[cur]){
		if(vis[v]) continue;
		vis[v]=1;
		c[v]=!c[cur];
		dfs(v);
	}
}
int main(){
    int i,j;
    int T;cin>>T;
    while(T--){
    	cin>>n>>m;
    	for(i=1;i<=n;i++) g[i].clear();
    	while(m--){
    		int x,y;cin>>x>>y;
    		g[x].push_back(y);
			g[y].push_back(x);
		}
		for(i=1;i<=n;i++) c[i]=vis[i]=0;
		ans=1;
		for(i=1;i<=n;i++){
			if(!vis[i]){
				ans1=ans2=1;
				vis[i]=1;
				dfs(i);
				ans*=(ans1+ans2);
				ans%=mod;
			}
		}
		bool flag=0;
		for(i=1;i<=n;i++){
			for(auto v:g[i]){
				if(c[i]==c[v]){
					cout<<0<<endl;
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) continue;
		cout<<ans<<endl;
	}
    return 0;
}