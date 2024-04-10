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
using namespace std;
map<long long,long long>mp1,mp2;
long long f(long long x){
	if(mp1.count(x))
		return mp1[x];
	if(x <= 1)
		return mp1[x] = 1;
	else
		return mp1[x] = 2 * f(x / 2) + 1;
}
long long g(long long x){
	if(mp2.count(x))
		return mp2[x];
	if(x == 1)
		return mp2[x] = 1;
	if(x == 0)
		return mp2[x] = 0;
	else
		return mp2[x] = 2 * g(x / 2) + (x % 2);
}
long long solve(long long n, long long x){
	if(x == 0)
		return 0;
	if(f(n) == x)
		return g(n);
	if(f(n / 2) >= x)
		return solve(n / 2, x);
	if(f(n / 2) + 1 >= x){
		return solve(n / 2, x - 1) + (n % 2);
	}
	return g(n / 2) + (n % 2) + solve(n / 2, x - f(n / 2) - 1);
}
int main(){
	long long n, l ,r;
	cin >> n >> l >> r;
	cout << solve(n, r) - solve(n, l - 1) << endl;
	return 0;
}