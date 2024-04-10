#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 100 + 5;
const ll MOD = 1e9 + 7;

int n;
ll k, a[MAXN];

struct Mat{
	ll v[MAXN][MAXN];
	ll n, m;
	Mat(ll nn, ll mm, ll x = 0){
		n = nn, m = mm;
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < m; j++)
				if (i == j)
					v[i][j] = x;
				else
					v[i][j] = 0;
	}
};

Mat mul(Mat a, Mat b){
	Mat ret(a.n, b.m, 0);
	for (ll i = 0; i < a.n; i++)
		for (ll j = 0; j < b.m; j++)
			for (ll w = 0; w < a.m; w++)
				ret.v[i][j] = (ret.v[i][j] + a.v[i][w] * b.v[w][j]) % MOD;
	return ret;
}

Mat pw(Mat a, ll b){
	Mat ret(a.n, a.m, 1);
	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ret;
}

int main(){
	cin >> n >> k;
	for (ll i = 0; i < n; i++)	cin >> a[i];
	Mat v(n, n, 0);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
				v.v[i][j] = 1;
	v = pw(v, k-1);
	Mat ans(n, 1, 0);
	for (int i = 0; i < n; i++)
		ans.v[i][0] = 1;
	
	ans = mul(v, ans);
	ll sm = 0;
	for (int i = 0; i < n; i++)
		sm = (sm + ans.v[i][0]) % MOD;
	cout << sm << endl;
	return 0;
}