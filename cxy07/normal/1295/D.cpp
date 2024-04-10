//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

int T,a,m;

int gcd(int x,int y) {
	if(!y) return x;
	return gcd(y,x % y);
}

inline int Phi(int n) {
	int res = n;
	for(register int i = 2;i * i <= n; ++i) {
		if(n % i == 0) {
			res -= res / i;
			while(n % i == 0) n /= i; 
		}
	}
	if(n > 1) res -= res / n;
	return res;
}

signed main () {
	cin >> T;
	while(T--) {
		cin >> a >> m;
		cout << Phi(m / gcd(a,m)) << endl;
	}
	return 0;
}