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

int n, m, k, s;
int r[MAXN], c[MAXN], safes[MAXN];
vector<pair<int, ll>> vec[MAXN];
int mn[MAXN], mx[MAXN], cnt[MAXN];
ll ans;

void process(int row, int col, ll cost){
	int pos = lower_bound(safes, safes + s, col) - safes;
	if (pos < s)
		vec[row+1].push_back({safes[pos], cost + safes[pos] - col + 1});
	if (pos - 1 >= 0){
		pos--;
		vec[row+1].push_back({safes[pos], cost + col - safes[pos] + 1});
	}
}

void solve() {
	memset(mn, 63, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	cin >> n >> m >> k >> s;
	k++;
	for (int i = 0; i < k; i++) {
		if (i < k-1)
			cin >> r[i] >> c[i];
		else
			r[i] = c[i] = 1;
		r[i]--, c[i]--, mn[r[i]] = min(mn[r[i]], c[i]), mx[r[i]] = max(mx[r[i]], c[i]), cnt[r[i]]++;
	}
	for (int i = 0; i < s; i++) cin >> safes[i], safes[i]--;
	sort(safes, safes + s);
	int rem = k;
	vec[0].push_back({0, 0});
	ans = 1e18;
	ll xx = 0;
	for (int i = 0; rem && i < n; i++){

		bool fl = rem == cnt[i];
		rem -= cnt[i];

		if (mx[i] >= 0) {
			vector<pair<int, ll>> vecTemp;
			sort(vec[i].begin(), vec[i].end());
			for (int l = 0; l < (int)vec[i].size(); ){
				int r = l;
				while (r < (int)vec[i].size() && vec[i][l].F == vec[i][r].F) r++;
				vecTemp.push_back(vec[i][l]);
				l = r;
			}
			vec[i] = vecTemp;

			for (auto x: vec[i]){
				int col = x.F;
				ll cost = x.S + xx;
				if (mx[i] >= 0) {
					{
						ll temp = cost;
						if (mn[i] < col)
							temp += col - mn[i];
						temp += mx[i] - min(col, mn[i]);
						if (fl)
							ans = min(ans, temp);
						process(i, mx[i], temp);
					}
					{
						ll temp = cost;
						if (mx[i] > col)
							temp += mx[i] - col;
						temp += max(col, mx[i]) - mn[i];
						if (fl)
							ans = min(ans, temp);
						process(i, mn[i], temp);
					}
				}
			}
			xx = 0;
		}
		else
			vec[i+1] = vec[i], xx++;
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