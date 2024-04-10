#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n;
long long ans = 0;

int a[] = {1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	if(n == 0){
		cout << 1 << endl;
		return 0;
	}
	
	while(n){
		ans += a[n % 16];
		n /= 16;
	}
	
	cout << ans << endl;
	
	return 0;
}