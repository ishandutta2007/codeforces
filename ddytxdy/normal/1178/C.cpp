#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int power(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",power(2,n+m));
	return 0;
}