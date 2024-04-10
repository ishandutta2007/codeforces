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

const int MAXN = 3e5 + 10;

int n, m;
vector<pii> vec[MAXN];
int sec[MAXN * 3], sz;
int par[MAXN];

pii seg[MAXN<<3], lz[MAXN<<3];

void push(int v) {
    if (!lz[v].F) return;

    lz[v<<1] = max(lz[v<<1], lz[v]);
    lz[v<<1^1] = max(lz[v<<1^1], lz[v]);
    seg[v<<1] = max(seg[v<<1], lz[v]);
    seg[v<<1^1] = max(seg[v<<1^1], lz[v]);
    lz[v] = {0, 0};
}

void upd(int v, int b, int e, int l, int r, pii val) {
    if (l <= b && e <= r) {
        lz[v] = max(lz[v], val);
        seg[v] = max(seg[v], val);
        return;
    }
    if (r <= b || e <= l) return;

    int mid = b + e >> 1;
    push(v);
    upd(v<<1, b, mid, l, r, val);
    upd(v<<1^1, mid, e, l, r, val);
    seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

pii get(int v, int b, int e, int l, int r) {
    if (l <= b && e <= r) return seg[v];
    if (r <= b || e <= l) return {-1, -1};

    int mid = b + e >> 1;
    push(v);
    return max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

bool mark[MAXN];
void go(int v) {
    if (~par[v])
        go(par[v]);
    mark[v] = true;
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int row, l, r; cin >> row >> l >> r, row--, l--;
        vec[row].push_back({l, r});
        sec[sz++] = l;
        sec[sz++] = r;
    }
    sort(sec, sec + sz);
    sz = unique(sec, sec + sz) - sec;

    int ans = 0;
    int best = -1;
    for (int row = 0; row < n; row++) {
        pii mx = {0, -1};
        for (auto [l, r]: vec[row]) {
            l = lower_bound(sec, sec + sz, l) - sec;
            r = lower_bound(sec, sec + sz, r) - sec;
            mx = max(mx, get(1, 0, sz, l, r));
        }
        if (ans < mx.F + 1)
            ans = mx.F + 1, best = row;
        par[row] = mx.S;
        if (mx.F == 0)
            par[row] = -1;
        for (auto [l, r]: vec[row]) {
            l = lower_bound(sec, sec + sz, l) - sec;
            r = lower_bound(sec, sec + sz, r) - sec;
            upd(1, 0, sz, l, r, make_pair(mx.F + 1, row));
        }
    }
    go(best);
    cout << n - ans << "\n";
    for (int i = 0; i < n; i++)
        if (!mark[i])
            cout << i+1 << " ";
    cout << "\n";
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