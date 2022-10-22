#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+5;
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
inline int C(int x,int y){
	if(x<y) return 0;
	return 1ll*fac[x]*invf[y]%mod*invf[x-y]%mod;
}
ll row[N],ans[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%mod;
	invf[N-1]=po(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) invf[i]=ll(i+1)*invf[i+1]%mod;
	int iv3=po(3,mod-2);
	cin>>n>>m;n*=3;
	ans[0]=n/3+1;
	ans[1]=(ll(3+n)*n/6)%mod;
	for(i=0;i<=n;i++) row[i]=C(n+1,i+1);
	for(i=2;i<=n;i++){
		ll w=row[i]+2*row[i-1]+row[i-2]-3*ans[i-1]-ans[i-2];
		w=(w%mod+mod)%mod;
		ans[i]=iv3*w%mod;
	}
	while(m--){
		int x;cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}