#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
int main(){
	int n,m; cin>>n>>m;
	printf("%d\n",fpow(2,n+m));
	return 0;
}