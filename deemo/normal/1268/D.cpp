#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;
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

const int MAXN = 2e3 + 10;

int n;
string s[MAXN];
bitset<MAXN> adj[MAXN], rem;

bool vis[MAXN];
int cv = 0;
void dfs(int v, int t = 1){
	if (vis[v]) return;
	vis[v] = true;
	cv++;

	bitset<MAXN> temp = adj[v];
	if (!t)
		temp.flip();
	temp &= rem;
	
	vector<int> toVisit;
	for (int x = temp._Find_first(); x < temp.size(); x = temp._Find_next(x))
		toVisit.push_back(x), rem.flip(x);
	for (auto x: toVisit)
		dfs(x, t);
}

bool strong() {
	fill(vis, vis + n, 0);
	for (int i = 0; i < n; i++) rem.set(i);
	cv = 0;
	dfs(0);
	if (cv != n) return false;

	for (int i = 0; i < n; i++) rem.set(i);
	fill(vis, vis + n, 0);
	cv = 0;
	dfs(0, 0);
	return cv == n;
}

bool check(int mask){
	for (int v = 0; v < n; v++)
		if (mask>>v&1)
			for (int i = 0; i < n; i++)
				adj[v].flip(i), adj[i].flip(v);

	bool ret = strong();

	for (int v = 0; v < n; v++)
		if (mask>>v&1)
			for (int i = 0; i < n; i++)
				adj[v].flip(i), adj[i].flip(v);
	return ret;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++)
			if (s[i][j] == '1')
				adj[i][j] = 1;
	}
	if (strong()){
		cout << "0 1\n";
		return;
	}

	if (n < 10) {
		int mn = 1e9, cnt = 0;
		for (int mask = 1; mask < 1<<n; mask++){
			int t = __builtin_popcount(mask);

			if (t <= mn && check(mask)) {
				if (t < mn)
					mn = t, cnt = 1;
				else
					cnt++;
			}
		}
		if (mn > n)
			cout << "-1\n";
		else {
			for (int i = 1; i <= mn; i++)
				cnt = 1ll*cnt*i%MOD;
			cout << mn << " " << cnt << "\n";
		}
	} else {
		int cnt = 0;
		for (int v = 0; v < n; v++){
			for (int i = 0; i < n; i++)
				adj[v].flip(i), adj[i].flip(v);

			cnt += strong();
			
			for (int i = 0; i < n; i++)
				adj[v].flip(i), adj[i].flip(v);
		}
		cout << "1 " << cnt << "\n";
	}
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