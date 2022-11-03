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

struct tree{
	ll t[300007 * 4];
	ll p[300007 * 4];

	void push(int v, int vl, int vr){
		if (p[v]){	
			t[v] += p[v] * (ll)(vr - vl + 1);
			if (v * 2 + 1 < 300007 * 4) p[v * 2 + 1] += p[v];
			if (v * 2 + 2 < 300007 * 4) p[v * 2 + 2] += p[v];
			p[v] = 0;
		}
	}

	void up(int v, int vl, int vr, int l, int r, ll val){
		if (l > r) return;
		push(v, vl, vr);
		if (r < vl || l > vr) return;
		if (vl >= l && vr <= r){
			p[v] += val;
			push(v, vl, vr);
		} else {	
			int vm = (vl + vr) >> 1;
			up(v * 2 + 1, vl, vm, l, r, val);
			up(v * 2 + 2, vm + 1, vr, l, r, val);
			t[v] = t[v * 2 + 1] + t[v * 2 + 2];
		}
	}

	ll get(int v, int vl, int vr, int l, int r){
		push(v, vl, vr);
		if (l > r) return 0;
		if (r < vl || l > vr) return 0;
		if (vl >= l && vr <= r) return t[v];
		int vm = (vl + vr) >> 1;
		return get(v * 2 + 1, vl, vm, l, r) + get(v * 2 + 2, vm + 1, vr, l, r);
	}
} t;

int n, m, q;
vector<int> g[300007];
vector<int> w[300007];
vector<int> st;
int color[300007];
void dfs(int v, int pred){
	color[v] = 1;
	st.pub(v);
	for (int to : g[v]){
		if (to == pred || color[to] == 2) continue;
		if (color[to] == 1){
			int mi = n, ma = 0;
			for (int i = sz(st) - 1; i >= 0; i--){
				mi = min(mi, st[i]);
				ma = max(ma, st[i]);
				if (st[i] == to) break;
			}
			w[ma].pub(mi);
		} else {
			dfs(to, v);
		}
	}	
	st.pop_back();
	color[v] = 2;
}

vector<pair<int, int> > zap[300007];
ll ans[300007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pub(b);
    	g[b].pub(a);
    }
    for (int i = 0; i < n; i++) if (color[i] == 0) dfs(i, -1);
    cin >> q;
    for (int i = 0; i < q; i++){
    	int l, r;
    	cin >> l >> r;
    	l--; r--;	
    	zap[r].pub(mp(l, i));
    }

    int last = -1;
    for (int i = 0; i < n; i++){
    	for (int x : w[i]) last = max(last, x);
    	t.up(0, 0, n - 1, last + 1, i, 1);
    	for (auto c : zap[i]) ans[c.y] = t.get(0, 0, n - 1, c.x, i);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}