#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=1004535809ll;
int n,m;
int dp[N];
inline void add(int x){
	for(int i=N-1;i>=x;i--) dp[i]=(dp[i]+dp[i-x])%mod;
}
inline void del(int x){
	for(int i=x;i<N;i++) dp[i]=(dp[i]-dp[i-x]+mod)%mod;
}
vector<int> v[N];
int cnt[N];
int main(){
	int i,j;
	cin>>n>>m;
	dp[0]=1;
	for(i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		v[x].push_back(z);
		v[y+1].push_back(-z);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<v[i].size();j++){
			int k=v[i][j];
			if(k>0) add(k);
			else del(-k);
		}
		for(j=1;j<N;j++) if(dp[j]) cnt[j]++;
	}
	int ans=0;
	for(i=1;i<=n;i++) ans+=bool(cnt[i]);
	cout<<ans<<endl;
	for(i=1;i<=n;i++) if(cnt[i]) cout<<i<<" ";
	return 0;
}