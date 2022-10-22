#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N=2e5+5;
int n,m;
ll a[N];
ll dp[N][2];
set<pll> st;
vector<pll> v[N];
pll s[N];
bool vis[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) v[i].clear();
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		st.clear();
		for(i=1;i<=m;i++) cin>>s[i].fr>>s[i].sc;
		sort(s+1,s+m+1);
		for(i=1;i<=m;i++) vis[i]=0;
		j=0;
		for(i=1;i<=m;i++){
			while(j<n&&s[i].fr>a[j+1]){
				j++;
				while(!st.empty()&&(st.rbegin()->fr)>=a[j])
					st.erase(*st.rbegin());
			}
			while(!st.empty()&&(st.rbegin()->fr)>=s[i].sc)
				st.erase(*st.rbegin());
			st.insert({s[i].sc,i});
		}
		if(j<n){
			j++;
			while(!st.empty()&&(st.rbegin()->fr)>=a[j])
				st.erase(*st.rbegin());
		}
		for(auto x:st){
		//	cout<<s[x.sc].fr<<","<<s[x.sc].sc<<endl;
			vis[x.sc]=1;
		}
		ll w1=0,w2=0;
		for(i=1;i<=m;i++){
			if(!vis[i]) continue;
			if(s[i].sc<a[1])
				w1=max(w1,a[1]-s[i].sc);
			else if(s[i].fr>a[n])
				w2=max(w2,s[i].fr-a[n]);
			else{
				int pos=lower_bound(a+1,a+n+1,s[i].sc)-a-1;
				v[pos].push_back(s[i]);
			}
		}
		for(i=1;i<=n;i++) dp[i][0]=dp[i][1]=1e18;
		dp[1][0]=w1;dp[1][1]=w1*2;
		for(i=1;i<n;i++){
			for(j=-1;j<(int)v[i].size();j++){
				ll c1,c2;
				if(j==-1) c1=0;
				else c1=v[i][j].fr-a[i];
				if(j==(int)v[i].size()-1) c2=0;
				else c2=a[i+1]-v[i][j+1].sc;
				dp[i+1][0]=min(dp[i+1][0],dp[i][1]+c1+c2);
				dp[i+1][1]=min(dp[i+1][1],dp[i][1]+c1+c2*2);
				dp[i+1][0]=min(dp[i+1][0],dp[i][0]+c1*2+c2);
				dp[i+1][1]=min(dp[i+1][1],dp[i][0]+c1*2+c2*2);
			}
		}
		ll ans=min(dp[n][0]+w2*2,dp[n][1]+w2);
		cout<<ans<<endl;
	}
	return 0;
}