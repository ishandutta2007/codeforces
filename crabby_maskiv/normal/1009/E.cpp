#include<bits/stdc++.h>
#define inv(x) (po(x,mod-2))
using namespace std;
typedef long long ll;
const int N=1000005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll p[N];
ll a[N];
ll po(ll x,ll k){
	if(!k) return 1ll;
	ll s=po(x,k>>1);s=(s*s)%mod;
	if(k&1) return s*x%mod;
	else return s;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	p[0]=1;
	for(i=1;i<=n;i++) p[i]=(p[i-1])*2%mod;
	for(i=1;i<=n;i++) p[i]=inv(p[i]);
	ll ans=0;
	for(i=1;i<=n;i++){
		ans+=(p[i]*a[i])%mod*(n-i+2);
		ans%=mod;
	}
	cout<<(ans*inv(p[n-1]))%mod;
	return 0;
}