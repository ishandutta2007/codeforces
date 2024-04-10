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

int n, par[200001], visit[200001], depth[200001], incycle[200001];
ll pos[400005];
map<int,vi> adj[200001];
vi cy, cy1;
vector<pair<int,pair<ll,ll>>> c;
pii bad;
ll mn = 0, ans = 1e18;

void dfs(int p, int node) {
    par[node] = p; visit[node] = 1;
    depth[node] = depth[p]+1;
    for (pair<int,vi> a: adj[node]) for (int x: a.s) if (a.f != p) {
        if (visit[a.f]) bad = {a.f,node};
        else dfs(node,a.f);
    }
}

void init() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    int u,v,l; cin >> u >> v >> l;
	    adj[u][v].pb(l);
	    adj[v][u].pb(l);
	}
	dfs(0,1);
}

ll get(int p, int x) {
    multiset<ll> z;
    for (pair<int,vi> a: adj[x]) if (a.f != p && incycle[a.f] == 0) z.insert(get(x,a.f)+a.s[0]);
    if (z.size() == 0) return 0LL;
    
    ll tmp = *prev(z.end());
    if (z.size() > 1) tmp += *prev(prev(z.end()));
    mn = max(mn,tmp);
    return *prev(z.end());
}

void gencycle() {
    while (bad.f != bad.s) {
        if (depth[bad.f] > depth[bad.s]) {
            cy.pb(bad.f);
            bad.f = par[bad.f];
        } else {
            cy1.pb(bad.s);
            bad.s = par[bad.s];
        }
    }    
    cy.pb(bad.f);
    reverse(cy1.begin(),cy1.end());
    for (int i: cy1) cy.pb(i);
    if (cy.size() > 2) {
        F0R(i,cy.size()) 
            c.pb({cy[i],{adj[cy[i]][cy[(i+1)%cy.size()]][0],0}});
    } else {
        c.pb({cy[0],{adj[cy[0]][cy[1]][0],0}});
        c.pb({cy[1],{adj[cy[0]][cy[1]][1],0}});
    }
    F0R(i,c.size()) incycle[c[i].f] = 1;
    F0R(i,c.size()) c[i].s.s = get(0,c[i].f);
}

multiset<pair<ll,int>> b1,b2;

ll getmax() {
    if (b1.begin()->s != prev(b2.end())->s) return prev(b2.end())->f-b1.begin()->f;
    return max(prev(b2.end())->f-next(b1.begin())->f,prev(prev(b2.end()))->f-b1.begin()->f);
}

int main() {
	init();
	gencycle();
	pos[0] = 0;
	F0R(i,2*c.size()) pos[i+1] = c[i%c.size()].s.f+pos[i];
	F0R(i,c.size()) {
	    b1.insert({pos[i]-c[i].s.s,i});
	    b2.insert({pos[i]+c[i].s.s,i});
	}
	F0R(i,c.size()) {
	    ans = min(ans,max(mn,getmax()));
	    b1.erase(b1.find({pos[i]-c[i].s.s,i}));
	    b1.insert({pos[i+c.size()]-c[i].s.s,i});
	    b2.erase(b2.find({pos[i]+c[i].s.s,i}));
	    b2.insert({pos[i+c.size()]+c[i].s.s,i});
	}
	cout << ans;
}