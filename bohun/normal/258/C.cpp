#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

const int mod = 1e9 + 7;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int n;
int a[100001];
vector <int> divi[100001];
int pref[200001];

int sum(int l, int r) {
	if(l > r)
		return 0;
	return pref[r] - pref[l - 1];
}

int ans = 0;

int query(vector <int> &x, int y) {
	int res = 1;
	for(int i = 0; i + 1 < ss(x); ++i) 
		res = 1ll * res * pt(min(y, i + 1), sum(x[i], x[i + 1] - 1)) % mod;
	return res;
}
 
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		pref[a[i]] += 1;
	}
	for(int i = 1; i <= 200000; ++i)
		pref[i] += pref[i - 1];
		
	for(int i = 1; i <= 100000; ++i)
		for(int j = i; j <= 100000; j += i)
			divi[j].pb(i);
	for(int i = 1; i <= 100000; ++i)
		divi[i].pb(111111);
	for(int i = 1; i <= 100000; ++i) {
		ans = (ans + query(divi[i], 100000)) % mod;
		ans = (ans - query(divi[i], ss(divi[i]) - 2) + mod) % mod;
	}
	printf("%d", ans);
	
	
	return 0;
}