#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int N = 1e5;

int prime[maxn];
bool isnp[maxn];
int pc = 0;
int u[maxn];
vector <int> dv[maxn];
long long p[maxn];
long long f[maxn];

long long n;

int init(){
	int i, j;
	
	u[1] = 1;
	isnp[1] = true;
	
	for(i=1;i<=N;i++)dv[i].push_back(1);
	
	for(i=2;i<=N;i++){
		if(!isnp[i]){
			prime[++pc] = i;
			u[i] = -1;
		}
		
		for(j=1;j<=pc and 1ll*i*prime[j]<=N;j++){
			if(i % prime[j] == 0){
				isnp[i * prime[j]] = true;
				u[i * prime[j]] = 0;
				break;
			}else{
				isnp[i * prime[j]] = true;
				u[i * prime[j]] = -u[i];
			}
		}
		
		for(j=i;j<=N;j+=i){
			dv[j].push_back(i);
		}
	}
	
	return 0;
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

long long calc(int x, int m){
	long long ret = 0;
	for(int i : dv[x]){
		ret += u[i] * m / i;
	}
	return ret;
}

int main(){
	int i, j;
	long long invn;
	
	init();
	
	cin >> n;
	
	invn = qpow(n, mod - 2);
	
	for(i=1;i<=n;i++){
		p[i] = f[i] = invn;
	}
	
	for(i=n;i>1;i--){
		long long c = calc(i / i, n / i);
		long long ps = c * invn % mod;
		long long s = qpow(ps - 1, mod - 2);
		s = s * s % mod;
		
		for(auto j : dv[i]){
			if(i == j)continue;
			long long cc = calc(i / j, n / j);
			long long pp = cc * invn % mod;
			p[j] = (p[j] + p[i] * cc % mod * qpow(n - c, mod - 2)) % mod;
			f[j] = (f[j] + f[i] * cc % mod * qpow(n - c, mod - 2) % mod + p[i] * pp % mod * s) % mod;
		}
		
	}
	
	cout << f[1] << endl;
	
	return 0;
}