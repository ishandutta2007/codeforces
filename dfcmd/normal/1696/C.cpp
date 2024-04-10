#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,v,a[N],b[N];
vector<pair<int,ll> > calc(int *a,int n){
	vector<pair<int,ll> > ans;
	for(int i=1;i<=n;++i){
		ll c=1;int x=a[i];
		while(x%v==0)x/=v,c*=v;
		if(ans.empty()||ans.back().first^x){
			ans.push_back({x,c});
		}
		else{
			ans.back().second+=c;
		}
	}
	return ans;
}
void Solve(){
	cin>>n>>v;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
	}
	cout<<(calc(a,n)==calc(b,m)?"Yes\n":"No\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}