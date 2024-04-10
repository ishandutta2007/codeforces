#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, a[MAXN], f[MAXN], tt[MAXN];

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

int choose(int a, int b){
	if (a < b) return 0;
	return 1ll*f[a]*tt[b]%MOD*tt[a-b]%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 1;
	for (int i = 1; i < MAXN; i++)
		f[i] = 1ll*f[i-1]*i%MOD;
	tt[0] = 1;
	for (int i = 1; i < MAXN; i++)
		tt[i] = 1ll*tt[i-1]*pw(i, MOD-2) % MOD;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n && a[i] != a[n-1]; i++){
		int pos = (a + n) - lower_bound(a, a + n, a[i]);
		int ret = f[pos-1];
		int rem = (n - pos);
		ret = 1ll*ret*f[rem]%MOD*choose(n, rem)%MOD*a[i]%MOD;
		ans = (ans + ret) % MOD;
	}
	cout << ans << "\n";
	return 0;
}