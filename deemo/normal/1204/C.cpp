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

const int MAXN = 100 + 5;
const int MAXM = 1e6 + 10;

int n, m, a[MAXM];
int d[MAXN][MAXN];
pii dp[MAXM];
int lst[MAXN];

void go(int v){
	if (dp[v].S != -1)
		go(dp[v].S);
	cout << a[v]+1 << " ";
}

void solve() {
	cin >> n;
	memset(d, 63, sizeof(d));
	for (int i = 0; i < n; i++) d[i][i] = 0;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				d[i][j] = 1;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	cin >> m;
	for (int i = 0; i < m; i++) cin >> a[i], a[i]--;

	memset(lst, -1, sizeof(lst));
	dp[0] = {1, -1};
	lst[a[0]] = 0;
	for (int i = 1; i < m; i++) {
		dp[i] = {1e9, -1};
		for (int other = 0; other < n; other++)
			if (other != a[i] && lst[other] != -1 && d[other][a[i]] == i-lst[other])
				dp[i] = min(dp[i], {dp[lst[other]].F+1, lst[other]});
		lst[a[i]] = i;
	}
	cout << dp[m-1].F << "\n";
	go(m-1);
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