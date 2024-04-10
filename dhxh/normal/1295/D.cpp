#include <bits/stdc++.h>

using namespace std;

long long n, m;

int t;

int main(){
	long long i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%lld%lld", &n, &m);
		long long g;
		g = __gcd(n, m);
		long long x = m / g;
		long long y = x;
		vector <long long> vec;
		
		for(i=2;i*i<=y;i++){
			if(x % i) continue;
			vec.push_back(i);
			while(x % i == 0){
				x /= i;
			}
		}
		
		if(x > 1) vec.push_back(x);
		
		long long ans = 0;
		for(i=0;i<(1<<(int)vec.size());i++){
			int cnt = 0;
			long long x = 1;
			for(j=0;j<vec.size();j++){
				if((i >> j) & 1){
					cnt++;
					x *= vec[j];
				}
			}
			
			if(cnt & 1) ans -= y / x;
			else ans += y / x;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}