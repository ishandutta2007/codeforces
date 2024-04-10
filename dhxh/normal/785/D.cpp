#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n;

long long frac[maxn];

long long mod = 1e9 + 7;

string str;

long long qpow(long long b){
	long long ans = 1;
	long long x = mod - 2;
	
	while(x > 0){
		if(x % 2){
			ans *= b;
			ans %= mod;
		}
		
		x /= 2;
		b *= b;
		b %= mod;
	}
	
	return ans;
}

int init(){
	int i, j;
	
	frac[0] = 1;
	
	for(i=1;i<maxn;i++){
		frac[i] = (frac[i - 1] * i) % mod;
	}
	
	return 0;
}

long long getc(long long x, long long y){
	long long sa = frac[x] * qpow(frac[x - y]) % mod;
	long long sb = frac[y];
	
	return sa * qpow(sb) % mod;
}

int main(){
	int i, j;
	long long l = 0, r = 0;
	long long ans = 0;
	
	cin >> str; 	
	n = str.length();
	
	init();
	
	for(i=0;i<n;i++){
		if(str[i] == ')'){
			r++;
		}
	}
	
	for(i=0;i<n;i++){
		if(str[i] == '('){
			l++;
			ans += getc(l + r - 1, r - 1);
			ans %= mod;
		}else{
			r--;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}