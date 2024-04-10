#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, a[MAXN];
vector<int> adj[MAXN];
int sub[MAXN];
bool blocked[MAXN];
ll ans;

void plant(int v, int p = -1){
	sub[v] = 1;
	for (int u:adj[v])
		if (u^p && !blocked[u])
			plant(u, v), sub[v] += sub[u];
}

int cnt[2];
void add(int v, int p, int lv, int type){
	cnt[lv] += type;
	for (int u:adj[v])
		if (u^p && !blocked[u])
			add(u, v, !lv, type);
}

void addAns(int v, int p, int lv, ll sm = 0){
	if (lv){
		sm -= a[v];
		sm = (sm%MOD+MOD)%MOD;
		ans += (MOD-sm)*cnt[1];
		ans = (ans%MOD+MOD)%MOD;
	}
	else{
		sm += a[v];
		sm = (sm%MOD+MOD)%MOD;
		ans += sm*cnt[0];
		ans = (ans%MOD+MOD)%MOD;
	}

	for (int u:adj[v])
		if (u^p && !blocked[u])
			addAns(u, v, !lv, sm);
}

void go(int v) {
	plant(v);
	int p = -1, tot = sub[v], changed = 1;
	while (changed){
		changed = 0;
		for (int u:adj[v])
			if (u^p && !blocked[u] && sub[u]*2 > tot){
				p = v;
				v = u;
				changed = 1;
				break;
			}
	}

	blocked[v] = true;
	for (int u:adj[v])
		if (!blocked[u])
			go(u);
	blocked[v] = false;

	cnt[0]=1, cnt[1]=0;
	for (int u:adj[v])
		if (!blocked[u]){
			addAns(u, v, 1, a[v]);
			add(u, v, 1, 1);
		}

	cnt[0] = cnt[1] = 0;
	reverse(adj[v].begin(), adj[v].end());
	for (int u:adj[v])
		if (!blocked[u]){
			addAns(u, v, 1, 0ll);
			add(u, v, 1, 1);
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	go(0);
	ans *= 2;
	ans = (ans%MOD+MOD)%MOD;
	for (int i = 0; i < n; i++) ans += a[i];
	ans = (ans%MOD+MOD)%MOD;
	cout << ans << "\n";
	return 0;
}