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

int n, m;
int t[505][505];

int main () {
	scanf("%d %d", &n, &m);
	if(n == 1 && m == 1) {
		printf("0\n");
		return 0;
	}
	if(n == 1) {
		for(int j = 1; j <= m; ++j)
			printf("%d ", j + 1);
		return 0;
	}
	if(m == 1) {
		for(int j = 1; j <= n; ++j)
			printf("%d\n", j + 1);
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			printf("%d ", i * (n + j));
		printf("\n");
	}



	return 0;
}