#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
 
const int N = 505;
const int mod = 1000000007;
int bin[N], c[N], p, n, ans;
 
int main() {
	scanf("%d", &n);
	bin[0] = 1;
	rep (i, 1, n) {
		scanf("%d", &p);
		if (~p) c[p] ++;
		bin[i] = 2 * bin[i - 1] % mod;
	}
	ans = bin[n-1] - 1;
	rep (i, 1, n)
		ans = (ans + mod - bin[c[i]] + 1) % mod;
	printf("%d\n", (ans + mod) % mod);
	return 0;
}