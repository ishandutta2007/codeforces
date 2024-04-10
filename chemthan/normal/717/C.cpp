#include <bits/stdc++.h>

#define pb push_back
#define ld double
#define ll long long
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int nm = 100010;
const ll mod = 10007;

int n;
ll a[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	ll res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + a[i] * a[n + 1 - i]) % mod;
	cout << res << "\n";
}