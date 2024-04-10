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

const int MAXN = 3e5 + 10;

int n[3], a[3][MAXN], best[3];
pii sec[MAXN];

ll sq(ll x){ return x * x; }

void solve() {
	int sz = 0;
	cin >> n[0] >> n[1] >> n[2];
	for (int w = 0; w < 3; w++)
		for (int i = 0; i < n[w]; i++) {
			cin >> a[w][i];
			sec[sz++] = {a[w][i], w};
		}
	sort(sec, sec + sz);
	memset(a, -1, sizeof(a));
	memset(best, -1, sizeof(best));
	for (int i = 0; i < sz; i++) {
		for (int w = 0; w < 3; w++)
			a[w][i] = best[w];
		best[sec[i].S] = sec[i].F;
	}

	ll ans = 4e18;
	memset(best, 63, sizeof(best));
	int inf = 1e9;
	for (int i = sz-1; ~i; i--) {
			for (int j = 0; j < 3; j++)
				if (j^sec[i].S) 
					for (int other = 0; other < 3; other++)
						if (j^other && other^sec[i].S) {
							if (best[j] <= inf && a[other][i] != -1)
								ans = min(ans, sq(best[j] - a[other][i]) 
										+ sq(a[other][i] - sec[i].F)
										+ sq(best[j] - sec[i].F));
							break;
						}
		best[sec[i].S] = sec[i].F;
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