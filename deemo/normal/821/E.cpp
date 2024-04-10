#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 16;
const int MOD = 1e9 + 7;

struct Mat{
	int v[MAXN][MAXN];
	int n, m;
	Mat(int a, int b){
		n = a;
		m = b;
		memset(v, 0, sizeof(v));
	}
};

Mat cur(MAXN, 1);

Mat mul(Mat a, Mat b){
	Mat ret(a.n, b.m);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int w = 0; w < a.m; w++){
				ret.v[i][j] = (ret.v[i][j] + 1ll*a.v[i][w]*b.v[w][j]) % MOD;
			}
	return ret;
}

Mat pw(Mat a, ll b){
	Mat ret(a.n, a.m);
	for (int i = 0; i < ret.n; i++) ret.v[i][i] = 1;
	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ret;
}

void go(int y, ll t){
	for (int i = y+1; i < MAXN; i++) cur.v[i][0] = 0;
	Mat z(MAXN, MAXN);
	for (int i = 0; i <= y; i++)
		for (int j = 0; j <= y; j++)
			if (abs(i-j) <= 1)
				z.v[i][j] = 1;
	z = pw(z, t);
	cur = mul(z, cur);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cur.v[0][0] = 1;
	int n; ll k; cin >> n >> k;
	while (n--){
		ll l, r, y; cin >> l >> r >> y;
		r = min(r, k);
		go(y, r-l);
	}
	cout << cur.v[0][0] << "\n";
	return 0;
}