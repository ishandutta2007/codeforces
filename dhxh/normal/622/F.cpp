#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 5;

const long long mod = 1e9 + 7;

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

struct poly {
	int n;
	long long a[maxn];
	long long f[maxn];
	long long g[maxn];
	
	int insert(long long x){
		a[++n] = x;
		return 0;
	}
	
	int solve(){
		int i, j;
		
		f[1] = 1;
		
		for(i=2;i<=n;i++){
			f[1] = f[1] * (1 - i) % mod;
		}
		f[1] = qpow(f[1], mod - 2);
		
		for(i=2;i<=n;i++){
			f[i] = f[i - 1] * (i - 1 - n) % mod * qpow(i - 1, mod - 2) % mod;
			
		}
		
		return 0;
	}
	
	int query(long long x){
		x++;
		if(x <= n)return a[x];
		int i;
		long long ret = 0;
		long long t = 1;
		for(int i=1;i<=n;i++){
			t = t * (x - i) % mod;
		}
		
		for(int i=1;i<=n;i++){
			ret = (ret + a[i] * t % mod * qpow(x - i, mod - 2) % mod * f[i]) % mod;
		}
		
		return ret;
	}
	
	int init(){
		n = 0;
		return 0;
	}
} a;

int t;
int n, m;

long long f[maxn];
long long sum[maxn];

int main(){
	int i, j;
	long long sum = 0;
	
	cin >> n >> m;
	
	a.init();
	a.insert(sum);
	for(i=1;i<=m+1;i++){
		sum += qpow(i, m);
		if(sum >= mod)sum -= mod;
		a.insert(sum);
	}
	
	a.solve();
	
	cout << a.query(n) << endl;
	
	return 0;
}