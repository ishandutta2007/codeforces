#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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

const int MOD = 1000000007;

int n,m, visit[100001], co[2][60];
ll ans, dist[100001], po2[120];
vector<pll> adj[100001];
vector<ll> posi;
queue<int> todo; 

vector<ll> gen(vector<ll> p) {
    vector<ll> ret;
    F0Rd(i,60) {
        ll des = 0;
        F0R(j,p.size()) if (p[j]&(1LL<<i)) des = p[j];
        if (des) {
            ret.pb(des);
            F0R(j,p.size()) if (p[j]&(1LL<<i)) p[j] ^= des;
        }
    }
    return ret;
}

void solve(int ind) {
    memset(co,0,sizeof co); posi.clear();
    todo.push(ind); visit[ind] = 1;
    
    while (todo.size()) {
        int x = todo.front(); todo.pop();
        F0R(i,60) {
            if (dist[x]&(1LL<<i)) co[1][i] ++;
            else co[0][i] ++;
        }
        for (pll y: adj[x]) {
            if (!visit[y.f]) {
                visit[y.f] = 1;
                dist[y.f] = y.s^dist[x];
                todo.push(y.f);
            } else posi.pb(dist[y.f]^dist[x]^y.s);
        }
    }
    
    posi = gen(posi);
    ll tmp = 0; for (ll x: posi) tmp |= x;
    
    F0R(i,60) {
        if (tmp&(1LL<<i)) {
            ll t = po2[posi.size()-1+i];
            t = t*(co[1][i]+co[0][i]) % MOD;
            t = t*(co[1][i]+co[0][i]-1) % MOD;
            t = t*(MOD+1)/2 % MOD;
            ans = (ans+t) % MOD;
        } else {
            ll t = po2[posi.size()+i];
            t = t*co[1][i] % MOD;
            t = t*co[0][i] % MOD;
            ans = (ans+t) % MOD;
        }
    }
    // then generate cycle lengths
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	po2[0] = 1;
	FOR(i,1,120) po2[i] = 2*po2[i-1] % MOD;
	
	cin >> n >> m;
	F0R(i,m) {
	    ll u,v,t; cin >> u >> v >> t;
	    adj[u].pb({v,t});
	    adj[v].pb({u,t});
	}
}

int main() {
    init();
	FOR(i,1,n+1) if (!visit[i]) solve(i);
	cout << ans;
}

// read!
// ll vs. int!