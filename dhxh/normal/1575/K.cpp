#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<numeric>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define frist first
#define bulid build
typedef long long ll;
const ll mod = 1e9 + 7;
using namespace std;
ll n,m,k,r,c;
ll ax,ay,bx,by;
ll ans;
ll qpow(ll a,ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int main() {
	cin >> n >> m >> k >> r >> c;
	cin >> ax >> ay >> bx >> by;
	if(ax == bx && ay == by) {
		ans = qpow(k,n * m);
	}
	else {
		ans = qpow(k,n * m - r * c);
	}
	cout << ans << endl;
	return 0;
}
/*
*/