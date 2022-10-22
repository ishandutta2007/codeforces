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

int n, a[MAXN], b[MAXN];
bool vis[MAXN];

int comp[MAXN], gg, lowest[MAXN];
void dfs(int v) {
    if (vis[v])
        return;

    vis[v] = true;
    comp[v] = gg;
    lowest[gg] = min(lowest[gg], __builtin_ctz(b[v]));
    for (int u = 0; u < n; u++)
        if (b[u]&b[v])
            dfs(u);
}

void done() {
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - b[i]);
    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
};

int par[30];
int get_par(int v){ return par[v]==v? v: par[v]=get_par(par[v]);}
bool go() {
    int rl = 0;
    for (int i = 0; i < n; i ++) rl |= b[i];
    rl = __builtin_popcount(rl) - 1;
    iota(par, par + 30, 0);
    for (int v = 0; rl && v < n; v++) {
        int lst = -1;
        for (int i = 0; i < 30; i++)
            if (b[v]>>i&1) {
                if (~lst) {
                    int b = get_par(i);
                    if (b != lst) {
                        rl--;
                        par[b] = lst;
                    }
                }
                lst = get_par(i);
            }
    }
    return !rl;
}

void solve() {
    cin >> n; for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
    for (int i = 0; i < n; i++) {
        if (!b[i])
            b[i]++;
    }

    memset(vis, 0, sizeof(vis));
    memset(lowest, 63, sizeof(lowest));
    gg = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i), gg++;
    if (gg == 1) {
        done();
        return;
    }

    for (int i = 0; i < n; i++) {
        b[i]--;
        if (b[i] && go()) {
            done();
            return;
        }
        b[i] += 2;
        if (b[i] < (1<<30) && go()) {
            done();
            return;
        }
        b[i]--;
    }

    int mx = 0;
    for (int i = 1; i < gg; i++)
        if (lowest[i] > lowest[mx])
            mx = i;

    int u = -1, v = -1;
    for (int i = 0; i < n; i++)
        if (comp[i] == mx) {
            if (u == -1)
                u = i;
            else {
                v = i;
                break;
            }
        }
    b[u]--;
    b[v]++;
    done();
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