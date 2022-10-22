#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MX = 100 + 2;
const int MOD = 1e6 + 3;

int m, w, h;

struct Mat{
	ll v[MX][MX];
	int n, m;
	Mat(int a, int b, int x = 0){
		n = a, m = b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)	v[i][j] = 0;
		for (int i = 0; i < n; i++)
			v[i][i] = x;
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
	cin >> m >> w >> h;
	Mat x(w + 1, 1);
	x.v[0][0] = 1;
	Mat b(w + 1, w + 1);
	for (int j = 0; j <= w; j++)
		b.v[0][j] = 1;
	for (int i = 1; i <= w; i++)
		b.v[i][i - 1] = h;
	b = pw(b, m + 1);
	x = mul(b, x);
	cout << x.v[0][0] << endl;
	return 0;
}