#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 1e9 + 7;

long long n, m, t;

struct matrix {
	long long f[101][101];
	
	matrix(){
		memset(f, 0, sizeof(f));
	};
};

matrix e;
matrix g;
matrix h;

matrix add(matrix x, matrix y){
	int i, j;
	matrix ret;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			ret.f[i][j] = (x.f[i][j] + y.f[i][j]) % mod;
		}
	}
	
	return ret;
}

matrix mul(matrix x, matrix y){
	int i, j, k;
	matrix ret;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			for(k=0;k<100;k++){
				ret.f[i][j] = (ret.f[i][j] + x.f[i][k] * y.f[k][j]) % mod;
			}
		}
	}
	
	return ret;
}

matrix qpow(matrix b, long long x){
	matrix ret = e;
	
	while(x){
		if(x & 1){
			ret = mul(ret, b);
		}
		
		b = mul(b, b);
		x >>= 1;
	}
	
	return ret;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n >> m;
	
	for(i=0;i<m;i++){
		e.f[i][i] = 1;
	}
	
	h.f[0][0] = h.f[m - 1][0] = 1;
	
	for(i=1;i<m;i++){
		h.f[i - 1][i] = 1;
	}
	
	g.f[0][0] = 1;
	
	cout << mul(g, qpow(h, n)).f[0][0] << endl;
	
	return 0;
}