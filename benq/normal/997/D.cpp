#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100001;

template<int SZ> struct Combo {
    ll fac[SZ+1], ifac[SZ+1];
    
    Combo() {
        fac[0] = ifac[0] = 1;
    	FOR(i,1,SZ+1) {
    	    fac[i] = i*fac[i-1] % MOD;
    	    ifac[i] = inv(fac[i]);
    	}
    }
    
    ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv (ll b) { return po(b,MOD-2); }
    
    ll comb(ll a, ll b) {
        if (a < b || b < 0 || a < 0) return 0;
        ll tmp = fac[a]*ifac[b] % MOD;
        tmp = tmp*ifac[a-b] % MOD;
        return tmp;
    }
};

Combo<100> C;

ll po (ll b, ll p) { return !p?1:po(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
ll inv (ll b) { return po(b,MOD-2); }

int ad(int a, int b) { if (a+b >= MOD) return a+b-MOD; return a+b; }
ll sub(ll a, ll b) { return (a-b+MOD)%MOD; }
ll mul(ll a, ll b) { return a*b%MOD; }
ll divi(ll a, ll b) { return mul(a,inv(b)); }

int n[2],k;
int oc[2][76];
vi adj[4001];

vi dfs(int ind, int cur, int pre) {
	vi sum(k+1), cnt(k+1), dp(k+1);
	for (int i: adj[cur]) if (i != pre) {
		vi DP = dfs(ind,i,cur);
		for (int i0 = 0; i0 <= k; i0 += 2) sum[i0] = ad(sum[i0],DP[i0]);
	}
	dp[0] = cnt[0] = 1;
	for (int i0 = 2; i0 <= k; i0 += 2)
		for (int i2 = 0; i2+2 <= i0; i2 += 2) {
			dp[i0] = ad(dp[i0],mul(sum[i2],dp[i0-i2-2]));
			if (i2+2 == i0) cnt[i0] = ad(cnt[i0],mul(sum[i2],i0));
			else cnt[i0] = ad(cnt[i0],mul(sum[i2],cnt[i0-i2-2]));
		}
		
	/*cout << cur << "\n";
	F0R(i,k+1) cout << cnt[i] << " ";
	cout << "\n";*/
	F0R(i,k+1) oc[ind][i] = ad(oc[ind][i],cnt[i]);
	return dp;
}

void gen(int ind) {
	FOR(i,1,n[ind]+1) adj[i].clear();
	F0R(i,n[ind]-1) {
		// int a = i+1,b = i+2; 
		int a,b; cin >> a >> b;
		adj[a].pb(b), adj[b].pb(a);
	}
	dfs(ind,1,0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n[0] >> n[1] >> k;
	gen(0);
	gen(1);
	ll ans = 0;
	F0R(i,k+1) ans = ad(ans,mul(C.comb(k,i),mul(oc[0][i],oc[1][k-i])));
	cout << ans;
}