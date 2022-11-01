#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int len = 0;
ll factor[27];
ll a[27];
int ti[27];
ll calc() {
/*
for(int i  = 1;i <= len;i++) {
	cout<<a[i]<<" ";
}cout<<endl;
*/
	memset(ti,0,sizeof(ti));
	for(int i = 1;i <= len;i++) {
		ti[a[i]]++;
	}
	ll res = 1;
	for(int i = 1;i <= len;i++) {
		if(a[i] > i) return 0;
	}
	//cout<<len<<" sue"<<endl;
	//cout<<res<<" ";
	for(int i = 2;i <= len;i++) {
		ll t = a[i];
		t = max(t,1ll);
		res = res * (i + 1 - t);
		//cout<<res<<" ";
	}
	//cout<<endl;
	//cout<<res<<endl;
	for(int i = 0;i <= 19;i++) {
		res = res / factor[ti[i]];
	}
	//cout<<res<<endl;
	return res;
}
ll work() {
	ll x;
	len = 0;
	scanf("%lld",&x);
	for(int i = 2;i <= 20 && x != 0;i++) {
		a[++len] = x % i;
		x = x / i;
	}
	stable_sort(a + 1,a + len + 1);
	ll ans1 = calc();
	if(a[1] != 0) return ans1;
	for(int i = 1;i < len;i++) {
		a[i] = a[i + 1];
	}
	len--;
	ll ans2 = calc();
	return ans1 - ans2;
}
int main(){
	factor[0] = 1;
	for(int i = 1;i <= 19;i++) {
		factor[i] = factor[i - 1] * i;
	}
	int t;
	scanf("%d",&t);
	while(t--) {
		printf("%lld\n",work() - 1);
	}
	
	return 0;
}