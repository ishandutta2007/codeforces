#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int a, b;
	int ans = 0;
	
	cin >> a >> b;
	
	while(a <= b){
		ans++;
		a *= 3;
		b *= 2;
	}
	
	cout << ans << endl;
	
	return 0;
}