#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m;
int a[N],x[N];
vector<pii> v[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];x[i]=a[i];
	}
	sort(x+1,x+n*m+1);
	for(i=1;i<=n*m;i++)
		a[i]=lower_bound(x+1,x+n*m+1,a[i])-x;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			v[a[(i-1)*m+j]].push_back({i,j});
	}
	ll ans=0;
	for(i=1;i<=n*m;i++){
		if(v[i].empty()) continue;
		sort(v[i].begin(),v[i].end());
		int t=v[i].size();
		for(j=0;j<t;j++)
			ans+=1ll*(j*2-t+1)*v[i][j].fr;
		for(j=0;j<t;j++) swap(v[i][j].fr,v[i][j].sc);
		sort(v[i].begin(),v[i].end());
		for(j=0;j<t;j++)
			ans+=1ll*(j*2-t+1)*v[i][j].fr;
	}
	cout<<ans;
	return 0;
}