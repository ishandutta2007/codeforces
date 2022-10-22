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

int n, T, a, b, type[MAXN], t[MAXN], sec[MAXN], cnt[2];

bool cmp(int u, int v){return t[u] < t[v];}

void solve() {
	cin >> n >> T >> a >> b;
	cnt[0] = cnt[1] = 0;
	for (int i = 0; i < n; i++) cin >> type[i], cnt[type[i]]++;
	for (int i = 0; i < n; i++) cin >> t[i];
	t[n++] = T+1;
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);

	int ans = 0;
	ll req = 0;
	for (int i = 0; i < n; i++){
		ll rem = t[sec[i]] - req - 1;
		if (rem >= 0){
			int t = i;
			
			ll g = min(rem/ a, 1ll*cnt[0]);
			t += g;
			rem -= g*a;
			g = min(rem/ b, 1ll*cnt[1]);
			t += g;

			ans = max(ans, t);
		}

		req += type[sec[i]] == 0? a: b;
		cnt[type[sec[i]]]--;
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