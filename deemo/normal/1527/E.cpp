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

const int MAXN = 35000 + 20;

int n, k, a[MAXN];
ll d[2][MAXN], seg[MAXN<<2], lz[MAXN<<2];
int cur;

void plant(int v, int b, int e) {
    lz[v] = 0;
    if (e - b == 1) {
        seg[v] = d[cur][b];
        return;
    }

    int mid = b + e >> 1;
    plant(v<<1, b, mid);
    plant(v<<1^1, mid, e);
    seg[v] = min(seg[v<<1], seg[v<<1^1]);
}

void push_down(int v) {
    if (!lz[v]) return;

    lz[v<<1] += lz[v];
    lz[v<<1^1] += lz[v];
    seg[v<<1] += lz[v];
    seg[v<<1^1] += lz[v];
    lz[v] = 0;
}

void add(int v, int b, int e, int l, int r, ll val) {
    if (l <= b && e <= r) {
        seg[v] += val;
        lz[v] += val;
        return;
    }
    if (r <= b || e <= l) return;

    int mid = b + e >> 1;
    push_down(v);
    add(v<<1, b, mid, l, r, val);
    add(v<<1^1, mid, e, l, r, val);
    seg[v] = min(seg[v<<1], seg[v<<1^1]);
}

int lst[MAXN];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    cur = 0;
    memset(d, 63, sizeof(d));
    d[cur][0] = 0;
    for (int w = 0; w < k; w++, cur ^= 1) {
        plant(1, 0, n);
        memset(lst, -1, sizeof(lst));

        d[!cur][0] = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (~lst[x])
                add(1, 0, n, 0, lst[x]+1, i-lst[x]);
            lst[x] = i;
            d[!cur][i+1] = seg[1];
        }
    }
    cout << d[cur][n] << "\n";
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