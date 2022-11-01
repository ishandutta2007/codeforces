#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int mod = 10;

int qpow(int b, int x){
	int ans = 1;
	
	while(x){
		if(x % 2){
			ans *= b;
			ans %= mod;
		}
		
		b *= b;
		b %= mod;
		x /= 2;
	}
	
	return ans;
}

int main(){
	int i, j;
	int n;
	
	cin >> n;
	
	cout << qpow(1378, n) << endl;
	
	return 0;
}