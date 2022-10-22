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

int n, m, a[MAXN];

int getMax(int t) {
	int res = 0;
	for (int i = 2; i <= t; i += 2)
		res += t-i;
	return res;
}

int get(int t) {
	int r = t - 2, res = 0;
	for (int l = 0; l < r; l++) {
		while (l < r && a[l] + a[r] > a[t-1]) r--;
		if (l >= r) break;

		if (a[l] + a[r] == a[t-1]) res++;
	}
	return res;
}

void go(int t) {
	int temp = getMax(t-1);
	for (int i = 0; i < t; i++) a[i] = i + 1;
	int inc = (int)1e4 + 10;
	for (int i = t; i < n; i++) a[i] = (int)1e8 + inc, inc += (int)1e4 + 10;
	
	while (get(t) != m - temp)
		a[t-1]++;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		if (getMax(i) >= m) {
			go(i);
			return;
		}
	cout << "-1\n";
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