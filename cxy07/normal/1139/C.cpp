//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;

#define ll long long

ll n,k,ans;
ll cnt[MAXN];
ll f[MAXN];

ll find(ll x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}

void unity(int x,int y) {
	if(find(x) != find(y))
		f[find(x)] = find(y);
}

ll qpow(ll a,ll b) {
    ll res = 1,base = a;
    while(b) {
        if(b & 1) (res *= base) %= mod;
        (base *= base) %= mod;
        b >>= 1;
    }
    return res;
}

int main () {
	cin >> n >> k;
	for(int i = 1;i <= n; ++i)
		f[i] = i; 
	for(int i = 1,x,y,col;i < n; ++i) {
		cin >> x >> y >> col;
		if(col == 0) unity(x,y); 
	}
	for(int i = 1;i <= n; ++i)
		cnt[find(i)]++;
	for(int i = 1;i <= n; ++i)
		if(f[i] == i) (ans += qpow(cnt[i],k)) %= mod;
	cout << (qpow(n,k) + mod - ans) % mod << endl;
	return 0;
}