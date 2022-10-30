#include<bits/stdc++.h>
#define int long long
const int mod=1000000007;
using namespace std;

int n,k,t;
int gsc(int a,int b){
	int ans=1;
	for(int i=1;i<=b;i<<=1,a=a*a%mod)
		if(b&i)
			ans=ans*a%mod;
	return ans;
}

main(){
	scanf("%lld",&t);
	while(t--)
	scanf("%lld%lld",&n,&k),printf("%lld\n",gsc(n,k));
}