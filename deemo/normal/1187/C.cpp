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

const int MAXN = 1e3 + 10;

int n, m, t[MAXN], l[MAXN], r[MAXN], a[MAXN];
bool connected[MAXN];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> l[i] >> r[i], l[i]--;
		if (t[i] == 1)
			for (int j = l[i]; j + 1 < r[i]; j++)
				connected[j] = true;
	}

	int latest = 1e8;
	for (int l = 0; l < n;){
		int r = l;
		while (r + 1 < n && connected[r]) r++;

		r++;
		latest -= r-l;
		for (int i = l; i < r; i++) {
			a[i] = latest + (i-l);
		}
		latest--;

		l = r;
	}

	for (int i = 0; i < m; i++)
		if (!t[i]){
			bool fl = false;
			for (int j = l[i]; j + 1 < r[i]; j++)
				if (a[j] > a[j+1])
					fl = true;
			if (!fl){
				cout << "NO\n";
				return;
			}
		}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
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