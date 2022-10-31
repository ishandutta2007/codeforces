#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	double a, b;
	double ans = 1e10;
	
	cin >> n >> m;
	
	for(i=1;i<=n;i++){
		cin >> a >> b;
		ans = min(ans, a / b * m);
	}
	
	printf("%.12f\n", ans);
	
	return 0;
}