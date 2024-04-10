#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

const int N = 2e6 + 10;
const int MOD = 1e9 + 7;

int T, n;
ll res[N];
ll leafs[N];
ll specials[N];

int main() {
	res[1] = 0;
	leafs[1] = 1;
	specials[1] = 0;
	
	rep(i, 2, N - 1) {
		leafs[i] = (leafs[i - 1] + specials[i - 1] * 2) % MOD;
		specials[i] = leafs[i - 1];
		res[i] = ((i - 3 >= 0 ? res[i - 3] : 0) + leafs[i - 2]) % MOD;
	}
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		printf ("%lld\n", 4 * res[n] % MOD);
	}
	
	return 0;
}