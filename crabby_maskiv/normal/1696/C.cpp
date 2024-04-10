#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=2e5+5;
int n,k;
ll m;
ll a[N],b[N];
pll fa[N],fb[N];
int ca,cb;
void solve(){
	int i,j;
	for(i=1;i<=n;i++){
		ll t=1;while(a[i]%(t*m)==0) t*=m;
		ll f=a[i]/t;
		while(ca&&fa[ca].fr==f){
			t+=fa[ca].sc;
			ca--;
		}
		ca++;
		fa[ca].fr=f;
		fa[ca].sc=t;
	}
	for(i=1;i<=k;i++){
		ll t=1;while(b[i]%(t*m)==0) t*=m;
		ll f=b[i]/t;
		while(ca&&fb[cb].fr==f){
			t+=fb[cb].sc;
			cb--;
		}
		cb++;
		fb[cb].fr=f;
		fb[cb].sc=t;
	}
	if(ca!=cb){
		cout<<"No"<<endl;
		return;
	}
	for(i=1;i<=ca;i++)
		if(fa[i]!=fb[i]){
			cout<<"No"<<endl;
			return;
		}
	cout<<"Yes"<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		cin>>k;
		for(i=1;i<=k;i++) cin>>b[i];
		ca=cb=0;
		solve();
	}
	return 0;
}