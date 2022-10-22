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

int n, x[MAXN], y[MAXN], c[MAXN];
int sec[MAXN], cord[MAXN], sz;
pair<ll, int> seg[MAXN<<2];
ll lz[MAXN<<2];

void plant(int v, int b, int e){
	if (e - b == 1){
		seg[v] = {cord[b], b};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

void pushDown(int v){
	if (!lz[v]) return;

	lz[v<<1] += lz[v];
	seg[v<<1].F += lz[v];
	lz[v<<1^1] += lz[v];
	seg[v<<1^1].F += lz[v];

	lz[v] = 0;
}

void add(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		lz[v] += val;
		seg[v].F += val;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	pushDown(v);
	add(v<<1, b, mid, l, r, val);
	add(v<<1^1, mid, e, l, r, val);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

pair<ll, int> get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return seg[v];
	if (r <= b || e <= l) return {(ll)-1e18, -1};

	int mid = b + e >> 1;
	pushDown(v);
	return max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void conv(int &x){x = lower_bound(cord, cord + sz, x) - cord;}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> c[i];
		if (x[i] > y[i])
			swap(x[i], y[i]);
		cord[sz++] = x[i];
		cord[sz++] = y[i];
	}
	sort(cord, cord + sz);
	sz = unique(cord, cord + sz) - cord;
	for (int i = 0; i < n; i++)
		conv(x[i]), conv(y[i]);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, [](int a, int b) {
		return y[a] < y[b];
		});

	plant(1, 0, sz);
	int pt = 0;
	ll ans = -1e18;
	pii ex;
	for (int i = 0; i < sz; i++){
		while (pt < n && y[sec[pt]] == i){
			int v = sec[pt++];
			add(1, 0, sz, 0, x[v]+1, c[v]);
		}

		auto x = get(1, 0, sz, 0, i+1);
		if (x.F - cord[i] > ans){
			ans = x.F - cord[i];
			ex = {cord[x.S], cord[i]};
		}
	}
	if (ans < 0){
		cout << "0\n";
		int temp = 1e9 + 4;
		cout << temp << " " << temp << " " << temp << " " << temp << endl;
		return;
	}

	cout << ans << "\n";
	cout << ex.F << " " << ex.F << " " << ex.S << " " << ex.S << "\n";
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