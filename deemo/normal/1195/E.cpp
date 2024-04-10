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

const int MAXN = 3e3 + 10;

int n, m, x, y;
int b[MAXN*MAXN], a[MAXN][MAXN];
int up[MAXN][MAXN];

pii q[MAXN];
void solve() {
	cin >> n >> m >> x >> y;
	int g0, X, Y, Z;
	cin >> g0 >> X >> Y >> Z;
	b[0] = g0;
	for (int i = 1; i < n*m; i++) b[i] = (1ll*b[i-1]*X + Y) % Z;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i*m + j];

	for (int j = 0; j < m; j++){
		int h = 0, t = 0;
		for (int i = 0; i < n; i++){
			while (t^h && q[t-1].F > a[i][j]) t--;
			q[t++] = {a[i][j], i};
			if (q[h].S == i-x) h++;
			up[i][j] = q[h].F;
		}
	}

	ll ans = 0;
	for (int i = x-1; i < n; i++){
		int h = 0, t = 0;
		for (int j = 0; j < m; j++) {
			while (t^h && q[t-1].F > up[i][j]) t--;
			q[t++] = {up[i][j], j};
			if (q[h].S == j-y) h++;
			if (j + 1 >= y)
				ans += q[h].F;
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