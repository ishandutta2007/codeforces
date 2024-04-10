#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

long long n, m;

long long mod = 998244353;

long long a;

long long f = 0;
long long fb;
long long c = 0;
long long cb = 0;

int main(){
	int i, j;
	int x;
	
	scanf("%d", &x);
	n = x;
	
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		a = x;
		f = (f + f + c + a) % mod;
		c = (c + c + a) % mod;
	}
	
	printf("%I64d\n", f);
	
	return 0;
}