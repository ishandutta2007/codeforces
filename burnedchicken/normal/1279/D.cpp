#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)

using namespace std;
 
const ll Mod=1000000007,Mod2=998244353;
ll n,k,x,y,z,prob[1000005]={0},cnt[1000005]={0},ans=0;
 
ll Pow(ll a, ll b, ll mod){
	ll y=1;
	ll z=a%mod;
	while(b>0){
		if((b&1ll)==1){
			y=(y*z)%mod;
			b--;
		}
		b=(b>>1);
		z=(z*z)%mod;
	}
	return y;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	z=Pow(n,Mod2-2,Mod2);
	rep(n){
		cin >> k;
		y=(z*Pow(k,Mod2-2,Mod2))%Mod2;
		rep1(j,k){
			cin >> x;
			x--;
			prob[x]=(prob[x]+y)%Mod2;
			cnt[x]++;
		}
	}
	rep(1000005){
		ans=(ans+prob[i]*(z*cnt[i]%Mod2))%Mod2;
	}
	cout << ans << '\n';
	return 0;
}