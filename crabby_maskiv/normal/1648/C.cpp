#include<bits/stdc++.h>
#define fr first
#define sc second
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
const int mod=998244353;
int n,m;
int a[N],b[N];
int d[N];
int c[N];
int fac[N],invf[N];
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*x*res%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invf[N-1]=po(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) invf[i]=ll(i+1)*invf[i+1]%mod;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	for(i=1;i<=n;i++) c[a[i]]++;
	int w=fac[n];
	for(i=1;i<N;i++){
		w=1ll*w*invf[c[i]]%mod;
		for(j=i;j<N;j+=lbt(j))
			d[j]=(d[j]+c[i])%mod;
	}
	int ans=0;
	for(i=1;i<=min(n,m);i++){
		int s=0;
		for(j=b[i]-1;j;j-=lbt(j)) s=(s+d[j])%mod;
		w=1ll*w*po(n-i+1,mod-2)%mod;
		ans=(ans+1ll*s*w)%mod;
		if(!c[b[i]]){
			cout<<ans;
			return 0;
		}
		w=1ll*w*c[b[i]]%mod;
		c[b[i]]--;
		for(j=b[i];j<N;j+=lbt(j))
			d[j]--;
	}
	ans=(ans+(m>n))%mod;
	cout<<ans;
	return 0;
}