#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",qpow(2,n+m));
	return 0;
}