#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, t, k, d;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int a, b;
	
	n = read();
	t = read();
	k = read();
	d = read();
	
	a = n / k + (n % k != 0);
	
	b = d / t + (d % t != 0);
	
	if(a - b >= 2){
		cout << "YES" << endl;
	}else if(a - b == 1 and d % t){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}