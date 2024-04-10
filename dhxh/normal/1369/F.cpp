#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int f[maxn][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool check(long long x, long long y){
	if(x > y) return false;
	if(y & 1){
		if(x & 1){
			return false;
		}else{
			return true;
		}
	}else{
		if(2 * x > y){
			return x & 1;
		}else if(4 * x > y){
			return true;
		}else{
			return check(x, y / 4);
		}
	}
}

int main(){
	int i, j;
	long long x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		scanf("%lld%lld", &x, &y);
		f[i][0] = check(x, y);
		f[i][1] = x * 2 > y || check(x, y / 2);
	}
	
	f[0][0] = 0, f[0][1] = 1;
	for(i=1;i<=n;i++){
		x = f[0][0], y = f[0][1];
		f[0][0] = (y && f[i][0]) || (x && !f[i][0]);
		f[0][1] = (y && f[i][1]) || (x && !f[i][1]);
	}
	
	printf("%d %d\n", f[0][0], f[0][1]);
	
	return 0;
}