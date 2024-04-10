#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#define maxn 300009
using namespace std;
const int MOD = 1e9 + 7;
long long fact[maxn],rfact[maxn];
long long mgml(long long a, int b){
	long long res = 1;
	while(b){
		if(b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
void init(){
	fact[0] = 1;
	for(int i = 1; i < maxn; i++)
		fact[i] = fact[i - 1] * i % MOD;
	for(int i = 0; i < maxn; i++)
		rfact[i] = mgml(fact[i], MOD - 2);
}
long long C(int n ,int m){
	if(n < 0 || m < 0 || n - m < 0)
		return 0;
	return fact[n] * rfact[m] % MOD * rfact[n - m] % MOD;
}
long long solve1(int f, int w, int h){
	long long sum1 = 0, sum2 = 0, sum3 = 0;
	for(int k = 1; k <= f && k <= w; k++){
		sum1 = (sum1 + C(w - 1, k - 1) * C(f - 1, k - 1)) % MOD;
	}
	for(int k = 2; k <= f && k - 1 <= w; k++){
		sum2 = (sum2 + C(f - 1, k - 1) * C(w - 1, k - 2)) % MOD;
	}
	if(w == 0 && f > 0)
		sum2++;
	for(int k = 2; k - 1 <= f && k <= w; k++){
		sum3 = (sum3 + C(w - 1, k - 1) * C(f - 1, k - 2)) % MOD;
	}
	if(f == 0 && w > 0)
		sum3++;
	return (sum1 + sum1 + sum2 + sum3) % MOD;
}
long long solve2(int f, int w, int h){
	long long sum1 = 0, sum2 = 0, sum3 = 0;
	for(int k = 1; k <= f && k <= w && k <= w - 1LL * k * h; k++){
		sum1 = (sum1 + C(w - k * h - 1, k - 1) * C(f - 1, k - 1)) % MOD;		
	}
	for(int k = 2; k <= f && k - 1 <= w && k - 1 <= w -  1LL * (k - 1) * h; k++){
		sum2 = (sum2 + C(f - 1, k - 1) * C(w - (k - 1) * h - 1, k - 2)) % MOD;
	}
	if(w == 0)
		sum2++;
	for(int k = 2; k - 1 <= f && k <= w && k <= w - 1LL * h * k; k++){
		sum3 = (sum3 + C(w - h * k - 1, k - 1) * C(f - 1, k - 2)) % MOD;
	}
	if(f == 0 && w > h)
		sum3++;
	return (sum1 + sum1 + sum2 + sum3) % MOD;
}
int main(){
	init();
	int f, w, h;
	cin >> f >> w >> h;
	if(f == 0 && w == 0){
		puts("1");
		return 0;
	}
	long long p = solve1(f, w, h);
	long long q = solve2(f, w, h);
	cout << q * mgml(p, MOD - 2) % MOD << endl;
	return 0;
}