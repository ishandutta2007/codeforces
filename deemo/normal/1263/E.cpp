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
const int XX = MAXN - 5;

int q;
string s;
pii seg[MAXN<<2];
int lz[MAXN<<2];

pii merge(pii a, pii b){
	return {min(a.F, b.F), max(a.S, b.S)};
}

void pushDown(int v){
	if (!lz[v]) return;

	lz[v<<1] += lz[v];
	seg[v<<1].F += lz[v];
	seg[v<<1].S += lz[v];

	lz[v<<1^1] += lz[v];
	seg[v<<1^1].F += lz[v];
	seg[v<<1^1].S += lz[v];
	lz[v] = 0;
}

void upd(int v, int b, int e, int l, int r, int val){
	if (r <= b || e <= l) return;
	if (l <= b && e <= r){
		lz[v] += val;
		seg[v].F += val;
		seg[v].S += val;
		return;
	}

	int mid = b+e >> 1;
	pushDown(v);
	upd(v<<1, b, mid, l, r, val);
	upd(v<<1^1, mid, e, l, r, val);
	seg[v] = merge(seg[v<<1], seg[v<<1^1]);
}

char cc[MAXN];

void solve() {
	cin >> q >> s;
	for (int i = 0; i < MAXN; i++) cc[i] = 'a';

	int cur = 0;
	int sm = 0;
	for (int i = 0; i < q; i++){
		if (s[i] == 'L')
			cur = max(0, cur - 1);
		else if (s[i] == 'R')
			cur++;
		else {
			if (cc[cur] == '(')
				upd(1, 0, XX, cur, XX, -1), sm--;
			else if (cc[cur] == ')')
				upd(1, 0, XX, cur, XX, 1), sm++;


			cc[cur] = s[i];	
			if (cc[cur] == '(')
				upd(1, 0, XX, cur, XX, 1), sm++;
			else if (cc[cur] == ')')
				upd(1, 0, XX, cur, XX, -1), sm--;
		}
		if (seg[1].F < 0 || sm)
			cout << "-1 ";
		else
			cout << seg[1].S << " ";
	}
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