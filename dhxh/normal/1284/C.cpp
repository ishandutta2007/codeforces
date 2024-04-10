#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 3e5 + 5;
int N = 3e5;

long long n, m, t;

long long fac[maxn];

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % m;
		}
		
		x >>= 1;
		b = b * b % m;
	}
	
	return ret;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	long long ans = 0;
	
	cin >> n >> m;
	
	fac[0] = 1;
	for(i=1;i<=N;i++){
		fac[i] = fac[i - 1] * i % m;
	}
	
	for(i=1;i<=n;i++){
		ans = (ans + (n - i + 1) * (n - i + 1) % m * fac[i] % m * fac[n - i]) % m;
	}
	
	cout << ans << endl;
	
	return 0;
}