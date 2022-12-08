#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 9;
int n, power[maxn], ans , cnt;
int main() {
	scanf("%d", &n); n >>= 1;
	power[0] = 1;
    for (int i = 1; i <= n; ++i) power[i] = 1ll * power[i - 1] * 2 % mod;
    ans = 1; cnt = 2;
    for (int i = 2; i <= n; ++i) {
        ans = 1ll * ans * ((power[i] - 3 + mod) % mod) % mod;
		cnt = (cnt + 4ll * ans % mod) % mod;
    }
	cnt = 1ll * cnt * cnt % mod;
	cnt = (cnt + cnt + 2) % mod;
	printf("%d\n", cnt);
	return 0;
}