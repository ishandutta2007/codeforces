#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,ans=1e12;
ll gcd(ll x,ll y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	cin>>x;
	for (ll i=1;i*i<=x;i++)
		if (x%i==0){
			if (gcd(i,x/i)!=1) continue;
			ans=min(ans,x/i);
		}
	cout<<x/ans<<" "<<ans;
}