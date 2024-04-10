#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 2e6 + 7;

int form(int n){
	if (n < 0) return n + MOD;
	if (n >= MOD) return n - MOD;
	return n;
}

int fact(int a, int b){
	return form((a * b) % MOD);
}

int sum(int a, int b){
	return form(a + b);
}

int power[MAXN], factorial[MAXN];

int get_pow(int a, int b){
	if (b == 0) return 1;
	if (b == 1) return a;
	int m = b / 2;

	int p = get_pow(a, m);
	if (b % 2 == 0){
		return fact(p, p);
	}
	else{
		return fact(fact(p, p), a);
	}
}

int c(int n, int k){
	return fact(fact(factorial[n], get_pow(factorial[k], MOD - 2)), get_pow(factorial[n - k], MOD - 2));
}

signed main(){
	power[0] = 1;
	for (int i = 1; i < MAXN; ++i){
		power[i] = fact(power[i - 1], 2);
	}

	factorial[0] = 1;
	for (int i = 1; i < MAXN; ++i){
		factorial[i] = fact(factorial[i - 1], i);
	}

	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	int ans = 1;
	int s = 1;
	for (int i = 0; i < n; ++i){
		s = fact(s, 2);
		ans = sum(ans, s);
	}
	
	for (int i = 0; i < n; ++i){
		int have_two_child = s - fact(c(n + i, i), 2);
		s = sum(s, have_two_child);
		ans = sum(ans, s);
	}

	cout << ans;
	return 0;
}