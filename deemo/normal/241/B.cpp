#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e4 + 10;
const int MOD = 1e9 + 7;
const int C = 30 + 4;

int n, val[MAXN];
ll m, ans;
int c[C * MAXN], tr[2][C * MAXN], sz, cc[C][C * MAXN];

void add(int y, bool type = 0){
	int cur = 0;
	for (int w = 30; ~w; w--){
		bool z = (y >> w) & 1;
		if (!tr[z][cur])
			tr[z][cur] = ++sz;
		cur = tr[z][cur];
		c[cur]++;

		if (type)
			for (int i = 30; ~i; i--)
				if (y>>i&1)
					cc[i][cur]++;
	}
}

int get(int y, int x){
	int cur = 0, ret = 0;
	for (int w = 30; ~w; w--){
		bool z = y>>w&1;
		bool zz = x>>w&1;
		if (zz){
			cur = tr[!z][cur];
			if (!cur)	return ret;
		}
		else{
			ret += c[tr[!z][cur]];
			cur = tr[z][cur];
			if (!cur)	return ret;
		}
	}
	return ret + c[cur];
}

ll cnt(ll x){
	memset(c, 0, sizeof(c));
	ll ret = 0;
	for (int i = 0; i < n; i++){
		ret += get(val[i], x);
		add(val[i]);
	}
	return ret;
}

void go(int y, int x){
	int cur = 0;
	for (int w = 30; ~w; w--){
		bool z = y>>w&1;
		bool zz = x>>w&1;
		if (zz){
			cur = tr[!z][cur];
			if (!cur)	return;
		}
		else{
			for (int i = 30; ~i; i--)
				if (y>>i&1)
					ans = (ans + 1ll * (c[tr[!z][cur]] - cc[i][tr[!z][cur]]) * (1<<i)) % MOD;
				else
					ans = (ans + 1ll * cc[i][tr[!z][cur]] * (1<<i)) % MOD;

			cur = tr[z][cur];
			if (!cur)
				return;
		}
	}
	ans = (ans + 1ll * c[cur] * x) % MOD;
}

int main(){
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++)	scanf("%d", &val[i]), add(val[i]);
	int b = 0, e = 2e9, ret = 2e9 + 2;
	while (b <= e){
		int mid = ll(b) + e >> 1;
		if (cnt(mid) >= m)
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	ll t = cnt(ret);
	ans = ((m - t) * ret % MOD + MOD) % MOD;

	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++){
		go(val[i], ret);
		add(val[i], 1);
	}

	printf("%lld\n", ans);
	return 0;
}