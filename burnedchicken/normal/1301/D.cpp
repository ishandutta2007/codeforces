#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
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
const ll MOD=Mod2;

ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
ll v2(ll n){return ((n&1)?0:v2(n>>1)+1);}

const int maxn=100005;
//i_am_noob
int n,m,k;
vector<pair<int,string> > vec;

void noob(){
	print1("YES");
	print1(vec.size());
	rep(vec.size()) print2(vec[i].first,vec[i].second);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> k;
	if(k>4*n*m-2*n-2*m){
		print1("NO");
		return 0;
	}
	rep(2){
		if(k<m-1){
			if(k>0) vec.pb(mp(k,i==0?"R":"L"));
			noob();
			return 0;
		}
		if(m>1) vec.pb(mp(m-1,i==0?"R":"L"));
		k-=m-1;
	}
	rep(n-1){
		if(k<1){
			noob();
			return 0;
		}
		vec.pb(mp(1,"D"));
		k--;
		if(k<3*m-3){
			if(k/3>0) vec.pb(mp(k/3,"RUD"));
			if(k%3>=1) vec.pb(mp(1,"R"));
			if(k%3>=2) vec.pb(mp(1,"U"));
			noob();
			return 0;
		}
		if(m>1) vec.pb(mp(m-1,"RUD"));
		k-=3*m-3;
		if(k<m-1){
			if(k>0) vec.pb(mp(k,"L"));
			noob();
			return 0;
		}
		if(m>1) vec.pb(mp(m-1,"L"));
		k-=m-1;
	}
	if(k<n-1){
		if(k>0) vec.pb(mp(k,"U"));
		noob();
		return 0;
	}
	if(n>1) vec.pb(mp(n-1,"U"));
	noob();
	return 0;
}