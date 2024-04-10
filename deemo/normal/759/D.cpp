#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 10;
const int MOD = 1e9 + 7;

int n;
string s, t;
ll ss[MAXN*3], tt[MAXN*3];
int lst[200], d[MAXN][MAXN], tot[MAXN], temp[MAXN];

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = ret * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;	
}

ll choose(ll a, ll b){
	if (min(a, b) < 0 || a < b)	return 0;
	return ss[a] * tt[b] % MOD * tt[a - b] % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ss[0] = 1;
	for (int i = 1; i < MAXN*3; i++)	ss[i] = ss[i - 1] * i % MOD;
	tt[0] = tt[1] = 1;
	for (int i = 2; i < MAXN*3; i++)	tt[i] = tt[i - 1] * pw(i, MOD - 2) % MOD;

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
		if (t.empty() || t.back() != s[i])
			t += s[i];

	memset(lst, -1, sizeof(lst));
	tot[0] = 1;
	for (int i = 0; i < (int)t.size(); i++){
		for (int j = 0; j < MAXN; j++)	temp[j] = ((~lst[t[i]])?d[lst[t[i]]][j]:0);
		for (int j = 1; j <= i+1; j++)
			d[i][j] = ((tot[j - 1] - ((~lst[t[i]])?d[lst[t[i]]][j - 1]:0)) % MOD + MOD) % MOD;

		for (int j = 0; j < MAXN; j++){
			tot[j] -= temp[j];
			while (tot[j] < 0)	tot[j] += MOD;
			tot[j] += d[i][j];
			while (tot[j] >= MOD)	tot[j] -= MOD;
		}

		lst[t[i]] = i;
	}
	
	int ans = 0;
	for (int i = 1; i < MAXN; i++)
		ans = (ans + 1ll * choose(n-1, i-1) * tot[i]) % MOD;
	cout << ans << "\n";
	return 0;
}