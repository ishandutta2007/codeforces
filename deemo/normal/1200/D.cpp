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

const int MAXN = 2e3 + 10;

int n, k;
string s[MAXN];
int mn[2][MAXN], mx[2][MAXN];
int pt[2][MAXN];
int sec[MAXN];

void solve() {
	cin >> n >> k;
	memset(mn, 63, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'B'){
				mn[0][i] = min(mn[0][i], j);
				mx[0][i] = max(mx[0][i], j);
				mn[1][j] = min(mn[1][j], i);
				mx[1][j] = max(mx[1][j], i);
			}
	}
	for (int i = 0; i < n; i++)
		pt[0][i+1] = pt[0][i] + int(mx[0][i] < 0), pt[1][i+1] = pt[1][i] + int(mx[1][i] < 0);

	int ans = pt[0][n] + pt[1][n];
	for (int i = 0; i + k <= n; i++){
		memset(sec, 0, sizeof(sec));
		for (int j = i; j < i+k; j++)
			if (mx[0][j] >= 0 && mx[0][j] - mn[0][j] <= k-1){
				sec[max(0, mx[0][j] - k + 1)]++;
				sec[mn[0][j]+1]--;
			}
		
		for (int j = 0; j < n; j++)
			if (mx[1][j] >= 0 && mn[1][j] >= i && mx[1][j] < i+k)
				sec[max(0, j-k+1)]++, sec[j+1]--;
		int sm = 0;
		for (int j = 0; j + k <= n; j++){
			sm += sec[j];
			ans = max(ans, sm + pt[0][n] + pt[1][n]);
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