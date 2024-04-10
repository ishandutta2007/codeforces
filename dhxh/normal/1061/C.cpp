#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long mod = 1e9 + 7;

const int maxn = 1e6 + 5;

int n, m, t;

long long f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x;
	long long ans = 0;
	
	n = read();
	
	f[0] = 1;
	
	for(i=1;i<=n;i++){
		x = read();
		t = max(t, x);
		vector <int> a;
		vector <int> b;
		for(j=1;j*j<=x;j++){
			if(x % j == 0){
				a.push_back(j);
				if(j * j != x){
					b.push_back(x / j);
				}
			}
		}
		
		for(j=0;j<b.size();j++){
			f[b[j]] = (f[b[j]] + f[b[j] - 1]) % mod;
		}
		
		for(j=a.size()-1;j>=0;j--){
			f[a[j]] = (f[a[j]] + f[a[j] - 1]) % mod;
		}
	}
	
	for(i=1;i<=t;i++){
		ans = (ans + f[i]) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}