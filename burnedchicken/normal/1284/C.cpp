#include <bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))

using namespace std;

const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,m;
	cin >> n >> m;
	ll ans=0;
	ll x;
	ll fact[n+1];
	fact[0]=1;
	loop(n) fact[i+1]=(fact[i]*(i+1))%m;
	for(int i=1; i<=n; i++){
		x=((n-i+1)*(n-i+1))%m;
		x=(x*fact[i])%m;
		x=(x*fact[n-i])%m;
		ans=(ans+x)%m;
	}
	cout << ans << "\n";
	return 0;
}

/*
1~n len m
(n-m+1)(n-m+1)m!(n-m)!

*/