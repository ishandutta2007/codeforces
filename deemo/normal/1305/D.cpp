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

const int MAXN = 1e3 + 10;

int n, rem;
vector<int> adj[MAXN];
int deg[MAXN];
bool del[MAXN];

void dfs(int v, int p = -1) {
	for (int u: adj[v])
		if (u != p && !del[u])
			deg[v]++, deg[u]++, dfs(u, v);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int rem = n;
	while (rem > 1) {
		memset(deg, 0, sizeof(deg));
		int root = -1;
		for (int v = 0; v < n; v++)
			if (!del[v]) {
				dfs(v);
				root = v;
				break;
			}

		vector<int> leaves;
		for (int v = 0; v < n && leaves.size() < 2; v++)
			if (!del[v] && deg[v] == 1)
				leaves.push_back(v);
		
		cout << "? " << leaves[0]+1 << " " << leaves[1]+1 << endl;
		int p; cin >> p; p--;
		if (p == leaves[0] || p == leaves[1]) {
			cout << "! " << p+1 << endl;
			exit(0);
		}
		del[leaves[0]] = del[leaves[1]] = true;
		rem = 0;
		for (int v = 0; v < n; v++)
			if (!del[v])
				rem++;
	}

	for (int i = 0; i < n; i++)
		if (!del[i])
			cout << "! " << i+1 << endl;
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