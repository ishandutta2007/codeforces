#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e6 + 10;

int n, sub[MAXN], dep[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p = -1) {
    sub[v] = 1;
    dep[v] = p == -1? 1: dep[p] + 1;
    for (int u: adj[v])
        if (u^p)
            dfs(u, v), sub[v] += sub[u];
}

int go(vector<int> weights) {
    vector<int> c(n, 0);
    for (auto w: weights)
        c[w]++;
    for (int i = 1; i <= n-1; i++)
        if (c[i] > 2) {
            c[i<<1] += c[i]-1>>1;
            c[i] = 2 - (c[i] & 1);
        }
    
    bitset<MAXN> can;
    can[0] = 1;
    for (int i = 1; i <= n-1; i++)
        for (int j = 0; j < c[i]; j++)
            can |= can << i;
    for (int i = n-1>>1; ~i; i--)
        if (can[i])
            return i;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p, p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(0);

    int rt = 0;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int u: adj[rt])
            if (sub[u] >= n/2 && sub[u] < sub[rt]) {
                rt = u;
                changed = true;
                break;
            }
    }

    dfs(rt);
    ll ans = 0;
    for (int v = 0; v < n; v++)
        ans += dep[v];

    vector<int> vec;
    for (int u: adj[rt])
        vec.push_back(sub[u]);
    int best = go(vec);
    ans += 1ll*best*(n-1-best);
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}