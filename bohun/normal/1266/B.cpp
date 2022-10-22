#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int mod = 1e9 + 7;
const int nax = 2e5 + 111;

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



int main () {
	int n;
	scanf("%d", &n);
	ll a;
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a);
		if(a <= 14) {
			printf("NO\n");
			continue;
		}
		a %= 14;
		if(a > 0 && a <= 6) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}



	return 0;
}