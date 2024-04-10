#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N;
ll F[202020];
ll I[202020];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

ll ncr(int n, int r) {
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	bool black = false, white = false;
	scanf("%d", &N);

	F[0] = 1;
	for(int i = 1; i <= N + N; i++) F[i] = F[i - 1] * i % MOD;
	I[N + N] = inv(F[N + N]);
	for(int i = N + N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int sum = 0, cnt = 0;
	ll no = 1;
	for(int i = 1; i <= N; i++) {
		string str; cin >> str;
		if(str[1] == 'B') str[1] = 'W';
		else if(str[1] == 'W') str[1] = 'B';
		if(str[0] == 'B' || str[1] == 'B') black = true;
		if(str[0] == 'W' || str[1] == 'W') white = true;

		if(str[0] == '?') cnt++;
		else if(str[0] == 'W') sum--;
		else sum++;

		if(str[1] == '?') cnt++;
		else if(str[1] == 'W') sum++;
		else sum--;

		if(str == "WB" || str == "BW") no = 0;
		if(str == "??") no = no * 2 % MOD;
	}

	ll ans = 0;
	sum = abs(sum);
	if(cnt % 2 == sum % 2 && sum <= cnt) ans = ncr(cnt, (cnt + sum) / 2);
	printf("%lld\n", (ans + MOD - no + !white + !black) % MOD);

	return 0;
}