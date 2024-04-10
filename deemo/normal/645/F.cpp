//Sometimes love is not enough and the road gets tough I don't know why..

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int MAXVAL = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, k, q, vec[MAXN], cs[2][MAXN], dvs_cnt[MAXVAL], cnt[MAXVAL], ss[MAXVAL];
ll fact[MAXN];
vector<int>	dvs[MAXVAL];

ll pw(ll a, int b){
	ll ret = 1;
	while (b){
		if (b&1) ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;
}

int choose(int a, int b){return (fact[a] * pw((fact[b] * fact[a - b]) % MOD, MOD - 2)) % MOD;}

void init(){
	fact[0] = 1;
	for (int i = 1; i ^ MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
	for (int i = k; i <= n + q; i++) cs[0][i] = choose(i, k);
	for (int i = k - 1; i <= n + q; i++) cs[1][i] = choose(i, k - 1);
	int mx = 0;
	for (int i = 1; i < MAXVAL; i++)
		for (int j = i; j < MAXVAL; j += i)	dvs_cnt[j]++, mx = max(mx, dvs_cnt[j]);
	for (int i = 1; i < MAXVAL; i++)	dvs[i].resize(dvs_cnt[i]), dvs_cnt[i] = 0;
	for (int i = 1; i < MAXVAL; i++)
		for (int j = i; j < MAXVAL; j += i)	dvs[j][dvs_cnt[j]++] = i;
}

int main(){
	scanf("%d %d %d", &n, &k, &q);
	init();
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		for (int u:dvs[vec[i]])	cnt[u]++;
	}
	
	ll ans = 0;
	for (int i = MAXVAL - 1; i; i--){
		ss[i] = cs[0][cnt[i]];
		for (int j = i + i; j < MAXVAL; j += i){
			ss[i] = (ss[i] + MOD - ss[j]);
			while (ss[i] >= MOD)	ss[i] -= MOD;
		}
		ans = (ans + (ll)ss[i] * (ll)i) % MOD;
	}
	memset(ss, 0, sizeof(ss));

	while (q--){
		int x;	scanf("%d", &x);	
		for (int i = dvs[x].size() - 1; i >= 0; i--){
			int d = dvs[x][i];
			int d2 = x/d;
			ss[d] = cs[1][cnt[d]];
			for (int u:dvs[d2])
				if (u - 1){
					ss[d] = (ss[d] + MOD - ss[u*d]);
					while (ss[d] >= MOD)	ss[d] -= MOD;
				}
			ans = (ans + (ll)ss[d] * (ll)d) % MOD;
		}
		for (int &u:dvs[x])	cnt[u]++, ss[u] = 0;
		printf("%I64d\n", ans);
	}
	return	0;
}