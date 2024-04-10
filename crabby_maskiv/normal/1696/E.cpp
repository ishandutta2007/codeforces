#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=4e5+5;
const int mod=1e9+7;
int n,m;
int fac[N],invf[N];
inline int po(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
inline int C(int x,int k){
	if(x<k) return 0;
	return 1ll*fac[x]*invf[k]%mod*invf[x-k]%mod;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invf[N-1]=po(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) invf[i]=invf[i+1]*ll(i+1)%mod;
	cin>>n;
	int ans=0;
	for(i=0;i<=n;i++){
		int x;cin>>x;
		ans=(ans+C(x+i,i+1))%mod;
	}
	cout<<ans;
	return 0;
}