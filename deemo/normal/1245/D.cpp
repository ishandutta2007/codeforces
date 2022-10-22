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

const int MAXN = 2e3 + 10;

int n, x[MAXN], y[MAXN];
pair<ll, pii> sec[MAXN*MAXN]; int sz;
int par[MAXN];
int c[MAXN], k[MAXN];

int getPar(int v){return par[v]==v? v: par[v]=getPar(par[v]);}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) cin >> k[i];
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			sec[sz++] = {1ll*(abs(x[i] - x[j]) + abs(y[i] - y[j]))*(k[i]+k[j]), {i, j}};
	for (int i = 0; i < n; i++)
		sec[sz++] = {c[i], {i, n}};
	sort(sec, sec + sz);
	iota(par, par + n+1, 0);
	ll ans = 0;
	vector<int> vertices;
	vector<pii> edges;
	for (int i = 0; i < sz; i++){
		int u = sec[i].S.F, v = sec[i].S.S;
		int pu = getPar(u), pv = getPar(v);
		if (pu == pv) continue;
	
		par[pu] = pv;
		ans += sec[i].F;
		if (v == n)
			vertices.push_back(u+1);
		else
			edges.push_back({u+1, v+1});
	}

	cout << ans << "\n";
	cout << vertices.size() << "\n";
	for (auto x: vertices)
		cout << x << " ";
	cout << "\n";
	cout << edges.size() << "\n";
	for (auto x: edges)
		cout << x.F << " " << x.S << "\n";
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