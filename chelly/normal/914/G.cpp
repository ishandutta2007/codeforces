#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 1 << 17;
const int LOG = 17;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int inv2 = inf / 2 + 1;
int a[N], b[N], s[N], t[N], f[N];
int main() {
	int n;
	n = getInt();
	for(int i(1); i <= n; i++) {
		int x = getInt();
		a[x]++;
	}
	for(int i(0); i < (1 << LOG); i++) {
		for(int j(i); j; j = (j - 1) & i)
			b[i] = (b[i] + (LL)a[j] * a[i - j]) % mod;
		b[i] = (b[i] + (LL)a[0] * a[i]) % mod;
		
		//printf("b[%d] = %d\n", i, b[i]);
	}
	memcpy(s, a, sizeof(a));
	for(int i(0); i < LOG; i++)
		for(int j(0); j < (1 << LOG); j++)
			if(j & (1 << i)) {
				s[j - (1 << i)] += s[j];
				s[j] = s[j - (1 << i)] - 2 * s[j];
			}
	for(int i(0); i < (1 << LOG); i++)
		s[i] = (s[i] * (LL)s[i]) % mod;
	for(int i(0); i < LOG; i++)
		for(int j(0); j < (1 << LOG); j++)
			if((j & (1 << i))) { 
				s[j - (1 << i)] = (s[j - (1 << i)] + s[j]) * (LL)inv2 % mod;
				s[j] = (s[j - (1 << i)] - s[j] + mod) % mod;
			}
	for(int i(0); i < (1 << LOG); i++) {
		//printf("s[%d] = %d\n", i, s[i]);
		//s[i] = (s[i] - t[i] + mod) % mod;
	}
	f[0] = 0;
	f[1] = 1;
	for(int i(2); i < (1 << LOG); i++) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	}
	for(int i(0); i < (1 << LOG); i++) {
		a[i] = (LL)a[i] * f[i] % mod;
		b[i] = (LL)b[i] * f[i] % mod;
		s[i] = (LL)s[i] * f[i] % mod;
		
	}

	for(int i(0); i < LOG; i++)
		for(int j(0); j < (1 << LOG); j++)
			if(!(j & (1 << i))) 
				if((a[j] += a[j + (1 << i)]) >= mod)
					a[j] -= mod;
	
	for(int i(0); i < LOG; i++)
		for(int j(0); j < (1 << LOG); j++)
			if(!(j & (1 << i))) 
				if((b[j] += b[j + (1 << i)]) >= mod)
					b[j] -= mod;
	
	for(int i(0); i < LOG; i++)
		for(int j(0); j < (1 << LOG); j++)
			if(!(j & (1 << i))) 
				if((s[j] += s[j + (1 << i)]) >= mod)
					s[j] -= mod;
	for(int i(0); i < (1 << LOG); i++)
		a[i] = ((LL)a[i] * b[i] % mod * s[i]) % mod;
	for(int i(0); i < LOG; i++)
		for(int j(0); j < (1 << LOG); j++)
			if(!(j & (1 << i))) 
				if((a[j] -= a[j + (1 << i)]) < 0)
					a[j] += mod;
	int ans = 0;
	for(int i(0); i < LOG; i++)
		ans = (ans + a[1 << i]) % mod;
	cout << ans << endl;
}