#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;

void add(ll &x, ll y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

const int MAXN = 2e5 + 10;
const int C = 35; 
const int CC = 18;

int n, m, sv[MAXN];
ll a[MAXN];
int bit[MAXN];
ll cnt[2][1<<CC][CC + 1], ans[C + 1];

void genAll(int mid, int cur) {
	int ln = cur - mid;
	for (int mask = 0; mask < 1<<ln; mask++) {
		ll temp = 0;
		for (int i = mid; i < cur; i++)
			if (mask>>i-mid&1)
				temp ^= a[i];
		temp >>= CC;
		cnt[0][temp][0]++;
	}
}

void go(int cur) {
	int mid = 0;
	while (bit[mid] < CC && mid < cur) mid++;
	genAll(mid, cur);
	
	int c = 0;
	for (int w = 0; w < C-CC; w++, c ^= 1) {
		memset(cnt[!c], 0, sizeof(cnt[!c]));
		for (int mask = 0; mask < 1<<C-CC; mask++) {
			for (int i = 0; i <= C-CC; i++) {
				cnt[!c][mask][i] = cnt[c][mask][i];
				if (i)
					add(cnt[!c][mask][i], cnt[c][mask^1<<w][i-1]);
			}
		}
	}
	// cout << cnt[c][2][0] << " " << cnt[c][2][1] << "  " << cnt[c][2][2] << endl;
	
	for (int mask = 0; mask < 1<<mid; mask++) {
		ll temp = 0;
		for (int i = 0; i < mid; i++)
			if (mask>>i&1)
				temp ^= a[i];
		
		int tempCount = __builtin_popcountll((1ll<<CC)-1 & temp);
		//cout << mask << " " << temp << endl;
		temp >>= CC;
		//cout << mask << " " << temp << endl;
		//cout << tempCount << endl;
		for (int i = 0; i <= C-CC; i++)
			add(ans[tempCount + i], cnt[c][temp][i]);
		//cout << ans[3] << endl;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		sv[i] = sv[i-1]<<1;
		sv[i] = fix(sv[i]);
	}

	int cur = 0;
	for (int w = 0; w < C; w++) {
		int i;
		for (i = cur; i < n; i++)
			if (a[i]>>w&1) 
				break;
		if (i == n) continue;

		swap(a[cur], a[i]);
		for (int i = 0; i < n; i++)
			if (cur!=i && a[i]>>w&1)
				a[i] ^= a[cur];
		bit[cur++] = w;
	}
	go(cur);
	
	for (int i = 0; i <= m; i++)
		cout << 1ll*ans[i]*sv[n-cur] % MOD << " ";
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