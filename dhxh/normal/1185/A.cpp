#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

long long a, b, c, d;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> a >> b >> c >> d;
	
	if(a > b)swap(a, b);
	if(b > c)swap(b, c);
	if(a > b)swap(a, b);
	
	cout << max(0ll, d - (b - a)) + max(0ll, d - (c - b)) << endl;
	
	return 0;
}