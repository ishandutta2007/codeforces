//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T,p1,p2,k,gcd;

int GCD(int x,int y) {
	if(!y) return x;
	return GCD(y,x % y);
}

signed main () {
	cin >> T;
	while(T--) {
		cin >> p1 >> p2 >> k;
		if(k == 1) {puts("OBEY"); continue;} 
		gcd = GCD(p1,p2);
		p1 /= gcd,p2 /= gcd;
		if(p1 > p2) swap(p1,p2);
		if(ceil((double) (p2 - 1) / p1) >= k) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}