#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
long long f[1333333][2],ans;
void solve(){
	ans=-0x7fffffffffffffffll;
	int n,m,k=0,i;
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%lld",&f[i][0]),f[i][1]=-f[i][0];
	rep(i,m){
		int x;
		scanf("%d",&x);
		k=__gcd(k,x);
	}
	rep(i,n-k){
		long long n0=max(f[i][0]+f[i+k][0],f[i][1]+f[i+k][1]);
		long long n1=max(f[i][1]+f[i+k][0],f[i][0]+f[i+k][1]);
		f[i+k][0]=n0;
		f[i+k][1]=n1;
	}
	long long sum=0;
	rep(i,k) sum+=f[n-i+1][0];
	ans=max(ans,sum);
	sum=0;
	rep(i,k) sum+=f[n-i+1][1];
	ans=max(ans,sum);
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}