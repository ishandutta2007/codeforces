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
const int LOG = 20;

int n, sp, x[MAXN], t[MAXN];
pair<ll, int> seg[2][LOG][MAXN];
int fen[2][LOG][MAXN];
int pos[2][LOG][MAXN];

void plant(int v, int b, int e, int de = 0) {
    if (e - b == 1) {
        seg[0][de][b] = {1ll*t[b]*sp - x[b], b};
        seg[1][de][b] = {1ll*t[b]*sp + x[b], b};
        pos[0][de][b] = b;
        pos[1][de][b] = b;
        return;
    }

    int mid = b + e >> 1;
    plant(v<<1, b, mid, de+1);
    plant(v<<1^1, mid, e, de+1);
    for (int w = 0; w < 2; w++) {
        merge(seg[w][de+1] + b, seg[w][de+1] + mid, seg[w][de+1] + mid, seg[w][de+1] + e, seg[w][de] + b);
        for (int i = b; i < e; i++)
            pos[w][de][seg[w][de][i].S] = i;
    }
}

int d[MAXN], sec[MAXN];
int _t[MAXN];
int get_fen(int b, int e, int de, int tp) {
    int res = -1e9;
    for (; e > b; e -= e&-e)
        res = max(res, fen[tp][de][e]);
    return res;
}

void upd_fen(int b, int e, int val, int de, int tp) {
    for (; b <= e; b += b&-b)
        fen[tp][de][b] = max(fen[tp][de][b], val);
}

int get_max(int v, int b, int e, int l, int r, int tp, ll th, int de = 0) {
    if (l <= b && e <= r) {
        int pp = upper_bound(seg[tp][de] + b, seg[tp][de] + e, make_pair(th+1, -1)) - seg[tp][de];
        //cout << v << " " << b << "     " << e << "    " << th << "   " << tp << endl;
        if (pp == b) return -1e9;
        return get_fen(b, pp, de, tp);
    }
    if (r <= b || e <= l) return -1e9;

    int mid = b + e >> 1;
    return max(get_max(v<<1, b, mid, l, r, tp, th, de+1), get_max(v<<1^1, mid, e, l, r, tp, th, de + 1));
}

void upd(int v, int b, int e, int p, int de = 0) {
    upd_fen(pos[0][de][p]+1, e, d[p], de, 0);
    upd_fen(pos[1][de][p]+1, e, d[p], de, 1);
    if (e - b == 1) return;

    int mid = b + e >> 1;
    if (p < mid)
        upd(v<<1, b, mid, p, de + 1);
    else
        upd(v<<1^1, mid, e, p, de + 1);
}

void solve() {
    cin >> n >> sp;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> x[i];
    iota(sec, sec + n, 0);
    sort(sec, sec + n, [](int u, int v) {
            return x[u] < x[v];
            });
    sort(x, x + n);
    for (int i = 0; i < n; i++)
        _t[i] = t[sec[i]];
    memcpy(t, _t, sizeof(t));

    sort(sec, sec + n, [](int u, int v) {
            return t[u] < t[v];
            });
    plant(1, 0, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v = sec[i];
        if (1ll*t[v]*sp < abs(x[v]))
            d[v] = -1e9;
        else {
            d[v] = max(get_max(1, 0, n, 0, v, 0, 1ll*t[v]*sp - x[v]), get_max(1, 0, n, v+1, n, 1, 1ll*t[v]*sp + x[v])) + 1;
            d[v] = max(d[v], 1);
        }
        //cout << v << "   " << d[v] << endl;
        //if (i == 1) exit(0);
        upd(1, 0, n, v);
        ans = max(ans, d[v]);
    }
    cout << ans << "\n";
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