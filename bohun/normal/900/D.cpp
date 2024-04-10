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
	

vector <int> prime;
 
int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	if(s % n) {
		printf("0\n");
		return 0;
	}
	s /= n;
	int N = s;
	for(int i = 2; i * i <= s; ++i) {
		if(s % i == 0) {
			prime.pb(i);
			while(s % i == 0)
				s /= i;
		}
	}
	if(s > 1) 
		prime.pb(s);
	int ans = 0;
	for(int maska = 0; maska < (1 << ss(prime)); ++maska) {
		int ile = 0;
		int x = 1;
		for(int j = 0; j < ss(prime); ++j) {
			if(((maska >> j) & 1)) {
				ile++;
				x *= prime[j];
			}
		}
		int y = pt(2, N / x - 1);
		if(ile % 2)
			ans = (ans - y + mod) % mod;
		else
			ans = (ans + y) % mod;
	}
	printf("%d", ans);
	
	
	
	
	return 0;
}