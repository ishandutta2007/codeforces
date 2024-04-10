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

int n, sz;
string s;
pii sec[MAXN];
int seg[MAXN<<2];

void pushDown(int v) {
	if (seg[v] == -1) return;
	seg[v<<1^1] = seg[v<<1] = seg[v];
	seg[v] = -1;
}

void upd(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r) {
		seg[v] = val;
		return;
	}
	if (r <= b || e <= l) return;

	pushDown(v);
	int mid = b + e >> 1;
	upd(v<<1, b, mid, l, r, val);
	upd(v<<1^1, mid, e, l, r, val);
}

int get(int v, int b, int e, int pos) {
	if (seg[v] != -1) return seg[v];
	if (e - b == 1) return -1;
	
	int mid = b + e >> 1;
	pushDown(v);
	if (pos < mid)
		return get(v<<1, b, mid, pos);
	return get(v<<1^1, mid, e, pos);
}

int bw[MAXN], fw[MAXN];
void solve() {
	memset(seg, -1, sizeof(seg));
	cin >> n >> s;
	for (int l = 0; l < n;){
		if (s[l] == '0') {
			l++;
			continue;
		}
		int r = l;
		while (r < n && s[l] == s[r]) r++;
		sec[sz++] = {r-l, l};
		l = r;
	}

	for (int i = sz-1; ~i; i--){
		int ln = sec[i].F, start = sec[i].S;
		for (int j = 1; j <= ln; j++) {
			int p = get(1, 0, n, j);
			if (~p)
				bw[start + ln - j] = sec[p].S + j;
			else
				bw[start + ln - j] = n;
		}
		upd(1, 0, n, 0, ln, i);
	}

	memset(seg, -1, sizeof(seg));
	for (int i = 0; i < sz; i++) {
		int ln = sec[i].F, start = sec[i].S;
		for (int j = 1; j <= ln; j++) {
			int p = get(1, 0, n, j-1);
			if (~p)
				fw[start + j - 1] = sec[p].S + sec[p].F - j + 1;
			else
				fw[start + j - 1] = 0;
		}
		upd(1, 0, n, 0, ln, i);
	}


	ll ans = 0;
	for (int i = 0; i < sz; i++) {
		int ln = sec[i].F, start = sec[i].S;
		for (int j = 1; j < ln; j++) {
			ans += 1ll*(ln - j + 1)*j;
			ans -= j*2;
		}
		ans += 1ll*ln*(bw[start] - (start + ln - 1))*(start - fw[start + ln-1] + 1);
		for (int j = 1; j < ln; j++) {
			ans += 1ll*j*(bw[start + ln - j] - (start+ln-1));
			ans += 1ll*j*(start - fw[start + j-1] + 1);
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
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}