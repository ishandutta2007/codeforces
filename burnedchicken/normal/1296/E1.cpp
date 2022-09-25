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

using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

ll Pow(ll a, ll b){
	if(!b) return 1;
	ll z=Pow(a*a%MOD,b>>1);
	return (b&1?z*a%MOD:z);
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
ll fact(ll n){return (n?fact(n-1)*n%MOD:1);}
ll C(ll n, ll m){
	if(n<m) return 0;
	if(m==0) return 1;
	return C(n,m-1)*(n-m+1)%MOD*inverse(m)%MOD;
}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll v2(ll n){return ((n&1)?0:v2(n>>1)+1);}

//i_am_noob
int n,ans[200005],x,l,r,tmp;
vector<int> vec;
string str;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> str;
	rep(n){
		x='a'-str[i];
		if(vec.empty()){
			ans[i]=1;
			vec.pb(x);
		}
		else if(vec.back()<x){
			vec.pb(x);
			ans[i]=vec.size();
		}
		else{
			l=0,r=vec.size()-1;
			while(l!=r){
				tmp=(l+r)/2;
				if(vec[tmp]>=x) r=tmp;
				else l=tmp+1;
			}
			ans[i]=l+1;
			vec[l]=x;
		}
	}
	if(vec.size()>2) print1("NO");
	else{
		print1("YES");
		rep(n) cout << ans[i]-1;
		cout << '\n';
	}
	return 0;
}