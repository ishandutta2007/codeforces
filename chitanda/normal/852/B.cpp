#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int P = 1000000007;

const int MAXN = 100;
int N, L, M;
struct matrix{
	int n, m;
	int x[MAXN][MAXN];
	void clear(){
		memset(x, 0, sizeof(x));
	}
	void reset(){
		assert(n == m);
		clear();
		for(int i = 0; i < n; ++i)
			x[i][i] = 1;
	}
	matrix(int n = 0, int m = 0) : n(n), m(m){
		clear();
	}
	matrix operator * (const matrix &R) const{
		matrix res(n, R.m);
		assert(m == R.n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < R.m; ++k)
					res.x[i][k] = (res.x[i][k] + (ll)x[i][j] * R.x[j][k]) % P;
		return res;
	}
};

int cnt[MAXN];
int a[1000100];

void work(matrix &res, int n, bool k = 0){
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0, x; i < N; ++i){
		scanf("%d", &x);
		if(k) a[i] = (a[i] + x) % M;
		else a[i] = x % M;
		++cnt[a[i]];
	}
	matrix A(M, M);
	for(int i = 0; i < M; ++i)
		for(int j = 0; j < M; ++j)
			A.x[i][j] = cnt[(i + M - j) % M];
	for(; n; n >>= 1, A = A * A)
		if(n & 1) res = A * res;
}

int main(){
	scanf("%d%d%d", &N, &L, &M);
	matrix res(M, 1);
	res.x[0][0] = 1;
	work(res, 1);
	work(res, L - 2);
	work(res, 1, 1);
	printf("%d\n", res.x[0][0]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}