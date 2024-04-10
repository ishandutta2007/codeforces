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

int pt(int a, int b) {int c = 1; while(b) {if(b & 1) c = (ll) c * a % mod; a = (ll) a * a % mod; b /= 2;} return c;};

int n;
int a[300001];
int cnt[300001];
int ile[300001];

int fac[300001];
int odw[300001];

int ans[300001];

int newton(int N, int K) {
	if(N < K)
		return 0;
	int res = fac[N];
	res = (ll) res * odw[K] % mod;
	res = (ll) res * odw[N - K] % mod;
	return res;
}

bool ok(int len) {
	for(int i = 1; i <= 300000; ++i)	
		ans[i] = 0;
	for(int i = 300000; 1 <= i; --i) {
		ans[i] = newton(cnt[i], len);
		for(int j = 2 * i; j <= 300000; j += i)
			ans[i] = (ans[i] - ans[j] + mod) % mod;
	}
	return ans[1] > 0;
}

int main() {
	fac[0] = odw[0] = 1;
	for(int i = 1; i <= 300000; ++i) {
		fac[i] = (ll) fac[i - 1] * i % mod;
		odw[i] = pt(fac[i], mod - 2);
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		ile[a[i]] += 1;
	}
	
	for(int i = 1; i <= 300000; ++i)
		for(int j = i; j <= 300000; j += i)
			cnt[i] += ile[j];
	
	int left = 1;
	int right = n + 1;
	while(left < right) {
		int mid = (left + right) / 2;
		if(ok(mid))
			right = mid;
		else
			left = mid + 1;
	}
	if(left == n + 1)
		printf("-1");
	else
		printf("%d", left);
	
	return 0;
}