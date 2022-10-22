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

const int MAXN = 5e5 + 10;

int n, m, cap, c0;
int t[MAXN], a[MAXN], b[MAXN];
int sec[MAXN];
int seg[MAXN<<2], lz[MAXN<<2];

void plant(int v, int b, int e){
	lz[v] = 0;
	if (e - b == 1) {
		seg[v] = c0 - t[sec[b]];
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

void pushDown(int v){
	if (!lz[v]) return;

	seg[v<<1] += lz[v];
	lz[v<<1] += lz[v];
	seg[v<<1^1] += lz[v];
	lz[v<<1^1] += lz[v];

	lz[v] = 0;
}

void add(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		lz[v] += val;
		seg[v] += val;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	pushDown(v);
	add(v<<1, b, mid, l, r, val);
	add(v<<1^1, mid, e, l, r, val);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int getMax(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return seg[v];
	if (r <= b || e <= l) return 0;

	int mid = b + e >> 1;
	pushDown(v);
	return max(getMax(v<<1, b, mid, l, r), getMax(v<<1^1, mid, e, l, r));
}

int getBound(int f){
	return lower_bound(sec, sec + n, f, [](int a, int b){
			return t[a] < b;})
		- sec;
}

void solve() {
	cin >> n >> m >> cap >> c0;
	cap = min(cap, m);
	c0 = min(c0, cap);
	for (int i = 0; i < n; i++) cin >> t[i] >> a[i] >> b[i];
	if (n == 0){
		if (c0 == m)
			cout << "0\n";
		else
			cout << "-1\n";
		return;
	}

	iota(sec, sec + n, 0);
	sort(sec, sec + n, [](int a, int b){
			return t[a] < t[b];
			});
	plant(1, 0, n);

	ll ans = 0;
	int curPos = c0, pt = 0;
	priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
	while (curPos < m) {
		if (pt < n && curPos >= t[sec[pt]]){
			int f = sec[pt++];
			pq.push({{b[f], a[f]}, f});
		}
		else {
			if (pq.empty()){
				cout << "-1\n";
				return;
			}

			auto mn = pq.top(); pq.pop();
			int g = min({mn.F.S, (pt < n? t[sec[pt]]: m) - curPos, cap - getMax(1, 0, n, getBound(t[mn.S]), n), cap});
			if (g == 0) {
				continue;
			}

			ans += 1ll*g*mn.F.F;
			mn.F.S -= g;
			if (mn.F.S)
				pq.push(mn);
			curPos += g;
			add(1, 0, n, getBound(t[mn.S]), n, g);
		}
	}
	cout << ans << "\n";
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