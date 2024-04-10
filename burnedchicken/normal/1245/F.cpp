#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const ll mod=1e9+7;

ll c(ll n, ll m){
	if(n<m) return 0;
	if(n==1) return 1;
	if(m==0||m==n) return 1;
	if(m==1||m==n-1) return n;
	ll x=1;
	ll t=1;
	loop(m){
		x=x*(n-i);
		while(x%t==0&&t<=m){
			x=x/t;
			t++;
		}
	}
	return x;
}

ll dgts(ll n){
	ll n1=n;
	ll x=0;
	while(n1>0){
		n1=n1/2;
		x++;
	}
	return x;
}

ll cnt(ll n, ll m){//num of nums with popcount m in 0~n
	if(m==0) return 1;
	if(m==1) return dgts(n);
	if(n==0) return 0;
	if(m>dgts(n)) return 0;
	ll x=dgts(n)-1;
	ll y=n-pow(2,x);
	return c(x,m)+cnt(y,m-1);
}

ll goodcnt(ll m, ll n){//num of good pairs with form (0~m,0~n), m<=n
	if(m==0) return n+1;
	ll a=dgts(m)-1;
	ll b=dgts(n)-1;
	ll ans=pow(3,a)*pow(2,b-a);
	ll x=m-pow(2,a);
	ll y=n-pow(2,b);
	ll k;
	if(a==b){
		loop(b+1){
			k=cnt(x,i);
			k=k*pow(2,b-i);
			ans=ans+k;
		}
		loop(a+1){
			k=cnt(y,i);
			k=k*pow(2,a-i);
			ans=ans+k;
		}
		return ans;
	}
	loop(b){
		k=cnt(x,i);
		k=k*pow(2,b-i-1);
		ans=ans+k;
	}
	if(m<=y) return ans+goodcnt(m,y);
	return ans+goodcnt(y,m);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll t,l,r,ans;
	cin >> t;
	loop(t){
		cin >> l >> r;
		if(l==0) ans=goodcnt(r,r);
		else ans=goodcnt(r,r)-2*goodcnt(l-1,r)+goodcnt(l-1,l-1);
		//cout << goodcnt(r,r) << endl << goodcnt(l-1,r) << endl << goodcnt(l-1,l-1) << endl;
		cout << ans << endl;
	}
	return 0;
}