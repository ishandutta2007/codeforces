#include <bits/stdc++.h>

using namespace std;

long long n, k;

long long check(long long x){
	long long i, j;
	long long ret = 0;
	
	for(i=0;(x<<i)<=n;i++){
		if((x << i) + (1ll << (i + 1)) - 1 < n){
			ret += (1ll << (i + 1));
		}else{
			ret += n - (x << i) + 1;
			break;
		}
	}
	
	return ret;
}

long long checkb(long long x){
	long long i, j;
	long long ret = 1;
	x *= 2;
	
	for(i=0;(x<<i)<=n;i++){
		if((x << i) + (1ll << (i + 1)) - 1 < n){
			ret += (1ll << (i + 1));
		}else{
			ret += n - (x << i) + 1;
			break;
		}
	}
	
	return ret;
}

int main(){
	int i, j;
	
	cin >> n >> k;
	
	if(n == k){
		cout << 1 << endl;
		return 0;
	}
	
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	
	long long l = 1, r = n / 2;
	
	while(l + 1 < r){
		long long mid = (l + r) / 2;
		if(check(mid * 2) >= k){
			l = mid;
		}else{
			r = mid;
		}
	}
	
	if(check(r * 2) >= k)l = r;
	
	long long ans = l * 2;
	
	l = 0, r = n / 2 - 1;
	
	while(l + 1 < r){
		long long mid = (l + r) / 2;
		if(checkb(mid * 2 + 1) >= k){
			l = mid;
		}else{
			r = mid;
		}
	}
	
	if(checkb(r * 2 + 1) >= k)l = r;
	
	ans = max(ans, l * 2 + 1);
	
	cout << ans << endl;
	
	return 0;
}