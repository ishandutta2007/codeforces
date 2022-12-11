#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,int b){return b?gcd(b,a%b):a;}
long long lcm(long long a,int b){return a/gcd(a,b)*b;}
int main(){
	int t; cin>>t; while(t--){
		long long n,ans=0,g=1;
		scanf("%lld",&n);
		for(int i=2;n>=g;++i)ans+=(n/g-n/lcm(g,i))*i%1000000007,g=lcm(g,i);
		printf("%lld\n",ans%1000000007);
	}
}