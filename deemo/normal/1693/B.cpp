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

const int MAXN = 2e5 + 10;

int n;
vector<int> adj[MAXN];
ll l[MAXN], r[MAXN];
ll tl[MAXN], tr[MAXN];
int ans;

void dfs(int v) {
    ll sm[2] = {0};
    for (int u: adj[v]) {
        dfs(u);
        sm[0] += tl[u];
        sm[1] += tr[u];
    }
    ll gl = 0ll;
    ll gr = min(r[v], sm[1]);
    if (gr >= l[v])
        tl[v] = l[v], tr[v] = gr;
    else {
        tl[v] = l[v];
        tr[v] = r[v];
        ans++;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 1; i < n; i++) {
        int p; cin >> p, p--;
        adj[p].push_back(i);
    }
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    ans = 0;
    dfs(0);
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}