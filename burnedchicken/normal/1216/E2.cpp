#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
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
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define printvec(a) rep(a.size()) print0(a[i])
#define debug(a) print2(#a,a)

using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

ll Pow(ll a, ll b){
	if(!b) return 1;
	ll x=Pow(a*a%MOD,b>>1);
	return (b&1?x*a%MOD:x);
}
vector<ll> prime_factors(ll n){
	ll m=n;
	vector<ll> ret;
	rep2(i,2,n){
		while(m%i==0){
			if(ret.empty()) ret.pb(i);
			else if(ret.back()!=i) ret.pb(i);
			m/=i;
		}
		if(m==1||1ll*i*i>n) break;
	}
	if(m>1) ret.pb(m);
	return ret;
}
ll euler(ll n){
	vector<ll> vec=prime_factors(n);
	ll ret=n;
	rep(vec.size()) ret=ret/vec[i]*(vec[i]-1);
	return ret;
}
ll inverse(ll n){return Pow(n,MOD-2);}
ll C(ll n, ll m){
	if(n<m) return 0;
	if(m==0) return 1;
	return C(n,m-1)*(n-m+1)%MOD*inverse(m)%MOD;
}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
ll v2(ll n){return ((n&1)?0:v2(n>>1)+1);}

//i_am_noob
int q;
ll n,l,r,mid,tmp;

ll power(ll x, ll y){return (y?power(x,y-1)*x:1);}
ll cnt1(ll x){//length of first x blocks
	if(x<=0) return 0;
	ll ret=0;
	int y=dgts(x,10);
	ll z;
	rep2(i,1,y){
		z=9*power(10,i-1);
		ret+=i*(z*(x-power(10,i)+1)+(z*(z+1)>>1));
	}
	z=x-power(10,y-1)+1;
	ret+=y*(z*(z+1)>>1);
	return ret;
}
ll cnt2(ll x){return cnt1(x)-cnt1(x-1);}//length of the xth block

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> q;
	while(q--){
		cin >> n;
		l=0,r=1e9;
		while(l!=r){
			mid=l+r+1>>1;
			if(cnt1(mid)<n) l=mid;
			else r=mid-1;
		}
		n=n-cnt1(l);
		l=0,r=1e9;
		while(l!=r){
			mid=l+r+1>>1;
			if(cnt2(mid)<n) l=mid;
			else r=mid-1;
		}
		n=n-cnt2(l);
		tmp=l+1;
		while(dgts(tmp,10)>n){
			tmp=tmp/10;
		}
		print1(tmp%10);
	}
	return 0;
}