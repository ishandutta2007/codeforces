#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int n,m,a[25][50005],c[25],ans;
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int x){
	return Qpow(x,mod-2); 
}
signed main(){
	cin>>n>>m;
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=m;j++)
			scanf("%lld",&a[i][j]);
	for (register int i=1;i<=m;i++){
		for (register int j=1;j<=n;j++)c[j]=n+2-a[j][i];
		register int now=1;
		sort(c+1,c+1+n);
		for (register int j=n;j>=1;j--){
			if (c[j]>j){
				now=0;
				break;
			}
			now=now*(j-c[j]+1)%mod;
		}
		for (register int j=1;j<=n;j++)now=now*inv(j)%mod;
		ans=(ans+(1-now)%mod+mod)%mod;
	} 
	cout<<ans<<endl;
	return 0;
}