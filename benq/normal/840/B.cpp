/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,m, d[300001], ans[300001], sum = 0;
int hei[300001];
vector<pii> adj[300001];
vi ra;
int par[300001];

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,n+1) {
	    cin >> d[i];
	    if (d[i] >= 0) sum += d[i];
	    else ra.pb(i);
	}
	for (int i: ra) d[i] = 0;
}

int getpar(int x) {
    if (par[par[x]] != par[x]) par[x] = getpar(par[x]);
    return par[x];
}

void unite(int a, int b, int c) {
    int a1 = getpar(a), b1 = getpar(b);
    if (a1 == b1) return;
    if (hei[a1] < hei[b1]) swap(a1,b1);
    par[b1] = a1;
    hei[a1] = max(hei[a1],hei[b1]+1);
    adj[a].pb({b,c});
    adj[b].pb({a,c});
}

void dfs(int p, int no) {
    for (pii a: adj[no]) if (a.f != p) {
        dfs(no,a.f);
        if (d[a.f]) d[a.f] ^= 1, d[no] ^= 1, ans[a.s] = 1;
    }
}

int main() {
    init();
	if (sum % 2 == 1) {
	    if (ra.size() == 0) {
	        cout << -1;
	        return 0;
	    }
	    d[ra[0]] = 1;
	}
	FOR(i,1,n+1) par[i] = i;
	FOR(i,1,m+1) {
	    int a,b; cin >> a >> b;
	    unite(a,b,i);
	}
	dfs(0,1);
	int k = 0;
	FOR(i,1,m+1) if (ans[i]) k++;
	cout << k << "\n";
	FOR(i,1,m+1) if (ans[i]) cout << i << "\n";
}

// read!
// ll vs. int!