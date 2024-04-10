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

const int MAXN = 5e3 + 10;

int n, a[MAXN];
vector<int> vec[MAXN];

int cnt[MAXN], which[MAXN];
int where[MAXN][MAXN];
pii get(int ind) {
	pii ret {0, 1};
	int c = 0;
	if (ind) {
		for (auto h: vec[a[ind-1]])
			if (h == which[ind-1])
				c++;
		if (c == 0) return {-1, 0};
	}

	for (int i = 0; i < n; i++) {
		int cLeft = 0, cRight = 0, cBoth = 0;
		for (int h: vec[i]) {
			if (h > cnt[i]) break;
			if (where[i][h] < ind && where[i][cnt[i]-h+1] >= ind)
				cBoth++;
			else if (where[i][h] < ind)
				cLeft++;
			else if (where[i][cnt[i]-h+1] >= ind)
				cRight++;
		}
	
		if (ind && a[ind-1] == i) {
			ret.F++;
			ret.S = 1ll*ret.S*c % MOD;
			if (where[i][cnt[i] - which[ind-1] + 1] >= ind)
				cBoth--;
			if (cBoth + cRight) {
				ret.F++;
				ret.S = 1ll*ret.S*(cBoth + cRight) % MOD;
			}
		} else {
			if (cLeft) {
				ret.F++;
				if (cRight + cBoth) {
					ret.F++;
					int temp = 1ll*cLeft*(cBoth + cRight) % MOD;
					if (cBoth)
						temp = (temp + 1ll*cBoth*(cBoth + cRight - 1)) % MOD;

					ret.S = 1ll*ret.S*temp % MOD;
				} else {
					ret.S = 1ll*ret.S*cLeft % MOD;
				}
			} else if (cBoth) {
				ret.F++;
				if (cRight + cBoth - 1) {
					ret.F++;
					ret.S = 1ll*ret.S*cBoth%MOD*(cRight + cBoth - 1) % MOD;
				} else {
					ret.S = 2ll*ret.S%MOD;
				}
			} else if (cRight) {
				ret.F++;
				ret.S = 1ll*ret.S*cRight%MOD;
			}
		}
	}

	return ret;
}

void solve() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i], a[i]--;
		which[i] = ++cnt[a[i]];
		where[a[i]][cnt[a[i]]] = i;
	}
	for (int i = 0; i < m; i++) {
		int f, h; cin >> f >> h;
		f--;
		vec[f].push_back(h);
	}
	for (int i = 0; i < n; i++) sort(vec[i].begin(), vec[i].end());

	pii ans {0, 1};
	for (int i = 0; i <= n; i++) {
		auto x = get(i);
		if (ans.F < x.F)
			ans = x;
		else if (ans.F == x.F)
			add(ans.S, x.S);
	}

	if (ans.F == 0)
		ans.S = 1;
	cout << ans.F << " " << ans.S << "\n";
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