#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 4e5 + 10;

int n, k, l[MAXN], r[MAXN], sz;
ll sec[MAXN], ss[MAXN];
vector<int>	vec[MAXN];
multiset<int>	st;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ret;	
}

ll get(int sz){return sz < k?0:ss[sz] * pw(ss[k] * ss[sz - k] % MOD, MOD - 2) % MOD;}

int main(){
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = ss[i - 1] * ll(i) % MOD;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &l[i], &r[i]), l[i]--, sec[sz++] = l[i], sec[sz++] = r[i];
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	for (int i = 0; i < n; i++){
		l[i] = lower_bound(sec, sec + sz, l[i]) - sec;
		r[i] = lower_bound(sec, sec + sz, r[i]) - sec;
		vec[l[i]].push_back(r[i]);
	}

	ll ans = 0;
	for (int i = 0; i + 1 < sz; i++){
		while (st.size() && *st.begin() == i)	st.erase(st.begin());
		for (int tr:vec[i])	st.insert(tr);
		ans = (ans + get(st.size()) * (sec[i + 1] - sec[i]) % MOD) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}