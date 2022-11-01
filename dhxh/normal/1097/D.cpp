#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long n, k;
long long mod = 1e9 + 7;

const int maxn = 2e5 + 5;
const int maxm = 1e7 + 5;

vector <long long> vec;

vector <int> e[maxn];

long long f[2][maxn];

long long inv[maxn];

long long cnt[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		
		b = b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

int main(){
	int i, j, l;
	long long x = 1, y = 0;
	long long ans = 1;
	long long maxx = 0;
	
	cin >> n >> k;
	
	long long tmp = sqrt(n);
	
	for(i=2;i<=tmp;i++){
		if(n % i == 0){
			vec.push_back(i);
			while(n % i == 0){
				n /= i;
				cnt[vec.size() - 1]++;
			}
		}
	}
	
	if(n > 1){
		vec.push_back(n);
		cnt[vec.size() - 1] = 1;
	}
	
	for(i=1;i<=100;i++){
		inv[i] = qpow(i, mod - 2);
	}
	
	for(i=0;i<vec.size();i++){
		memset(f, 0, sizeof(f));
		f[0][cnt[i]] = 1;
	
		for(l=1;l<=k;l++){
			long long t = 0;
			for(j=0;j<=cnt[i];j++){
				f[(l & 1)][j] = 0;
			}
		
			for(j=cnt[i];j>=0;j--){
				t = (t + f[!(l & 1)][j] * inv[j + 1]) % mod;
				f[l & 1][j] = t;
			}
		}
		
		x = 1;
		y = 0;
		
		for(j=0;j<=cnt[i];j++){
			y = (y + (x * f[k & 1][j]) % mod) % mod;
			x = x * vec[i] % mod;
		}
		
		ans = ans * y % mod;
	}
	
	cout << ans % mod << endl;
	
	return 0;
}