#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1000000007ll;
int n,m;
ll l;
double w;
bool check(ll a,ll b){
	double x=(a+b)/2.0;
	double y=x-a;
	return (y>0)&&(y*w>x)&&(y*w>-x);
}
vector<ll> v1,v2;
int main() {
	int i,j;
	cin>>n>>l>>w;
	for(i=1;i<=n;i++){
		ll x,v;cin>>x>>v;
		if(v<0) v2.push_back(x+l);
		else v1.push_back(x);
	}
	if(!v1.size()||!v2.size()){
		cout<<0;
		return 0;
	}
	sort(v2.begin(),v2.end());
	ll ans=0;
	for(auto v:v1){
		int l=0,r=v2.size()-1;
		while(r>l){
			int mid=(l+r)>>1;
			if(check(v,v2[mid])) r=mid;
			else l=mid+1;
		}
		ans+=v2.size()-l;
		if(!check(v,v2[l])) ans--;
	}
	cout<<ans;
    return 0;
}