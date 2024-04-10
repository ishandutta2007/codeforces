#include <bits/stdc++.h> // PLEASE
 
using namespace std;
typedef long long ll;
typedef pair <int, int> pp;
#define MAXN 100005
#define MAXM 1005
#define MAXP 31
#define A first
#define B second
#define MP make_pair
#define PB push_back
const ll INF = 2e9+13;
const ll MOD = 1e9+7;
inline ll mmul(ll a, ll b) { return (a*b)%MOD; }
inline ll madd(ll a, ll b) { return (a+b)%MOD; }
 
struct Bit {
    ll f[MAXN*4];
 
    void upd(int i, ll d) {
        for (; i < MAXN*4; i = (i | (i + 1)))
            f[i] += d;
    }
 
    ll get(int i) const {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += f[i];
        return res;
    }
} Tree;
 
ll p[MAXP];
ll binpow(ll a, ll b)
{
	p[0] = a;
	for(int i=1; i<MAXP; i++) p[i] = mmul(p[i-1], p[i-1]);
	ll ret = 1;
	for(int i=MAXP-1; i>=0; i--) {
		if(b >= (1<<i)) {
			b -= (1<<i);
			ret = mmul(ret, p[i]);
		}
	}
	return ret;
}
 
ll modinv(ll a) { return binpow(a, MOD-2); }
 
int N;
int tot = 0;
vector <pair <int, pp> > adj[MAXN];
bool vis[MAXN];
int sz[MAXN];
vector <int> guys;
 
void dfs1(int u, int pa)
{
	if(pa == -1) guys.clear();
	guys.PB(u);
	sz[u] = 1;
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i].A;
		if(v == pa) continue;
		if(vis[v]) continue;
		dfs1(v, u);
		sz[u] += sz[v];
	}
	if(pa == -1) tot = sz[u];
}
 
int centroid(int u, int pa)
{
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i].A;
		if(v == pa) continue;	
		if(vis[v]) continue;
		if(sz[v]*2 >= tot) return centroid(v, u);
	}
	return u;
}
pair <pp, ll> vals[MAXN]; // PRODUCT, <R-2B, B-2R>
void dfs3(int u, int pa)
{
	if(pa == -1) vals[u] = MP(pp(0, 0), 1);
	for(int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i].A;
		ll type = adj[u][i].B.B;
		ll wt = adj[u][i].B.A;
		if(v == pa) continue;
		if(vis[v]) continue;
		ll nr = 1LL-type;
		ll nb = type;
		vals[v] = MP(pp(vals[u].A.A+nr-2LL*nb, vals[u].A.B+nb-2LL*nr), mmul(vals[u].B, wt));
		dfs3(v, u);
	}
}
 
bool cmp(int a, int b)
{
	if(vals[a].A.A == vals[b].A.A) return vals[a].A.B < vals[b].A.B;
	return vals[a].A.A < vals[b].A.A;
}
 
ll go(int cent, int targ)
{
	if(targ == -1) dfs3(cent, -1);
 
	vector <pair <pp, ll> > queries; // maxx, maxy, multiplier
	int OFFSET = 200000;
	int MAXV = OFFSET*2;
	for(int i=0; i<guys.size(); i++) {
		int v = guys[i];
		int vx = vals[v].A.A;
		int vy = vals[v].A.B;
		ll mult = vals[v].B;
		queries.PB(MP(pp(-vx+OFFSET, -vy+OFFSET), mult));
	}
	sort(guys.begin(), guys.end(), cmp);
	sort(queries.begin(), queries.end());
	ll ret = 1LL;
 
	int cur = 0;
	for(int i=0; i<queries.size(); i++) {
		int xcoord = queries[i].A.A-OFFSET;
		while((cur<guys.size()) && (vals[guys[cur]].A.A <= xcoord)) {
			Tree.upd(vals[guys[cur]].A.B+OFFSET, 1);
			cur++;
		}
		int ycoord = queries[i].A.B;
		ret = mmul(ret, binpow(queries[i].B, Tree.get(ycoord))); 
	}
	cur = 0;
	for(int i=0; i<queries.size(); i++) {
		int xcoord = queries[i].A.A-OFFSET;
		while((cur<guys.size()) && (vals[guys[cur]].A.A <= xcoord)) {
			Tree.upd(vals[guys[cur]].A.B+OFFSET, -1);
			cur++;
		}
	}
	return ret;
}
 
ll solve(int u, int pa)
{
	dfs1(u, -1);
	int cent = centroid(u, pa);
	ll ret = 1;
	ret = mmul(ret, go(cent, -1));
	vis[cent] = 1;
 
	for(int i=0; i<adj[cent].size(); i++) {
		int v = adj[cent][i].A;
		if(vis[v]) continue;
		dfs1(v, -1);
		ret = mmul(ret, modinv(go(cent, i)));
	}	
	for(int i=0; i<adj[cent].size(); i++) {
		int v = adj[cent][i].A;
		if(vis[v]) continue;
		ret = mmul(ret, solve(v, cent));
	}
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for(int i=0; i<N-1; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		adj[a].PB(MP(b, pp(c, d)));
		adj[b].PB(MP(a, pp(c, d)));
	}
	cout << solve(1, -1) << endl;
}