#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MOD = 1e4 + 7;

int n;
ll a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + a[i] * a[n - i - 1]) % MOD;
	printf("%lld\n", ans);
	return 0;
}