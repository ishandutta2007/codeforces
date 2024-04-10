#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,inv2=499122177;
int n,m,l,r;
int power(int x,long long y){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&l,&r);
	if((1ll*n*m)&1)printf("%d\n",power(r-l+1,1ll*n*m));
	else{
		printf("%d\n",1ll*(power(r-l+1,1ll*n*m)+((l+r)&1?0:1))*inv2%mod);
	}
	return 0;
}