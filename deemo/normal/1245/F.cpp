#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 30;//XXX

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

int l, r;
ll d[C+2][2][2];

void solve() {
	memset(d, 0, sizeof(d));
	cin >> l >> r;
	if (l == r){
		if (l+r == (l^r))
			cout << "1\n";
		else
			cout << "0\n";
		return;
	}

	int first;
	for (int w = C-1; ~w; w--)
		if (r>>w&1){
			if (l>>w&1){
				cout << "0\n";
				return;
			}
			first = w;
			break;
		}
	
	d[first][0][0] = 1;
	// d[first][0][1] = 1;
	
	bool fl = 0;
	for (int w = first; w; w--) {
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++){
				// 01
				if (a || (l>>w-1&1)==0)
					if (b || (r>>w-1&1)==1)
						d[w-1][a][b] += d[w][a][b];

				// 10
				int ta = a, tb = b;
				if (!(l>>w-1&1)) ta = 1;
				if ((r>>w-1&1)) tb = 1;
				d[w-1][ta][tb] += d[w][a][b];

				// 00
				if (a || (l>>w-1&1) == 0) {
					tb = b;
					if (r>>w-1&1) tb = 1;
					d[w-1][a][tb] += d[w][a][b];
				}
			}
		if (l>>(w-1)&1)
			fl = 1;
		if (!fl)
			d[w-1][0][1]++;
	}

	ll ans = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ans += d[0][i][j];
	ans *= 2;
	if (l == 0)
		ans++;
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