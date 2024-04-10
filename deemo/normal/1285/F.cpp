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

const int MAXN = 1e5 + 2;

int n, a[MAXN];
int pr[MAXN];
vector<int> primes[MAXN];
int cnt[MAXN];
int mul[MAXN];
int cntMask[MAXN];

int count(int v) {
	int t = primes[v].size();
	int ret = cntMask[1];
	mul[0] = 1;
	for (int mask = 1; mask < 1<<t; mask++) {
		int u = __builtin_ctz(mask&-mask);
		mul[mask] = mul[mask^1<<u] * primes[v][u];
		
		int temp = cntMask[mul[mask]];
		if (__builtin_popcount(mask)&1)
			ret -= temp;
		else
			ret += temp;
	}
	return ret;
}

void addMasks(int v, int t, int g){
	int tt = primes[v].size();
	mul[0] = 1;
	cntMask[1] += t * cnt[g*v];
	for (int mask = 1; mask < 1<<tt; mask++) {
		int u = __builtin_ctz(mask&-mask);
		mul[mask] = mul[mask^1<<u] * primes[v][u];
		cntMask[mul[mask]] += t * cnt[g*v];
	}
}

void solve() {
	for (int i = 2; i < MAXN; i++)
		if (pr[i] == 0)
			for (int j = i; j < MAXN; j += i) {
				pr[j] = 1;
				primes[j].push_back(i);
			}

	ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		ans = max<ll>(ans, a[i]);
	}

	for (int i = 1; i < MAXN; i++){
		int mx = (MAXN-1)/ i;
		if (mx == 1) continue;

		for (int j = 1; j <= mx; j++)
			addMasks(j, 1, i);

		int l = 1;
		for (int j = mx; j && l <= j; j--) {
			addMasks(j, -1, i);
			if (!cnt[i*j] || !count(j)) continue;
			do {
				addMasks(l++, -1, i);
			} while(l < j && count(j));
			ans = max(ans, 1ll*i*j*(l-1));
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