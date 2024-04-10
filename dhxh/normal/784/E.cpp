#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n;
long long ans = 1;

int a[5], b[10], c[10], d[10], e[10];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	
	b[1] = a[1] ^ a[2];
	b[2] = a[3] | a[4];
	b[3] = a[2] & a[3];
	b[4] = a[1] ^ a[4];
	
	c[1] = b[1] & b[2];
	c[2] = b[3] | b[4];
	d[1] = c[1] ^ c[2];
	
	cout << d[1] << endl;
	
	return 0;
}