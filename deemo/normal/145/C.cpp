#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, k, val[MAXN], sec[MAXN], sz, cnt, tt;
ll ss[MAXN], vec[MAXN], d[MAXN];

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return ret;
}

bool lucky(int x){
	while (x){
		if (x % 10 != 4 && x % 10 != 7)	return false;
		x /= 10;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> val[i];
		if (lucky(val[i]))	sec[sz++] = val[i];
		else	cnt++;
	}

	sort(sec, sec + sz);
	for (int i = 0; i < sz;){
		int j = i;
		while (j < sz && sec[j] == sec[i])	j++;
		vec[tt++] = j - i;
		i = j;
	}

	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = ss[i - 1] * ll(i) % MOD;
	
	d[0] = 1;
	for (int i = 0; i < tt; i++)
		for (int j = i + 1; j; j--)
			d[j] = (d[j] + d[j - 1] * vec[i]) % MOD;
	
	ll ans = 0;
	for (int i = 0; i <= min(k, tt); i++)
		if (k - i <= cnt)
			ans = (ans + d[i] * (ss[cnt] * pw(ss[k - i] * ss[cnt - (k - i)] % MOD, MOD - 2) % MOD)) % MOD;
	cout << ans << "\n";
	return 0;
}