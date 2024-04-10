#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
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

const int MOD = 1000000007;

const int MX = 200001;

int N, visit[MX], sub[MX], par[MX], hsh[MX];
ll ans[MX];
vi adj[MX], tmp, toErase;
int m[1<<20];

void dfs (int no) {
    sub[no] = 1;
    for (int i: adj[no]) if (!visit[i] && i != par[no]) {
        par[i] = no;
        dfs(i);
        sub[no] += sub[i];
    }
}

int get_centroid(int x) {
    par[x] = 0;
    dfs(x);
    int sz = sub[x];
    while (1) {
        pii mx = {0,0};
        for (int i: adj[x]) if (!visit[i] && i != par[x]) mx = max(mx,{sub[i],i});
        if (mx.f*2 > sz) x = mx.s;
        else return x;
    }
}

void DFS(int x, int pre, int cur, int ind, int t) {
    for (int i: adj[cur]) if (i != pre && !visit[i]) DFS(x,cur,i,ind^hsh[i],t);
    tmp.pb(ind);
}

ll ad(int x, int z) {
    ll t = 0;
    F0R(j,20) t += m[z^hsh[x]^(1<<j)];
    t += m[z^hsh[x]];
    return t;
}

ll DFS2(int x, int pre, int cur, int ind) {
    ll TMP = ad(x,ind);
    for (int i: adj[cur]) if (i != pre && !visit[i]) TMP += DFS2(x,cur,i,ind^hsh[i]);
    ans[cur] += TMP;
    return TMP;
}

void solve (int x) {
    x = get_centroid(x); visit[x] = 1;
    m[0] = 1; ans[x] ++;
    toErase.pb(0);
    for (int i: adj[x]) if (!visit[i]) {
        tmp.clear();
        DFS(x,x,i,hsh[i],1);
        for (int z: tmp) ans[x] += ad(x,z);
        for (int z: tmp) m[z] ++, toErase.pb(z);
    }
    for (int i: adj[x]) if (!visit[i]) {
        tmp.clear();
        DFS(x,x,i,hsh[i],-1);
        for (int i: tmp) m[i] --;
        DFS2(x,x,i,hsh[i]);
        tmp.clear();
        DFS(x,x,i,hsh[i],1);
        for (int i: tmp) m[i] ++;
    }
    for (int i: toErase) m[i] = 0;
    toErase.clear();
    
    for (int i: adj[x]) if (!visit[i]) solve(i);
}

int main() {
	cin >> N;
	F0R(i,N-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b), adj[b].pb(a);
	}
	FOR(i,1,N+1) {
	    char c; cin >> c;
	    hsh[i] = 1<<(c-'a');
	}
	solve(1);
	FOR(i,1,N+1) cout << ans[i] << " ";
} // OK