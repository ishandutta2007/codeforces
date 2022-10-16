#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll a[400005],s,ans=1;
int n;
ll gcd(ll x,ll y){
	if (y==0)return x;
	return gcd(y,x%y);
}
int main(){
//	freopen("1203C.in","r",stdin);
//	freopen("1203C.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	s=a[1];
	for (int i=1;i<=n;i++)s=gcd(s,a[i]);
	for (ll i=2;i*i<=s;i++){
		ll t=0;
		while(s%i==0)s/=i,t++;
		ans=ans*(t+1);
	}
	if (s>1)ans*=2;
	cout<<ans<<endl;
	return 0;
}