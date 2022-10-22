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

const int MAXN = 4e5 + 20;
const int INF = (int)1e9 + 10;

int n;
pair<ll, ll> p[MAXN];
ll sec[MAXN], sz;

void conv(ll &x){x = lower_bound(sec, sec + sz, x) - sec;}

int fen[MAXN];
void addFen(int v, int val){for (; v<MAXN; v+=v&-v) fen[v] += val;}

int getFen(int v) {
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

pii seg[MAXN<<2];
int lz[MAXN<<2];
pii merge(pii x, pii y, int mid) {
	if (x.F > y.F)
		return y;
	if (y.F > x.F)
		return x;

	pii ret(x.F, x.S + y.S);
	if (getFen(mid) == x.F && getFen(mid-1) == x.F)
		ret.S--;
	return ret;
}

void plant(int v, int b, int e){
	lz[v] = 0;
	if (e - b == 1){
		seg[v] = {0, 1};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	seg[v] = merge(seg[v<<1], seg[v<<1^1], mid);
}

void pushDown(int v){
	if (!lz[v]) return;

	lz[v<<1] += lz[v];
	seg[v<<1].F += lz[v];

	lz[v<<1^1] += lz[v];
	seg[v<<1^1].F += lz[v];

	lz[v] = 0;
}

void addRange(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		lz[v] += val;
		seg[v].F += val;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	pushDown(v);
	addRange(v<<1, b, mid, l, r, val);
	addRange(v<<1^1, mid, e, l, r, val);
	seg[v] = merge(seg[v<<1], seg[v<<1^1], mid);
}

void solve() {
	cin >> n;
	sz = 0;
	sec[sz++] = -4ll*INF - 1;
	sec[sz++] = -4ll*INF - 2;
	sec[sz++] = -4ll*INF - 3;
	for (int i = 0; i < n; i++) {
		cin >> p[i].F >> p[i].S;
		p[i].F *= 4;
		p[i].S *= 4;
		if (p[i].F == p[i].S)
			p[i].F--, p[i].S++;
		sec[sz++] = p[i].F, sec[sz++] = p[i].S;
	}
	sec[sz++] = 4ll*INF + 1;
	sec[sz++] = 4ll*INF + 2;
	sec[sz++] = 4ll*INF + 3;
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	for (int i = 0; i < n; i++)
		conv(p[i].F), conv(p[i].S);

	plant(1, 0, sz);
	for (int i = 0; i < n; i++) {
		addFen(p[i].F, 1);
		addFen(p[i].S, -1);
		addRange(1, 0, sz, p[i].F, p[i].S, 1);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		addFen(p[i].F, -1);
		addFen(p[i].S, 1);
		addRange(1, 0, sz, p[i].F, p[i].S, -1);
		ans = max(ans, seg[1].S - 1);
		addFen(p[i].F, 1);
		addFen(p[i].S, -1);
		addRange(1, 0, sz, p[i].F, p[i].S, 1);
	}
	cout << ans << "\n";

	for (int i = 0; i < n; i++) {
		addFen(p[i].F, -1);
		addFen(p[i].S, 1);
	}
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