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

int n, m, k, t, a[MAXN];
int l[MAXN], r[MAXN], d[MAXN];
pii sec[MAXN]; int sz;

int sm[MAXN];
int get(int mid){
	sz = 0;
	memset(sm, 0, sizeof(sm));
	for (int i = 0; i < k; i++)
		if (d[i] > mid)
			sm[l[i]]++, sm[r[i]]--;

	int res = m+1;
	int cur = 0;
	for (int i = 0; i < m+1; i++) {
		cur += sm[i];
		if (cur)
			res += 2;
	}
	return res;
}

void solve() {
	cin >> n >> m >> k >> t;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);

	for (int i = 0; i < k; i++) cin >> l[i] >> r[i] >> d[i], l[i]--;

	int lo = 0, hi = MAXN;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (get(mid) <= t)
			hi = mid;
		else
			lo = mid;
	}
	int tt = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= hi)
			tt++;
	cout << tt << "\n";
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