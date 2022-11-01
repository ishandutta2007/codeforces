#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
long long mod = 1e9 + 7;

int n, m, t;

string str;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long ans = 0;
	long long x = 0, y = 0;
	
	cin >> str;
	
	n = str.length();
	
	for(i=0;i<n;i++){
		if(str[i] == 'a'){
			ans = (ans + x + 1) % mod;
			y = (y + x + 1) % mod;
		}else if(str[i] == 'b'){
			x = (x + y) % mod;
			y = 0;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}