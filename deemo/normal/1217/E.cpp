#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 10;//XXX

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

int n, a[MAXN];
pii seg[MAXN<<2][10];

pii merge(pii a, pii b){
	if (b.F < a.S)
		a.S = b.F;
	if (a.S < a.F)
		swap(a.F, a.S);

	if (b.S < a.S)
		a.S = b.S;
	if (a.S < a.F)
		swap(a.F, a.S);
	return a;
}

void plant(int v, int b, int e){
	if (e-b == 1){
		int temp = a[b];
		for (int w = 0; w < 10; w++, temp /= 10)
			if (temp%10 == 0)
				seg[v][w] = {MOD, MOD};
			else
				seg[v][w] = {a[b], MOD};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	for (int w = 0; w < 10; w++)
		seg[v][w] = merge(seg[v<<1][w], seg[v<<1^1][w]);
}

void updPos(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		a[b] = val;
		int temp = a[b];
		for (int w = 0; w < 10; w++, temp /= 10)
			if (temp%10 == 0)
				seg[v][w] = {MOD, MOD};
			else
				seg[v][w] = {a[b], MOD};
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		updPos(v<<1, b, mid, pos, val);
	else
		updPos(v<<1^1, mid, e, pos, val);
	for (int w = 0; w < 10; w++)
		seg[v][w] = merge(seg[v<<1][w], seg[v<<1^1][w]);
}

pii get(int v, int b, int e, int l, int r, int t){
	if (l <= b && e <= r) return seg[v][t];
	if (r <= b || e <= l) return {MOD, MOD};

	int mid = b + e >> 1;
	return merge(get(v<<1, b, mid, l, r, t), get(v<<1^1, mid, e, l, r, t));
}

void solve() {
	int q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	plant(1, 0, n);

	while (q--){
		int type;
		cin >> type;
		if (type == 1){
			int i, x; cin >> i >> x, i--;
			updPos(1, 0, n, i, x);
		}
		else{
			int l, r; cin >> l >> r, l--;
			int ans = 2*MOD;
			for (int w = 0; w < 10; w++){
				auto x = get(1, 0, n, l, r, w);
				if (x.S < MOD)
					ans = min(ans, x.F+x.S);
			}

			if (ans >= 2*MOD)
				cout << "-1\n";
			else
				cout << ans << "\n";
		}
	}
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