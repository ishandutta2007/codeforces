//Don't turn away now..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 40;
const ll SQRT = 340;

ll n, m, q;
ll vec[MAXN];
vector<ll>	sec[MAXN];
ll mp[SQRT], sz;
ll sum[MAXN], save[MAXN];
int cnt[SQRT][MAXN];
bool mark[MAXN];

void init(){
	for (ll i = 0; i < sz; i++){
		ll id = mp[i];
		memset(mark, 0, sizeof(mark));
		for (ll j:sec[id])	mark[j] = 1;

		for (ll j = 0; j < m; j++)
			for (ll k:sec[j])
				if (mark[k])	cnt[i][j]++;
	}
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &m, &q);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &vec[i]);
	for (ll i = 0; i < m; i++){
		ll t;	scanf("%I64d", &t);
		bool mk = 0;
		if (t >= SQRT)	mp[sz++] = i, mk = 1;
		sec[i].resize(t);

		while (t--){
			scanf("%I64d", &sec[i][t]),	sec[i][t]--;
			if (mk)	sum[i] += vec[sec[i][t]];
		}
	}
	init();

	while (q--){
		char type;	scanf("%1s", &type);
		if (type == '+'){
			ll id, x;	scanf("%I64d%I64d", &id, &x);	id--;
			if (sec[id].size() >= SQRT)	
				save[id] += x;
			else{
				for (ll j:sec[id])	vec[j] += x;
				for (ll j = 0; j < sz; j++){
					ll c = cnt[j][id];
					sum[mp[j]] += c * (ll)x;
				}
			}
		}
		else{
			ll id;	scanf("%I64d", &id);	id--;
			ll ans = 0;
			for (ll i = 0 ; i < sz; i++)
				ans += (ll)cnt[i][id] * save[mp[i]];
			if (sec[id].size() >= SQRT)
				printf("%I64d\n", sum[id] + ans);
			else{
				for (ll j:sec[id])
					ans += vec[j];
				printf("%I64d\n", ans);
			}
		}
	}
	return 0;
}