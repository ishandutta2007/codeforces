#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const ll Mod=1000000007,Mod2=998244353;
int t;
ll a,m;

ll euler(ll n){
	if(n==1) return 1;
	ll ans=n;
	ll y=sqrt(n)+2;
	ll z=n;
	y=min(n+1,y);
	rep2(i,2,y){
		if(z%i==0){
			ans=ans/i*(i-1);
		}
		while(z%i==0){
			z=z/i;
		}
		if(z==1) break;
	}
	if(z>1) ans=ans/z*(z-1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> m;
		m=m/__gcd(a,m);
		cout << euler(m) << '\n';
	}
	return 0;
}