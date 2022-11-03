#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

int n, m;
int color[100007];
vector<int> g[100007];
map<pair<int, int>, int> reb;
int root;
int was[100007];
vector<int> st;
vector<int> cyc;
ll ans[100007];
void dfs(int v, int col){
	if (cyc.size()) return;
	st.pub(v);
	was[v] = col;
	for (int to : g[v]){
		if (cyc.size()) return;
		if (was[to] == -1){
			dfs(to, col ^ 1);
		} else {
			if (was[to] == was[v] && cyc.size() == 0){
				for (int i = sz(st) - 1; i >= 0; i--){
					cyc.pub(st[i]);
					if (st[i] == to) break;
				}
			}
		}
	}	
	st.pop_back();
}

ll dfs2(int v){
	was[v] = 1;
	ll now = color[v];
	for (int to : g[v]) if (was[to] == -1){
		ll val = dfs2(to);
		ans[reb[mp(v, to)]] += val;
		now -= val;
	}
	return now;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pub(b);
    	g[b].pub(a);
    	reb[mp(a, b)] = i;
    	reb[mp(b, a)] = i;
    }
    for (int i = 0; i < n; i++) was[i] = -1;
    dfs(0, 0);
    for (int i = 0; i < n; i++) was[i] = -1;
	if (cyc.size() == 0) root = 0; else root = cyc.back();
	ll ww = dfs2(root);
	if (ww != 0){
		if (abs(ww) % 2 == 1 || cyc.size() == 0) cout << "NO", exit(0);
		ll val = ww / 2;
		int ff = 0;
		ans[reb[mp(cyc[0], cyc.back())]] += val;
		for (int i = 0; i < (int)cyc.size() - 1; i++){
			if (ff == 0) ans[reb[mp(cyc[i], cyc[i + 1])]] -= val;
 			else ans[reb[mp(cyc[i], cyc[i + 1])]] += val;
			ff ^= 1;
		}
	}		
	cout << "YES\n";
	for (int i = 0; i < m; i++) cout << ans[i] << ' ';
}