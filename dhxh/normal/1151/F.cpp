#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long mod = 1e9 + 7;

int n, m, t;

int a[105];
long long cnt[2];

long long inv2;
long long inv;

struct matrix {
	long long f[51][51];
	
	matrix(){
		memset(f, 0, sizeof(f));
	};
};

matrix e;
matrix f;
matrix h;

matrix add(matrix x, matrix y){
	int i, j;
	matrix ret;
	for(i=0;i<=50;i++){
		for(j=0;j<=50;j++){
			ret.f[i][j] = (x.f[i][j] + y.f[i][j]) % mod;
		}
	}
	
	return ret;
}

matrix mul(matrix x, matrix y){
	int i, j, k;
	matrix ret;
	for(i=0;i<=50;i++){
		for(j=0;j<=50;j++){
			for(k=0;k<=50;k++){
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

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		
		b = b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

long long getc(long long x){
	if(x <= 0)return 0;
	return x * (x - 1) % mod * inv2 % mod;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	long long x, y;
	
	inv2 = qpow(2, mod - 2);
	
	for(i=0;i<=50;i++){
		e.f[i][i] = 1;
	}
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		cnt[a[i]]++;
	}
	
	inv = qpow(getc(n), mod - 2);
	
	x = min(cnt[0], cnt[1]);
	y = 0;
	
	for(i=1;i<=cnt[0];i++){
		if(a[i] != 0)y++;
	}
	
	for(i=0;i<=x;i++){
		if(i - 1 >= 0)h.f[i][i - 1] = 1ll * i * i * inv % mod;
		h.f[i][i] = 1ll * (getc(cnt[0]) + getc(cnt[1]) + i * (cnt[0] - i) + i * (cnt[1] - i)) * inv % mod;
		if(i + 1 <= x)h.f[i][i + 1] = 1ll * (cnt[0] - i) * (cnt[1] - i) * inv % mod;
	}
	
	f.f[0][y] = 1;
	printf("%lld\n", mul(f, qpow(h, m)).f[0][0]);
	
	return 0;
}