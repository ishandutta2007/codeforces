#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 10;
const ll INF = 1e16 + 2;

ll n, x, y, vec[MAXN], sec[MAXN], t;
ll cost[MAXN], mn[MAXN];

void ff(ll x){
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0){
			sec[t++] = i;
			while (x % i == 0)	x /= i;
		}	
	if (x > 1)	sec[t++] = x;
}

ll get(ll xx){
	memset(cost, 0, sizeof(cost));
	memset(mn, 0, sizeof(mn));

	for (ll i = 0; i < n; i++){
		if (i)	cost[i] = cost[i - 1];
		if (cost[i] >= INF){
			mn[i] = mn[i - 1];
			continue;
		}

		ll z = vec[i] % xx;
		if (z != 0){
			if (z == 1)	cost[i] += y;
			else if (z == xx - 1)	cost[i] += y;
			else	cost[i] = INF;
		}
	
		if (i == 0)
			mn[i] = cost[i] + x * (n - i - 1);
		else
			mn[i] = min(mn[i - 1], cost[i] + x * (n - i - 1));
	}
	
	ll ret = mn[n - 1], co = 0;
	for (ll i = n - 1; i; i--){
		ll z = vec[i] % xx;
		if (z){
			if (z == 1)	co += y;
			else if (z == xx - 1)	co += y;
			else co = INF;
		}

		ret = min(ret, co + mn[i - 1] - x * (n - i));
		ret = min(ret, co + x * i);
		if (co >= INF)	break;
	}
	return	ret;
}

int main(){
	scanf("%I64d %I64d %I64d", &n, &x, &y);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &vec[i]);
	ff(vec[0]);
	ff(vec[0] + 1);
	if (vec[0] != 2)	ff(vec[0] - 1);
	if (n > 1){
		ff(vec[n - 1]);
		ff(vec[n - 1] + 1);
		if (vec[n - 1] != 2)	ff(vec[n - 1] - 1);
	}	
	sort(sec, sec + t);
	t = unique(sec, sec + t) - sec;

	ll ans = INF;
	for (ll i = 0; i < t; i++){
		ans = min(ans, get(sec[i]));
		reverse(vec, vec + n);
		ans = min(ans, get(sec[i]));
		reverse(vec, vec + n);
	}	
	printf("%I64d\n", ans);
	return	0;
}