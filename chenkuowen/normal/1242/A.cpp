#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
int main(){
	ll n; scanf("%lld",&n);
	for(ll i=2;i*i<=n;++i)
		if(n%i==0){
			a.push_back(i);
			while(n%i==0)n/=i;
		}
	if(n>1) a.push_back(n);
	if(a.size()==0) puts("1");
	else if(a.size()==1) printf("%lld\n",a[0]);
	else puts("1");
	return 0;
}