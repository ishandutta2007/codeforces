#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=1000000007;
int n,m;
int dp[N];
vector<int> p[N],g[N];
map<int,int> mp[N];
int ans;
int a[N];
void dfs(int cur,int last){
	for(auto v:g[cur]){
		if(v==last) continue;
		dfs(v,cur);
	}
	for(auto pri:p[cur]){
		int mx1=0,mx2=0;
		for(auto v:g[cur]){
			if(v==last) continue;
			int k=mp[v][pri];
			if(k>mx1){
				mx2=mx1;
				mx1=k;
			}
			else if(k>mx2)
				mx2=k;
		}
		ans=max(ans,mx1+mx2+1);
		mp[cur][pri]=mx1+1;
	}
}
int main(){
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	int x=a[i];
    	for(j=2;j*j<=a[i];j++){
    		if(x%j==0){
    			p[i].push_back(j);
    			while(x%j==0) x/=j;
			}
		}
		if(x>1) p[i].push_back(x);
	}
	for(i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	cout<<ans;
    return 0;
}