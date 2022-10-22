#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 200 + 3;

struct Mat{
	ld v[MAXN][MAXN];
	int n, m;
	Mat(int N, int M){
		n = N, m = M;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				v[i][j] = 0;
	}
};

int n, x;
ld p[MAXN];

Mat mul(Mat a, Mat b){
	Mat ret(a.n, b.m);
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < b.m; j++)
			for (int w = 0; w < a.m; w++)
				ret.v[i][j] += a.v[i][w] * b.v[w][j];
	return ret;
}

Mat pw(Mat a, int b){
	Mat ret(a.n, a.n);
	for (int i = 0; i < a.n; i++)
		ret.v[i][i] = 1;

	while (b){
		if (b & 1)
			ret = mul(ret, a);
		b >>= 1;
		a = mul(a, a);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n >> x;
	for (int i = 0; i <= x; i++)	cin >> p[i];

	Mat v(MAXN, 1);
	v.v[0][0] = 1;
	Mat s(MAXN, MAXN);
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++){
			int u = i^j;
			if (u >= MAXN)	continue;
			s.v[u][i] = p[j];
		}

	s = pw(s, n);
	v = mul(s, v);
	cout << ld(1.)-v.v[0][0] << endl;
	return 0;
}