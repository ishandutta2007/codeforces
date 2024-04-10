//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define inv(x) ksm(x,mod - 2)

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int mod = 998244353;

int n,m;

inline int ksm(int a,int b) {
    if(b < 0) return 0;
	if(a == 1) return 1;
	int res = 1;
	while(b) {
		if(b & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return res;
}

inline int C(int a,int b) {
	int res = 1;
	for(register int i = a;i >= a - b + 1; --i)
		(res *= i) %= mod;
	for(register int i = 1;i <= b; ++i)
		(res *= inv(i)) %= mod;
	return res;
}

signed main () {
	cin >> n >> m;
	cout << ksm(2,n - 3) % mod * C(m,n - 1) % mod * (n - 2) % mod << endl;
	return 0;
}