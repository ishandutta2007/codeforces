//Toxic

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 100 + 4;
const ll MOD = 1e9 + 7;

ll n, d, cnt[200], dp[200];

struct Mat{
	ll v[MAXN][MAXN];
	Mat(ll x = 1){
		for (ll i = 0; i < MAXN; i++)
			for (ll j = 0; j < MAXN; j++)
				if (i == j)
					v[i][j] = x;
				else
					v[i][j] = 0;
	}
};

Mat mul(Mat a, Mat b, ll aa = 100, ll bb = 100, ll cc = 100){
	Mat ret(0);
	for (ll i = 0; i <= aa; i++)
		for (ll j = 0; j <= bb; j++)
			for (ll w = 0; w <= cc; w++)
				ret.v[i][j] = (ret.v[i][j] + a.v[i][w] * b.v[w][j]) % MOD;
	return	ret;
}

Mat pw(Mat a, ll b){
	Mat ret;
	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;	while (n--){ll x;	cin >> x;	cnt[x]++;}
	dp[0] = 1;
	for (ll i = 1; i <= 103; i++)
		for (ll j = 0; j < i; j++)
			dp[i] = (dp[i] + dp[j] * cnt[i - j]) % MOD;
	
	if (d < 100){
		ll ans = 0;
		for (ll i = 0; i <= d; i++)
			ans = (ans + dp[i]) % MOD;
		cout << ans << endl;
		return	0;
	}
	
	Mat f(0);
	for (ll i = 0; i <= 100; i++)
		for (ll j = 0; j <= 100; j++)
			if (i - j == 1)	f.v[i][j] = 1;
	f.v[100][99] = 0;
	for (ll i = 0; i < 100; i++)
		f.v[i][100] = f.v[i][99] = cnt[100 - i];
	f.v[100][100] = 1;

	Mat g(0);
	for (ll i = 0; i < 100; i++)	g.v[0][i] = dp[i], g.v[0][100] = (g.v[0][100] + dp[i]) % MOD;
	f = pw(f, d - 99);
	g = mul(g, f, 1, 100, 100);
	cout << g.v[0][100] << endl;

	return	0;
}