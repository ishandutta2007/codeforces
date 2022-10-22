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

int n;
vector<int> adj[MAXN];
bool done;
int sec[MAXN], sz;

int vis[MAXN];
void dfs(int v){
	if (vis[v]){
		if (vis[v] == 1){
			for (int i = 0; i < sz; i++)
				if (sec[i] == v){
					cout << sz-i << "\n";
					for (int j = i; j < sz; j++)
						cout << sec[j]+1 << " ";
					cout << "\n";
					break;
				}
			done = true;
		}
		return;
	}
	vis[v] = 1;
	sec[sz++] = v;
	for (int u: adj[v]){
		dfs(u);
		if (done)
			return;
	}
	sz--;
	vis[v] = 2;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) adj[i].clear(), vis[i] = 0;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		adj[i].push_back({i-x});
	}
	done = false;
	sz = 0;
	dfs(0);
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