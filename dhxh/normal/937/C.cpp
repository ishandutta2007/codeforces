#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, k, d, t;

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

int main(){
	int i, j;
	double ans = 0;
	long long pa, pb;
	long long tmp;
	
	cin >> k >> d >> t;
	
	t *= 2;
	
	if(k % d == 0){
		printf("%.12lf\n", (double)(t / 2));
		return 0;
	}else{
		tmp = k / d;
		pa = d * tmp;
		pb = k * 2 + (d * (tmp + 1) - k);
		ans += t / pb * (pa + d);
		
		t = t % pb;
		if(t <= k * 2){
			ans += (double)t / 2.0;
		}else{
			ans += k;
			t -= 2 * k;
			ans += t;
		}
	}
	
	printf("%.12lf\n", ans);
	
	return 0;
}