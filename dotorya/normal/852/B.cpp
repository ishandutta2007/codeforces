#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll u[105][105];
int M;
class Matrix {
public:
	ll v[105][105];
	Matrix() {
		memset(v, 0, sizeof(v));
		for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) v[i][j] = u[i][j];
	}
	Matrix operator * (const Matrix &l) const {
		memset(u, 0, sizeof(u));
		Matrix rv = Matrix();
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < M; k++) rv.v[i][j] = (rv.v[i][j] + v[i][k] * l.v[k][j]) % MOD;
			}
		}
		return rv;
	}
};

Matrix mypow(Matrix a, int x) {
	for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) u[i][j] = 0;
	for (int i = 0; i < M; i++) u[i][i] = 1;
	Matrix rv = Matrix();
	while (x) {
		if (x % 2) rv = rv * a;
		a = a * a;
		x /= 2;
	}
	return rv;
}

int in[3][1000050];
int cnt[1000050];
int main() {
	int N, L, i, j;
	scanf("%d %d %d", &N, &L, &M);
	for (i = 0; i < 3; i++) for (j = 1; j <= N; j++) scanf("%d", &in[i][j]);

	memset(cnt, 0, sizeof(cnt));
	for (i = 1; i <= N; i++) cnt[in[0][i] % M]++;
	for (i = 0; i < M; i++) for (j = 0; j < M; j++) u[i][j] = cnt[(j - i + M) % M];
	Matrix m1 = Matrix();

	memset(cnt, 0, sizeof(cnt));
	for (i = 1; i <= N; i++) cnt[in[1][i] % M]++;
	for (i = 0; i < M; i++) for (j = 0; j < M; j++) u[i][j] = cnt[(j - i + M) % M];
	Matrix m2 = Matrix();

	memset(cnt, 0, sizeof(cnt));
	for (i = 1; i <= N; i++) cnt[(in[1][i] + in[2][i]) % M]++;
	for (i = 0; i < M; i++) for (j = 0; j < M; j++) u[i][j] = cnt[(j - i + M) % M];
	Matrix m3 = Matrix();

	Matrix rv = m1 * mypow(m2, L - 2) * m3;
	printf("%lld\n", rv.v[0][0]);
	return 0;
}