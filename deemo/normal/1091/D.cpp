#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int MOD = 998244353;

int n, ss[MAXN], tt[MAXN];

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
	return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++) ss[i] = 1ll*ss[i-1]*i%MOD;
	tt[0] = 1;
	for (int i = 1; i < MAXN; i++) tt[i] = 1ll*tt[i-1]*pw(i, MOD-2)%MOD;
	cin >> n;

	int ans = ss[n];
	for (int ln = 1; ln < n; ln++){
		int res = 1ll*choose(n, ln)*ss[n-ln]%MOD;
		res = 1ll*res*(ss[ln]==0? MOD-1: ss[ln]-1)%MOD;

		ans = (ans + res) % MOD;
	}
	cout << ans << "\n";
	return 0;
}