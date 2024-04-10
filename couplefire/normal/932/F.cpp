#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct Line {
	mutable long long k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(long long x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const long long inf = LLONG_MAX;
	long long div(long long a, long long b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(long long k, long long m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	long long query(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

long long dp[MAXN] = {0};
int n;
vector<int> adj[MAXN];
int ai[MAXN], bi[MAXN];
int sz[MAXN];
LineContainer seg;

void init(int v = 0, int p = 0){
    sz[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        init(u, v);
        sz[v] += sz[u];
    }
}

void dfs(int v, int p, LineContainer &tree){
    // cout << v << endl;
    int bigChild = -1;
    int maxsz = -1;
    for(auto u : adj[v]){
        if(u == p) continue;
        if(sz[u] > maxsz){
            maxsz = sz[u];
            bigChild = u;
        }
    }
    if(bigChild != -1) dfs(bigChild, v, tree);
    for(auto u : adj[v]){
        if(u == p || u == bigChild) continue;
        LineContainer temp;
        dfs(u, v, temp);
        for(auto i : temp) tree.add(i.k, i.m);
    }
    dp[v] = -(sz[v]>1?tree.query(ai[v]):0);
    tree.add(-bi[v], -dp[v]);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> ai[i];
    for(int i = 0; i<n; i++) cin >> bi[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init();
    dfs(0, 0, seg);
    for(int i = 0; i<n; i++) cout << dp[i] << " ";
    cout << endl;
}