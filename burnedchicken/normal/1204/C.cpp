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
int n,m,a[1000005],dist[105][105],x;
bool adj[105][105];
char c;
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) rep1(j,n) cin >> c, adj[i][j]=(c=='1'?true:false);
	cin >> m;
	rep(m) cin >> a[i];
	rep(n) rep1(j,n) dist[i][j]=1e9;
	rep(n) dist[i][i]=0;
	rep(n) rep1(j,n) if(adj[i][j]) dist[i][j]=1;
	rep1(k,n){
		rep(n){
			rep1(j,n){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	x=0;
	ans.pb(a[0]);
	rep(m){
		if(dist[a[x]-1][a[i]-1]<i-x){
			x=i-1;
			ans.pb(a[i-1]);
		}
	}
	ans.pb(a[m-1]);
	print1(ans.size());
	printvec(ans);
	return 0;
}