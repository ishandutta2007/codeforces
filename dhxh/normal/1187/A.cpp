#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, s, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int T;
	
	cin >> T;
	
	while(T--){
		cin >> n >> s >> t; 
		long long a = s + t - n;
		cout << max(s, t) - a + 1 << endl;
	}
	
	return 0;
}