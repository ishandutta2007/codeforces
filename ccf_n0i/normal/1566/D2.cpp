#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int n,m,vis[305][305],ans;
int a[90005],b[90005];
vector<int> lsh;
vector<pair<int,int> > v[90005];
/*bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first)return x.second>y.second;
	return x.first<y.first;
}*/
void solve(){
	int i,j;
	cin>>n>>m;
	lsh.clear();
	rep(i,n*m)cin>>a[i];
	rep(i,n*m)lsh.push_back(a[i]);
	sort(lsh.begin(),lsh.end());
	lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
	rep(i,n*m)b[i]=a[i]=upper_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin();
	sort(b+1,b+n*m+1);
	rep(i,lsh.size()) v[i].clear();
	rep(i,n)rep(j,m)vis[i][j]=0;
	for(i=n;i>=1;i--)rep(j,m) v[b[(i-1)*m+j]].push_back(make_pair(i,j));
	ans=0;
	rep(i,n*m){
		int x=v[a[i]].back().first;
		int y=v[a[i]].back().second;
		v[a[i]].pop_back();
		rep(j,y) ans+=vis[x][j];
		vis[x][y]=1;
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