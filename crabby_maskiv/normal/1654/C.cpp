#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
ll a[N];
multiset<ll> s;
void solve(){
	sort(a+1,a+n+1);
	int i,j;
	int pos=n;
	ll sum=0;
	for(i=1;i<=n;i++) sum+=a[i];
	s.insert(sum);
	while(pos){
		if(s.size()>pos){
			cout<<"NO"<<endl;
			return;
		}
		auto it=s.end();it--;
		ll x=(*it);s.erase(it);
		if(x<a[pos]){
			cout<<"NO"<<endl;
			return;
		}
		if(x==a[pos]) pos--;
		else{
			s.insert(x+1>>1);
			s.insert(x>>1);
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		solve();
		s.clear();
	}
	return 0;
}