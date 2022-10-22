#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 5e4 + 10;
const ll LOG = 30 + 3;
const ll MAXX = 100 + 3;

struct Mat{
	ll v[MAXX][MAXX];
	Mat(ll z = 0){
		for (ll i = 0; i < MAXX; i++)
			for (ll j = 0; j < MAXX; j++)
				if (i == j)
					v[i][j] = z;
				else
					v[i][j] = 0;
	}
};

Mat mul(Mat a, Mat b){
	Mat ret;
	for (ll i = 0; i < MAXX; i++)
		for (ll j = 0; j < MAXX; j++)
			for (ll w = 0; w < MAXX; w++)
				ret.v[i][j] = (ret.v[i][j] + a.v[i][w] * b.v[w][j]) % MOD;
	return	ret;
}

Mat pw(Mat a, ll b){
	Mat ret(1);
	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return	ret;
}

ll n, b, k, x;
ll cnt[20], c[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> b >> k >> x;
	while (n--){
		ll y;	cin >> y;
		cnt[y]++;
		c[y % x]++;
	}

	Mat ans;
	for (ll i = 0; i < x; i++)	ans.v[i][0] = c[i];
	Mat tt;
	for (ll i = 0; i < x; i++)
		for (ll j = 0; j < x; j++)
			for (ll w = 1; w < 10; w++)
				if ((j * 10LL + w) % x == i)	tt.v[i][j] += cnt[w];
	tt = pw(tt, b - 1);
	ans = mul(tt, ans);
	cout << ans.v[k][0] % MOD << "\n";
	return	0;
}