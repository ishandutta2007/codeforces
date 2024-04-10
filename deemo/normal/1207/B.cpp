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

const int MAXN = 50 + 5;

int n, m, a[MAXN][MAXN], b[MAXN][MAXN];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	vector<pii> ans;
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j + 1 < m; j++)
			if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
				b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
				ans.push_back({i+1, j+1});
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j]){
				cout << "-1\n";
				return;
			}
	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x.F << " " << x.S << "\n";
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