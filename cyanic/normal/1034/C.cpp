#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef vector<int> vi;
typedef long long ll;

const int N = 1000005;
const int mod = 1000000007;
int ans[N], c[N], p[N], n;
ll a[N], sum;

ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}
inline void add(int &a, int b) {
	a += b; if (a >= mod) a -= mod;
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%lld", &a[i]);
	rep (i, 2, n) scanf("%d", &p[i]);
	per (i, n, 2) a[p[i]] += a[i];
	sum = a[1];
	rep (i, 1, n) {
		a[i] = gcd(sum, a[i]);
		if (sum / a[i] <= n) c[sum / a[i]] ++;
	}
	per (i, n, 1) for (int j = i + i; j <= n; j += i) c[j] += c[i];
	int res = 0; ans[1] = 1;
	rep (i, 1, n) if (c[i] == i) {
		for (int j = i + i; j <= n; j += i)
			if (c[j] == j) add(ans[j], ans[i]);
		add(res, ans[i]);
	}
	printf("%d\n", res);
	return 0;
}