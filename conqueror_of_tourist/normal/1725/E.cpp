#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))
 
#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)
 
#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<
 
#define int long long
 
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
 
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pld;
typedef complex<ld> cd;
 
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
 
const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 998244353;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret, depth;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), depth(sz(C)), rmq((dfs(C,0,-1, 0), ret)) {}
	void dfs(vector<vi>& C, int v, int par, int d) {
		time[v] = T++;
		depth[v] = d;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v, d + 1);
		}
	}


	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

typedef vector<pair<int, int>> vpi;
vpi compressTree(LCA& lca, const vi& subset) {
	static vi rev; rev.resize(sz(lca.time));
	vi li = subset, &T = lca.time;
	auto cmp = [&](int a, int b) { return T[a] < T[b]; };
	sort(all(li), cmp);
	int m = sz(li)-1;
	rep(i,0,m) {
		int a = li[i], b = li[i+1];
		li.push_back(lca.lca(a, b));
	}
	sort(all(li), cmp);
	li.erase(unique(all(li)), li.end());
	rep(i,0,sz(li)) rev[li[i]] = i;
	vpi ret = {pii(0, li[0])};
	rep(i,0,sz(li)-1) {
		int a = li[i], b = li[i+1];
		ret.emplace_back(rev[lca.lca(a, b)], b);
	}
	return ret;
}

const int MAXN = 200010;

int32_t c3 (int n){
    int res = (n * (n - 1) * (n - 2))/6;
    return res % MOD;
}

void dfs_add(vi& tot, vvi&g_adj, int node, vpi& map){
    //cout << "add " << node << '\n';
    for (int u : g_adj[node]){
        dfs_add(tot, g_adj, u, map);
        tot[map[node].s] += tot[map[u].s];
    }
}

void dfs_clear(vi& tot, vvi&g_adj, int node, vpi& map){
    for (int u : g_adj[node]){
        dfs_clear(tot, g_adj, u, map);
    }
    tot[map[node].s] = 0;
}

int32_t main() { FAST
    int n;
    cin >> n;
    
    vi A(n);
    vvi revA(MAXN);
    for (int i = 0; i < n; i++){
        cin >> A[i];
        revA[A[i]].pb(i);
    }

    
    vi fact(MAXN, 1);
    vvi seen(MAXN);
    
    for (int i = 2; i < MAXN; i++){
        if (fact[i] == 1){
            for (int j = i; j < MAXN; j += i){
                fact[j] = i;
                for (int v : revA[j]){
                    seen[i].pb(v);
                }
            }
        }
    }
    
    
    vvi adj(n);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    
    LCA lca_g(adj);
    vi desc(n);
    
    int res = 0;
    for (int i = 2; i < MAXN; i++){
        vi l = seen[i];
        
        int tot = sz(l);
        
        if (tot < 3){
            continue;
        }
        
        for (int v : l){
            desc[v] = 1;
        }
        
        vpi ct = compressTree(lca_g, l);
        int m = sz(ct);
        
        vvi adj2(m);
        
        //for (int v : desc){
        //    cout << v << " ";
        //} cout << '\n';
        
        for (int i = 0; i < m; i++){
            pii pp = ct[i];
            
            int a = pp.f;
            int b = pp.s;
            //cout << a << " " << b << '\n';
            if (a != i){
                adj2[a].pb(i);
            }
        }
        
        dfs_add(desc, adj2, 0, ct);
        
        //for (int v : desc){
        //    cout << v << " ";
        //} cout << '\n';
        
        for (int i = 0; i < m; i++){
            pii pp = ct[i];
            
            int a = pp.f;
            int b = pp.s;
            //cout << a << " " << b << '\n';
            if (a != i){
                int j = ct[a].s;
                int below = desc[b];
                int length = lca_g.depth[b] - lca_g.depth[j];
                
                //cout << a _ b _ i _ j _ length << '\n';
                int ct = (c3(tot) - c3(below) - c3(tot - below)) % MOD;
                res = (res + length * ct) % MOD;
            }
        }
        
        dfs_clear(desc, adj2, 0, ct);
        
        
    }
    
    cout << res << '\n';
    
}