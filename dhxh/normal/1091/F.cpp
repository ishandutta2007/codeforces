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

char a[maxn];

long long l[maxn];

long long g = 0;
bool h = 0;

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

int main(){
	int i, j;
	long long sum = 0;
	long long ans = 0;
	long long delta = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		l[i] = read();
	}
	
	for(i=1;i<=n;i++){
		scanf(" %c", &a[i]);
		if(a[i] == 'L'){
			ans += l[i];
			if(delta >= l[i]){
				delta -= l[i];
			}else{
				if(h){
					ans += 3ll * (l[i] - delta);
					delta = 0;
				}else{
					ans += 5ll * (l[i] - delta);
					delta = 0;
				}
			}
		}else{
			if(a[i] == 'G'){
				ans += 5ll * l[i];
				g += 2ll * l[i];
				delta += l[i];
			}else{
				ans += 3ll * l[i];
				h = true;
				delta += l[i];
			}
		}
		g = min(g, delta);
	}
	
	if(delta >= g){
		ans -= 2ll * g;
		delta -= g;
		ans -= delta;
	}else{
		ans -= 2ll * delta;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}