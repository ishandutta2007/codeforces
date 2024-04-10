//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE
#define int long long
const int MAXN = 1e18 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int T;
int a,k;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

inline int calc(int x) {
	int maxn = -1,minn = 10;
	while(x) {
		maxn = max(maxn,x % 10);
		minn = min(minn,x % 10);
		x /= 10;
	}
	return maxn * minn;
}

signed main () {
#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	cin >> T;
	while(T--) {
		cin >> a >> k;
		for(register int i = 2;i <= k; ++i) 
			if(calc(a)) a += calc(a);
			else break;
		cout << a << endl;
	}
	return 0;
}