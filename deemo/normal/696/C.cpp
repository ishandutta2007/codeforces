#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = MOD - 1;

struct Mat{
	ll v[2][2];
	int n, m;
	Mat(int a, int b, int x = 0){
		n = a, m = b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (i == j)
					v[i][j] = x;
				else
					v[i][j] = 0;
	}
};

Mat mul(Mat a, Mat b){
	Mat ret(a.n, b.m);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int w = 0; w < a.m; w++)
				ret.v[i][j] = (ret.v[i][j] + a.v[i][w] * b.v[w][j]) % MOD;
	return ret;
}

Mat mpw(Mat a, ll b){
	Mat ret(a.n, a.m, 1);
	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ret;
}

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

ll c = pw(2, MOD - 2);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;	cin >> k;
	Mat v(2, 2);
	v.v[0][0] = 1;
	v.v[0][1] = 2;
	v.v[1][0] = 1;
	v.v[1][1] = 0;

	Mat ans(2, 1);

	ll y = 1;
	while (k--){
		ll t;	cin >> t;
		t %= MOD2;
		y = y * t % MOD2;
	}

	y = (y + MOD2 - 1) % MOD2;
	v = mpw(v, y);
	ans = mul(v, ans);
	y = pw(2ll, y);
	cout << v.v[1][0] << "/" << y << "\n";
	return 0;
}