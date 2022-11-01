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
long long a, b, c, d;

struct matrix {
    long long f[5][5];
     
    matrix(){
        memset(f, 0, sizeof(f));
    };
};
 
matrix e;
matrix fib;
matrix f, g, h;
 
matrix add(matrix x, matrix y){
    int i, j;
    matrix ret;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            ret.f[i][j] = (x.f[i][j] + y.f[i][j]) % mod;
        }
    }
     
    return ret;
}
 
matrix mul(matrix x, matrix y){
    int i, j, k;
    matrix ret;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            for(k=0;k<5;k++){
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

long long qpow(long long b, long long x, long long p){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % p;
		}
		
		b = b * b % p;
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
	long long ans = 1;
	
	for(i=0;i<5;i++)e.f[i][i] = 1;
	
	mod--;
	
	cin >> n >> a >> b >> c >> d;
	h.f[0][2] = 1;
	h.f[1][0] = 1;
	h.f[1][2] = 1;
	h.f[2][1] = 1;
	h.f[2][2] = 1;
	
	g = qpow(h, n - 3);
	
	fib.f[0][0] = 1;
	f = mul(fib, g);
	ans = qpow(a, f.f[0][2], mod + 1);
	
	fib.f[0][0] = 0;
	fib.f[0][1] = 1;
	f = mul(fib, g);
	ans = ans * qpow(b, f.f[0][2], mod + 1) % (mod + 1);
	
	fib.f[0][1] = 0;
	fib.f[0][2] = 1;
	f = mul(fib, g);
	ans = ans * qpow(c, f.f[0][2], mod + 1) % (mod + 1);
	
	memset(h.f, 0, sizeof(h.f));
	memset(fib.f, 0, sizeof(fib.f));
	
	fib.f[0][4] = 2;
	
	h.f[0][2] = 1;
	h.f[1][0] = h.f[1][2] = 1;
	h.f[2][1] = h.f[2][2] = 1;
	h.f[3][2] = h.f[3][3] = 1;
	h.f[4][3] = h.f[4][4] = 1;
	g = qpow(h, n - 2);
	f = mul(fib, g);
	ans = ans * qpow(d, f.f[0][2], mod + 1) % (mod + 1);
	
	cout << ans << endl;
	
	return 0;
}