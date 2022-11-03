#include <bits/stdc++.h>
                     
using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

const int mod = (int)1e9 + 7;

int m, n;
string a[55];

int mult(int a, int b){
	return a * (ll)b % mod;
}

int sum(int a, int b){
	int ans = a + b;
	if (ans >= mod) ans -= mod;
	return ans;
}

int dp[1005][1005];
int ss[1005];

int main(){
	srand(123);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dd;
	for (int i = 0; i < m; i++) dd.pub(i);
	vector<vector<int> > t;
	t.pub(dd);
	for (int i = 0; i < n; i++){
		vector<vector<int> > gg;
		for (int j = 0; j < t.size(); j++){
			vector<int> f[2];
			for (int x : t[j]) f[a[i][x] - '0'].pub(x);
			if (f[0].size()) gg.pub(f[0]);
			if (f[1].size()) gg.pub(f[1]);
		}
		t = gg;
	}
	dp[1][1] = 1;
	for (int i = 1; i < 1005; i++){
		dp[i][0] = 0;
		for (int j = 1 + (i == 1); j <= i; j++){
			dp[i][j] = sum(dp[i - 1][j - 1], mult(j, dp[i - 1][j]));
		}
	}
	for (int i = 1; i < 1005; i++){
		for (int j = 1; j <= i; j++) ss[i] = sum(ss[i], dp[i][j]);
	}
	int ans = 1;
	for (auto x : t) ans = mult(ans, ss[x.size()]);
	cout << ans;
}