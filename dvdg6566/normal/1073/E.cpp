#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 200010
ll MOD = 998244353;

pi memo[20][1030][2][2];
ll T,K;
string X;
ll p10[20];

pi dp(ll in, ll bm, ll flag, ll trail){
	// cerr<<"Query "<<in<<' '<<bm<<' '<<flag<<'\n';
	if (in == T){
		return mp(1,0);
	}
	if (memo[in][bm][flag][trail].f != -1)return memo[in][bm][flag][trail];

	ll left = K;
	for (ll i=0;i<=9;++i){
		if (((1<<i) & bm) > 0)--left;
	}
	//Left is number of available digits

	if (flag == 0){
		pi ans = mp(0,0);
		// Does not need to adhere to the previous
		for (ll p=0;p<=9;++p){
			if (p == 0 && trail){
				pi c = dp(in+1, bm, 0, 1);
				ans.s = (ans.s + c.s + p*c.f*p10[T-1-in]) %MOD; // Total sum
				ans.f += c.f; // Number of ways 
				continue;
			}

			ll cleft = left;
			if (((1<<p) & bm) == 0)--cleft;
			if (cleft < 0)continue;
			ll cbm = bm | (1<<p);

			pi c = dp(in+1,cbm,0,0);
			ans.s = (ans.s + c.s + p*c.f*p10[T-1-in]) %MOD; // Total sum
			ans.f = (ans.f+c.f)%MOD; // Number of ways 
		}

		// cerr<<"At "<<in<<' '<<bm<<' '<<flag<<' '<<trail<<" value "<<ans.f<<' '<<ans.s<<'\n';
		return memo[in][bm][flag][trail] = ans;
	}

	pi ans = mp(0,0);
	ll t = X[in]-'0';
	// Case 1 is when is equal
	ll cleft = left;
	if (((1<<t) & bm) == 0)--cleft;
	if (cleft >= 0){
		ll cbm = bm | (1<<t);
		pi c = dp(in+1,cbm,1,0);
		ans.s = (ans.s + c.s + (t*c.f)%MOD *p10[T-1-in]) %MOD; // Total sum
		ans.f = (ans.f+c.f)%MOD; // Number of ways 
	}

	for (ll i=0;i<t;++i){
		if (i == 0 && trail){
			pi c = dp(in+1, bm, 0, 1);
			ans.s = (ans.s + c.s) %MOD; // Total sum
			ans.f = (ans.f+c.f)%MOD; // Number of ways 
			continue;
		}
		ll cleft = left;
		if (((1<<i) & bm) == 0)--cleft;
		if (cleft >= 0){
			ll cbm = bm | (1<<i);
			pi c = dp(in+1,cbm,0,0);
			ans.s = (ans.s + c.s + (i*c.f)%MOD*p10[T-1-in]) %MOD; // Total sum
			ans.f = (ans.f+c.f)%MOD; // Number of ways 
		}
	}
	// cerr<<"At "<<in<<' '<<bm<<' '<<flag<<' '<<trail<<" value "<<ans.f<<' '<<ans.s<<'\n';
	return memo[in][bm][flag][trail] = ans;
}

ll query(string x){
	X = x;
	T = SZ(x);
	return dp(0LL, 0LL, 1LL, 1LL).s;
}

string L,R;

int main(){
	// freopen("in.txt","r",stdin);
	ll a;
	cin>>a>>R>>K;
	--a;

	while(a){
		L += (char) ((a%10)+'0');
		a /= 10;
	}

	reverse(ALL(L));

	p10[0]=1;
	for (ll i=1;i<20;++i)p10[i] = (p10[i-1]*10)%MOD;

	for (ll i=0;i<20;++i){
		for (ll j=0;j<1030;++j){
			for (ll k=0;k<2;++k)for (ll l=0;l<2;++l){
				memo[i][j][k][l].f=memo[i][j][k][l].s = -1;
			}
		}
	}
	ll p = query(R);

	// cout<<p<<'\n';
	for (ll i=0;i<20;++i){
		for (ll j=0;j<1030;++j){
			for (ll k=0;k<2;++k)for (ll l=0;l<2;++l){
				memo[i][j][k][l].f=memo[i][j][k][l].s = -1;
			}
		}
	}

	ll k = query(L);
	cout<<(p-k+MOD)%MOD;
}