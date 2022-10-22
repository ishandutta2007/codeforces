#include <bits/stdc++.h> 
using namespace std;
const int N=20;
int n;
long long f[N];
const int MOD=1000000007;
int inv(int a){
	return a==1?1:(long long)(MOD-MOD/a)*inv(MOD%a)%MOD; 
}
long long choose(long long s,long long n){
	long long ret=1;
	for (int i=0;i<n;++i){
		ret=(long long)ret*((s-i)%MOD)%MOD*inv(i+1)%MOD;
	}
	return ret;
}
long long go(int i,long long s){
	if (s<0){
		return 0;
	}
	if (i==n){
		return choose(s+n-1,n-1);
	}
	return (go(i+1,s)-go(i+1,s-f[i]))%MOD;
}
long long s;
int main(){
	cin>>n>>s;
	for (int i=0;i<n;++i){
		cin>>f[i];
		++f[i];
	}
	cout<<(go(0,s)+MOD)%MOD<<endl;
	return 0;
}