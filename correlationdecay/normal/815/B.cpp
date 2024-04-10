#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define maxn 300009
using namespace std;
const int MOD = 1e9 + 7;
long long fact[maxn], rfact[maxn];
long long mgml(long long a, int b){
	long long ans = 1;
	while(b){
		if(b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}
void init(){
	fact[0] = 1;
	for(int i = 1; i < maxn ; i++){
		fact[i] = fact[i -1] * i % MOD;
	}
	rfact[maxn - 1] = mgml(fact[maxn - 1], MOD - 2);
	for(int i = maxn - 2; i >= 0; i--){
		rfact[i] = rfact[i + 1] * (i + 1) % MOD;
	}
}
long long C(int n, int m){
	return fact[n] * rfact[n - m] % MOD * rfact[m] % MOD;
}
int n;
long long a[maxn];
long long b[maxn], c[maxn], d[maxn];

void update1(int m){
	c[0] = 0;
	c[m + 1] = 0;
	int sg = 1;
	for(int i = 1; i <= m + 1; i++){
		if(sg == 1)
			d[i] = c[i] - c[i - 1];
		else
			d[i] = c[i] + c[i - 1];
		sg *= -1;
	}
	for(int i = 1; i <= m + 1; i++)
		c[i] = d[i];
}

void update2(int m){
	c[0] = 0;
	c[m + 1] = 0;
	int sg = 1;
	for(int i = 1; i <= m + 1; i++){
		if(sg == 1)
			d[i] = c[i - 1] + c[i];
		else
			d[i] = c[i - 1] - c[i];
		sg *= -1;
	}
	for(int i = 1; i <= m + 1; i++)
		c[i] = d[i];
}

void output(){
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans + a[i] * b[i]) % MOD;
	}
	if(ans < 0)
	 	ans += MOD;
	 cout << ans << endl;
}
int main(){
	init();
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	
	if(n == 1){
		cout << a[1] << endl;
		return 0;
	}
	else{
		int m = n;
		while(m % 4 != 2)
			m--;
		int t = 0;
		for(int i = 1; i <= m; i++){
			c[i] = C(m / 2 - 1, t);
			if(i % 2 == 0)
				t++;
		}
		if(n == m){
			for(int i = 1; i <= n; i++)
				b[i] = c[i] % MOD;
			output();
			return 0;
		}
		update1(m); m++;
		if(n == m){
			for(int i = 1; i <= n; i++)
				b[i] = c[i] % MOD;
			output();
			return 0;
		}
		update2(m); m++;
		if(n == m){
			for(int i = 1; i <= n; i++)
				b[i] = c[i] % MOD;
			output();
			return 0;
		}
		update1(m); m++;
		if(n == m){
			for(int i = 1; i <= n; i++)
				b[i] = c[i] % MOD;
			output();
			return 0;
		}
	}
	return 0;
}