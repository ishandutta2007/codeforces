#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, k;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long t;
	
	cin >> n >> k;
	
	if(n - 1 + n < k){
		cout << 0 << endl;
	}else{
		if(k & 1){
			t = k / 2;
			cout << min(t, n - t) << endl;
		}else{
			t = k / 2;
			cout << min(t - 1, n - t);
		}
	}
	
	return 0;
}