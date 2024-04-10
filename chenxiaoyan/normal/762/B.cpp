/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int n,m,s,t;
vector<int> v[2];
signed main(){
	cin>>n>>m>>s>>t;
	v[0].pb(0);v[1].pb(0);
	while(t--){
		int x;char a[10];
		scanf("%lld%s",&x,a);
		v[a[0]=='P'].pb(x);
	}
	sort(v[0].begin(),v[0].end());
	for(int i=1;i<v[0].size();i++)v[0][i]+=v[0][i-1];
	sort(v[1].begin(),v[1].end());
	for(int i=1;i<v[1].size();i++)v[1][i]+=v[1][i-1];
	int x=0,y=0;
	for(int i=0;i<v[0].size()&&i<=n+s;i++){
		if(i+min(s-max(0ll,i-n)+m,v[1].size()-1ll)>x)
			x=i+min(s-max(0ll,i-n)+m,v[1].size()-1ll),y=v[0][i]+v[1][min(s-max(0ll,i-n)+m,v[1].size()-1ll)];
		if(i+min(s-max(0ll,i-n)+m,v[1].size()-1ll)==x)
			y=min(y,v[0][i]+v[1][min(s-max(0ll,i-n)+m,v[1].size()-1ll)]);
	}
	cout<<x<<" "<<y;
	return 0;
}