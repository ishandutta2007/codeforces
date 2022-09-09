#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int n,m,vis[305],ans,id[305];
pair<int,int> a[305];
void solve(){
	int i,j;
	cin>>n>>m;
	rep(i,m)cin>>a[i].first;
	rep(i,m)a[i].second=-i;
	sort(a+1,a+m+1);
	rep(i,m)vis[i]=0;
	ans=0;
	rep(i,m){
		id[-a[i].second]=i;
	}
	rep(i,m){
		rep(j,id[i])ans+=vis[j];
		vis[id[i]]=1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}