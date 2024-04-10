#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5;

int n, m;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int ans = 0;
	int la = 0, lb = 0, ra = 2e9, rb = 2e9;
	int l, r;
		
	n = read();
	
	for(i=1;i<=n;i++){
		l = read();
		r = read();
		la = max(la, l);
		ra = min(ra, r);
	}
	
	m = read();
	
	for(i=1;i<=m;i++){
		l = read();
		r = read();
		lb = max(lb, l);
		rb = min(rb, r);
	}
	
	cout << max(0, max(la - rb, lb - ra)) << endl;
	
	return 0;
}