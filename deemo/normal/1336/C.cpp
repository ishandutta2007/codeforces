#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

void fix(int &x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

const int MAXN = 3e3 + 10;

string s, t;
int n, m;
int d[MAXN][MAXN], d2[MAXN][MAXN];
int sv[MAXN];

void solve() {
	cin >> s >> t;
	n = s.size(), m = t.size();
	for (int i = 0; i < m; i++)
		if (s[0] == t[i])
			d[i][i+1] = 2;
	for (int ln = 2; ln <=  m; ln++)
		for (int l = 0; l + ln <= m; l++) {
			if (s[ln-1] == t[l])
				d[l][l+ln] = d[l+1][l+ln];
			if (s[ln-1] == t[l+ln-1])
				add(d[l][l+ln], d[l][l + ln - 1]);
		}

	sv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		sv[i] = sv[i-1]<<1;
		fix(sv[i]);
	}

	d2[n][0] = 1;
	for (int i = n-1; ~i; i--) {
		for (int j = 0; j<= m; j++) {
			d2[i][j] = d2[i+1][j];
			if (j && s[i] == t[j-1])
				add(d2[i][j], d2[i+1][j-1]);
		}
		d2[i][0] += 1;
		fix(d2[i][0]);
	}

	int ans = 0;
	for (int k = 1; k <= m; k++) 
		if (d[m-k][m]) {
			int temp = d[m-k][m];
			temp = 1ll*temp*d2[k == m? k: k+1][m - k] % MOD;
			add(ans, temp);
		}

	for (int k = 1; k < n; k++)
		if (s[k] == t[m-1])
			add(ans, 1ll*sv[k]*d2[k+1][m-1] % MOD);

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