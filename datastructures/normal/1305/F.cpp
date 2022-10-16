#include <iostream>
#include <cstdio>
#include <random>
#define ll long long
using namespace std;
int n,ans=1e9;
ll a[1000005];
mt19937 rnd(19260817);
int rnd_num(int w){
	return (rnd()%w+w)%w;
}
void upd(ll x){
	ll now=0;
	for (int i=1;i<=n;i++){
		ll val=x-a[i]%x;
		if (a[i]>=x)val=min(val,a[i]%x);
		now+=val;
	}
	if (now<=n)ans=min(ans,(int)now);
	return;
}
void solve(ll x){
	if (x<2)return;
	for (ll i=2;i*i<=x;i++){
		if (x%i!=0)continue;
		upd(i);
		while(x%i==0)x/=i;
	}
	if (x>1)upd(x);
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=30;i++){
		int pos=rnd_num(n);
		solve(a[pos]);
		solve(a[pos]+1);
		if (a[pos]>1)solve(a[pos]-1);
	}
	cout<<ans<<endl;
	return 0;
}