#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n, m;
db a[111][111];
db can[11][111];
int color[11][111];
db dp[11][77][77][77];

db calc(int lvl, int vl, int vr, int last){
	if (lvl == 0) return 0;
	if (dp[lvl][vl][vr][last] != -1) return dp[lvl][vl][vr][last];

	db vm = (vl + vr) >> 1;

	if (last >= vl && last <= vr){
		return calc(lvl - 1, vl, vm, last) + calc(lvl - 1, vm + 1, vr, last);
	}

	
	db ans = 0;

	for (int i = vl; i <= vr; i++){
		db now = 0;
		for (int d = 1; d <= lvl; d++) now += can[d][i] * (1 << (d - 1));
		db val = 0;
		if (vl != vr){
			val = calc(lvl - 1, vm + 1, vr, i) + calc(lvl - 1, vl, vm, i);
		}
		ans = max(ans, now + val);
	}

	dp[lvl][vl][vr][last] = ans;
	//cout << lvl << ' ' << vl << ' ' << vr << ' ' << ans << endl;
	return ans;
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m; n = (1 << m);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
		cin >> a[i][j];
		a[i][j] /= 100;
	}

	for (int i = 0; i < m; i++){
		int len = (1 << (i + 1));
		int uk = 0;
		while(1){
			if (uk >= n) break;
			for (int j = 0; j < len; j++) color[i][uk + j] = uk;
			uk += len;
		}
	}

	for (int i = 0; i < n; i++) can[0][i] = 1;
	for (int cc = 1; cc <= m; cc++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) if (i != j && (cc == 1 || color[cc - 2][i] != color[cc - 2][j]) && color[cc - 1][i] == color[cc - 1][j]) can[cc][i] += can[cc - 1][j] * a[i][j];
			can[cc][i] *= can[cc - 1][i];
		}
	}

	//for (int i = 0; i < n; i++){
	//	for (int cc = 1; cc <= m; cc++){
	//		cout << can[cc][i] << ' ';
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < 11; i++) for (int j = 0; j < 77; j++) for (int s = 0; s < 77; s++) for (int last = 0; last < 77; last++) dp[i][j][s][last] = -1;

	cout.precision(10);
	cout << fixed << calc(m, 0, n - 1, 76);
}