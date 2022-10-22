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

int n;
pii p[MAXN];
int mxIn[MAXN];
pair<int, int> d[MAXN];
pii seg[MAXN<<2];


pii merge(pii a, pii b){
	pii res;
	res.F = min(a.F, b.F);
	res.S = 0;
	if (a.F == res.F)
		add(res.S, a.S);
	if (b.F == res.F)
		add(res.S, b.S);
	return res;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		seg[v] = {MOD, 0};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	seg[v] = merge(seg[v<<1], seg[v<<1^1]);
}

void updPos(int v, int b, int e, int pos){
	if (e - b == 1){
		seg[v] = d[b];
		seg[v].F += MOD-p[b].F;
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		updPos(v<<1, b, mid, pos);
	else
		updPos(v<<1^1, mid, e, pos);
	seg[v] = merge(seg[v<<1], seg[v<<1^1]);
}

pii get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return seg[v];
	if (r <= b || e <= l) return {MOD, 0};
	
	int mid = b + e >> 1;
	return merge(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
	sort(p, p + n);
	mxIn[0] = 0;
	for (int i = 0; i < n; i++)
		mxIn[i+1] = max(mxIn[i], p[i].S);

	plant(1, 0, n);

	for (int i = 0; i < n; i++){
		d[i] = {p[i].S, 1};
		if (i){
			int tr = lower_bound(p, p + n, make_pair(p[i].S+1, -1)) - p;
			int tl = lower_bound(p, p + n, make_pair(mxIn[tr]+1, -1)) - p;
			auto x = get(1, 0, n, tl, tr);
		//	cout << tl << "  " << tr << "   " << x.F << "  " << x.S << endl;
			if (x.F < MOD)
				x.F -= MOD - p[i].S;
			d[i] = min(d[i], x);
		}
		updPos(1, 0, n, i);
	//	cout << i << "   " << d[i].F << "  " << d[i].S << endl;
	}

	int xx = -1;
	int res = 2e9;
	for (int i = n-1; ~i; i--){
		if (xx >= p[i].F) break;
		res = min(res, d[i].F);
		xx = max(xx, p[i].S);
	}
	xx = -1;
	int ans = 0;
	for (int i = n-1; ~i; i--){
		if (xx >= p[i].F) break;
		if (d[i].F == res)
			add(ans, d[i].S);
		xx = max(xx, p[i].S);
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