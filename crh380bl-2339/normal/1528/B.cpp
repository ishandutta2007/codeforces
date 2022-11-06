#include<bits/stdc++.h>
#define N 1000000
#define mod 998244353
using namespace std;
int d[N+2],s[N+2];
int main(){
	int i,j;
	for(i=1;i<=N;++i){
		for(j=i;j<=N;j+=i)++d[j];
		s[i]=(2LL*s[i-1]%mod+d[i])%mod;
	}
	int n;scanf("%d",&n);
	printf("%d\n",(s[n]-s[n-1]+mod)%mod);
	return 0;
}