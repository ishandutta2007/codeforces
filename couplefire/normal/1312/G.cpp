#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define INF 1000000009

int dp1[MAXN];
int dp2[MAXN];
vector<pair<char,int>> adj[MAXN];
int n,k;
int arr[MAXN];
bool good[MAXN] = {0};
int cur = 0;

template<class T> struct Seg { 
	const T ID = 1e9+9; // comb(ID,b) must equal b, and minimum is greater than -1e9
	T comb(T a, T b) { return min(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.resize(2*n); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
Seg<int> seg;

void dfs(int u = 0, int p = -1){
    if(good[u])cur++;
    if(u == 0){
        dp1[u] = 0;
        dp2[u] = INF;
    }
    else{
        dp1[u] = min(dp1[p], dp2[p])+1;
        if(good[u]){
            dp2[u] = min(seg.query(0, n)+cur, INF);
        }
        else dp2[u] = INF;
    }
    seg.upd(u, min(dp1[u], dp2[u])-cur+good[u]);
    sort(adj[u].begin(), adj[u].end());
    for(auto v : adj[u]){
        dfs(v.second, u);
    }
    seg.upd(u, INF);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    seg.init(MAXN);
    for(int i = 0; i<n; i++){
        int u; cin >> u;
        char c; cin >> c;
        adj[u].push_back({c,i+1});
    }
    cin >> k;
    for(int i = 0; i<k; i++){
        cin >> arr[i];
        good[arr[i]] = 1;
    }
    // cout << dp1[1] << endl;
    dfs();
    for(int i = 0; i<k; i++) cout << min(dp1[arr[i]], dp2[arr[i]]) << " ";
    cout << endl;
}