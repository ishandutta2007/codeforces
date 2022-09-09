#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
long long n,k,i,a[500005],f[500005],ans;
int main(){
	ans=-0x7fffffffffffffffll;
	scanf("%lld%lld",&n,&k);k++;
	rep(i,n){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	for(i=n;i>=1;i--){
		long long t=(n-i)/k;
		f[i]=f[i+1]+t*a[i];
	}
	ans=f[1];
	long long s0=0,s1=0;
	rep(i,n){
		s1+=s0;
		s0+=a[i];
		ans=max(ans,s1+s0*((n-i+k-1)/k)+f[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}