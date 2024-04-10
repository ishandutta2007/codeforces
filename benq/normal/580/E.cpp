#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
const int MOD = 1000000007;

int n,m,k;
ll lazy[1<<18], sum[1<<18], po10[1<<17], inv9 = 111111112;
string s;

ll inv (ll base) {
	ll po = MOD-2, res=1;
	while (po) {
		if (po&1) res = (res*base) % MOD;
		po /= 2;
		base = (base*base) % MOD;
	}
	return res;
}

void init() { 
	F0R(i,1<<18) lazy[i] = -1;
	po10[0] = 1;
	FOR(i,1,1<<17) po10[i] = (po10[i-1]*10) % MOD;
	cin >> n >> m >> k >> s;
	FOR(i,1,n+1) sum[i+(1<<17)-1] = int(s[i-1]-'0')*po10[i] % MOD;
	for (int i = (1<<17)-1; i > 0; --i) sum[i] = (sum[2*i]+sum[2*i+1]) % MOD;
}

void push(int node, int l, int r) {
	if (lazy[node] != -1) {
		sum[node] = lazy[node]*(po10[r+1]-po10[l]) % MOD;
		sum[node] = sum[node]*inv9 % MOD;
		while (sum[node]<0) sum[node] += MOD;
		if (node<(1<<17)) {
			lazy[2*node] = lazy[node];
			lazy[2*node+1] = lazy[node];
		}
		lazy[node] = -1;
	}
} 

void update(int ind, int L, int R, int low, int high, int inc) {
	push(ind,L,R);
    if (high < L || R < low) return;
    if (low <= L && R <= high) {
    	lazy[ind] = inc;
    	push(ind,L,R);
        return;
    }
    int M = (L+R)/2;
    update(2*ind,L,M,low,high,inc);
    update(2*ind+1,M+1,R,low,high,inc);
    sum[ind] = sum[2*ind]+sum[2*ind+1];
} 

ll query(int ind, int L, int R, int low, int high) {
	push(ind,L,R);
	if (high < L || R < low) return 0;
	if (low <= L && R <= high) return sum[ind];
    int M = (L+R)/2;
    return (query(2*ind,L,M,low,high)+query(2*ind+1,M+1,R,low,high)) % MOD;
}

int main() {
	init();
	F0R(i,m+k) {
		int t,l,r,c;
		cin >> t >> l >> r >> c;
		if (t == 1) update(1,1,1<<17,l,r,c);
		else {
			int d = c;
			ll q1 = (query(1,1,1<<17,l,r-d)*po10[d]) % MOD;
			ll q2 = query(1,1,1<<17,l+d,r);
			if (q1 != q2) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}