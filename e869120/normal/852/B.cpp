#include<bits/stdc++.h>
#include<ctime>
#include<random>
using namespace std;


#define MOD 1000000007LL  
#define MODMOD MOD*MOD
const int matrix_size = 102;
struct matrix{
	int mat[matrix_size][matrix_size];  
	matrix(){
		memset(mat, 0, sizeof(mat));
	}
};
matrix operator *(const matrix &a, const matrix &b){
	matrix r;
	long long int tmp;
	for (int i = 0; i < matrix_size; i++){
		for (int j = 0; j < matrix_size; j++){
			tmp = 0;
			for (int k = 0; k < matrix_size; k++){
				tmp += (long long int)(a.mat[i][k]) * b.mat[k][j];
				if (tmp >= MODMOD)tmp -= MODMOD;
			}
			if (tmp >= MOD)tmp %= MOD;
			r.mat[i][j] = tmp;
		}
	}
	return r;
}
matrix operator +(const matrix &a, const matrix &b){
	matrix r;
	for (int i = 0; i < matrix_size; i++){
		for (int j = 0; j < matrix_size; j++){
			r.mat[i][j] += a.mat[i][j] + b.mat[i][j];
			if (r.mat[i][j] >= MOD){
				r.mat[i][j] -= MOD;
			}
		}
	}
	return r;
}
matrix ppow(matrix i, long long int j){
	if (j == 0){
		for (int i1 = 0; i1<matrix_size; i1++){
			for (int j = 0; j<matrix_size; j++){
				i.mat[i1][j] = (i1 == j);
			}
		}
		return i;
	}
	if (j == 1LL){
		return i;
	}
	j--;
	matrix r = i;
	while (j){
		if ((j & 1LL)){
			r = r*i;
		}
		i = i*i;
		j >>= 1LL;
	}
	return r;
}

#define MAX 1000002

int n;
int l;
int m;

vector<int> v;

vector<int> vv;
vector<int> en;

long long int dp[102];

matrix mat;

long long int go[102];

int main(){
	cin >> n >> l >> m;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
		dp[a%m]++;
	}
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		vv.push_back(a);
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < vv.size(); j++){
			int go = i + vv[j];
			go %= m;
			mat.mat[go][i]++;
		}
	}
	mat=ppow(mat, l-2);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			go[i] += dp[j] * mat.mat[i][j];
			go[i] %= MOD;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		int mm = m - (a%m);
		mm += m;
		mm -= (vv[i]%m);
		mm %= m;
		ans += go[mm];
	}
	ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}