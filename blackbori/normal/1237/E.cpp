#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353, w = 3;

ll D0[1101010], D1[1101010];
vector <ll> X, Y;

ll pow(ll a, ll b)
{
	ll ret = 1;
	
	for(; b; b>>=1){
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
	}
	
	return ret;
}
 
void dft(vector <ll> &X)
{
	ll n, i, j, k, x, y, z;
	
	n = X.size();
	j = 0;
	
	for(i=1; i<n; i++){
		for(k=n>>1; j>=k; k>>=1) j -= k;
		j += k;
		if(i < j) swap(X[i], X[j]);
	}
	
	for(i=1; i<n; i<<=1){
		x = pow(w, mod / i >> 1);
		for(j=0; j<n; j+=i<<1){
			y = 1;
			for(k=0; k<i; k++){
				z = X[i | j | k] * y % mod;
				X[i | j | k] = (X[j | k] - z + mod) % mod;
				X[j | k] = (X[j | k] + z) % mod;
				y = y * x % mod;
			}
		}
	}
}

void idft(vector <ll> &X)
{
	ll n, i, j, k, x, y, z;
	
	n = X.size();
	j = 0;
	
	for(i=1; i<n; i++){
		for(k=n>>1; j>=k; k>>=1) j -= k;
		j += k;
		if(i < j) swap(X[i], X[j]);
	}
	
	for(i=1; i<n; i<<=1){
		x = pow(w, mod - (mod / i >> 1) - 1);
		for(j=0; j<n; j+=i<<1){
			y = 1;
			for(k=0; k<i; k++){
				z = X[i | j | k] * y % mod;
				X[i | j | k] = (X[j | k] - z + mod) % mod;
				X[j | k] = (X[j | k] + z) % mod;
				y = y * x % mod;
			}
		}
	}
	
	x = pow(n, mod - 2);
	
	for(i=0; i<n; i++){
		X[i] = X[i] * x % mod;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, i, j;
	
	D0[1] = 0; D0[2] = 1; D0[3] = 0; // D0[4] = 1;
	D1[1] = 1; D1[2] = 0; D1[3] = 0; // D1[4] = 0;
	
	for(i=1; i<=18; i++){
		X.clear();
		
		for(j=(1<<i); j<(1<<i+1); j++){
			X.push_back(D0[j]);
		}
		
		for(j=(1<<i); j<(1<<i+1); j++){
			X.push_back(0);
		}
		
		dft(X);
		
		for(j=0; j<(1<<i+1); j++){
			X[j] = X[j] * X[j] % mod;
		}
		
		idft(X);
		
		for(j=0; j<(1<<i+1); j++){
			D1[(1 << i + 1) + j + 1] = (D1[(1 << i + 1) + j + 1] + X[j]) % mod;
			if(j + 2 <= 1 << i){
				D1[(1 << i + 1) + j + 1] = (D1[(1 << i + 1) + j + 1] +
						2 * D0[(1 << i) - 1] * D0[(1 << i) + j + 1]) % mod;
			}
//			printf("%lld %lld\n", (1 << i + 1) + j + 1, (1 << i) + j +D1[(1 << i + 1) + j + 1]);
		}
		
		D1[(1 << i + 1)] = 2 * D0[(1 << i) - 1] * D0[1 << i] % mod;
		
		X.clear(); Y.clear();
		
		for(j=(1<<i); j<(1<<i+1); j++){
			X.push_back(D1[j]);
			Y.push_back(D0[j]);
		}
		
		for(j=(1<<i); j<(1<<i+1); j++){
			X.push_back(0);
			Y.push_back(0);
		}
		
		dft(X); dft(Y);
		
		for(j=0; j<(1<<i+1); j++){
			X[j] = X[j] * Y[j] % mod;
		}
		
		idft(X);
		
		for(j=0; j<(1<<i+1); j++){
			D0[(1 << i + 1) + j + 1] = (D0[(1 << i + 1) + j + 1] + X[j]) % mod;
			if(j + 2 <= 1 << i){
				D0[(1 << i + 1) + j + 1] = (D0[(1 << i + 1) + j + 1] +
						2 * D1[(1 << i) - 1] * D1[(1 << i) + j + 1]) % mod;
			}
//			printf("%lld %lld\n", (1 << i + 1) + j + 1, D0[(1 << i + 1) + j + 1]);
		}
		
		D0[(1 << i + 1)] = (D1[(1 << i) - 1] * D0[1 << i] + D0[(1 << i) - 1] * D1[1 << i]) % mod;
	}
/*	
	for(i=1; i<=100; i++){
		printf("%lld : %lld %lld\n", i, D0[i], D1[i]);
	}
*/	
	cin >> n;
	cout << (D0[n] + D1[n]) % mod << "\n";
	
	return 0;
}