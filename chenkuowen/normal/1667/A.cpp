#include<bits/stdc++.h>
using namespace std;
const int N=5005;
typedef long long ll;
int a[N],n;
ll solve(int x){
	static ll b[N];
	b[x]=0; ll ans=0;
	for(int i=x+1;i<=n;++i){
		ll k=b[i-1]/a[i]+1;
		ans+=k;
		b[i]=1ll*k*a[i];
	}
	for(int i=x-1;i>=1;--i){
		ll k=b[i+1]/a[i]+1;
		ans+=k;
		b[i]=1ll*k*a[i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	ll ans=(ll)1e18;
	for(int i=1;i<=n;++i)
		ans=min(ans,solve(i));
	printf("%lld\n",ans);
	return 0;
}