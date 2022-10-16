#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll s[50005],f[50005],t;
ll len(ll x){
	ll to=1;
	for (ll i=1;i<=100;i++){
		to*=10;
		if (to>x)return i;
	}
	return 0;
}
ll work2(int x,int now){
	ll l=len(x);
	ll o=1;
	l-=now;
	for (int i=1;i<=l;i++)o*=10;
		return x/o%10;
}
ll work(ll now,ll x){
	ll m=x-f[now];
	ll i;
	for (i=1;i<=now;i++)
		if (s[i]>=m)break;
	m-=s[i-1];
	return work2(i,m);
}
int main(){
//	freopen("e.in","r",stdin);
//	freopen("e.out","w",stdout);
	for (ll i=1;i<=50000;i++)s[i]=s[i-1]+len(i);
	for (ll i=1;f[i-1]<=2147483647;i++)f[i]=f[i-1]+s[i];
	cin>>t;
	while(t--){
		ll x;
		cin>>x;
		ll i=1;
		while(f[i+1]<x)i++;
		if (x!=1)cout<<work(i,x)<<endl;
		else cout<<1<<endl;
	}
	return 0;
}