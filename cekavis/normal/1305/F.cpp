#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, ans;
ll a[N];
void work(ll x){
	if(x==1) return;
	for(int i=2; (ll)i*i<=x; ++i) if(x%i==0){ work(x/i), x=i; break;}
	ll tot=0;
	for(int i=0; i<n; ++i){
		ll s;
		if(a[i]<x) s=x-a[i];
		else{
			s=a[i]%x;
			s=min(s, x-s);
		}
		if((tot+=s)>ans) return;
	}
	ans=tot;
}
int main() {
	mt19937 rng(chrono::system_clock().now().time_since_epoch().count());
	scanf("%d", &n), ans=n;
	for(int i=0; i<n; ++i) scanf("%lld", a+i);
	for(int i=0; i<20; ++i){
		ll x=a[rng()%n];
		for(int j=-1; j<=1; ++j) if(x+j>0) work(x+j);
	}
	printf("%d\n", ans);
	return 0;
}