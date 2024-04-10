#include<cstdio>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

typedef long long ll;

const ll max_n = 1e5 + 100;

ll n, m;
ll ans;
ll c[max_n];
vector<ll>	adj[max_n];
ll vec[max_n], cnt[max_n], comp[max_n];
bool seen[max_n], mark[max_n];

ll get_comp(ll v){
	if (comp[v] == v)	return	v;
	return	comp[v] = get_comp(comp[v]);
}

bool cmp(ll a, ll b){
	return	c[a] > c[b];
}

int main(){
	scanf("%I64d%I64d", &n, &m);
	for (ll i = 0; i < n; i++)
		scanf("%I64d", &c[i]);
	for (ll i = 0; i < m; i++){
		ll a, b;	scanf("%I64d%I64d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	for (ll i = 0; i < n; i++){
		vec[i] = i;
		comp[i] = i;
		cnt[i] = 1;
	}
	sort(vec, vec + n, cmp);

	for (ll i = 0; i < n; i++){
		memset(seen, 0, sizeof(seen));
		ll t = 0, sum = 1;
		ll u = vec[i];
		for (ll j:adj[u]){
			if (!mark[j])	continue;
			if (seen[get_comp(j)])	continue;
			seen[get_comp(j)] = 1;
			t += cnt[get_comp(j)] * sum;
			sum += cnt[get_comp(j)];
		}

		memset(seen, 0, sizeof(seen));
		for (ll j:adj[u]){
			if (!mark[j])	continue;
			if (seen[get_comp(j)])	continue;
			seen[get_comp(j)] = 1;
			ll temp = cnt[get_comp(j)];
			cnt[get_comp(j)] = 0;
			comp[get_comp(j)] = get_comp(u);
			cnt[get_comp(u)] += temp;
		}

		mark[u] = 1;
		ans += t * c[u];
	}	
	cout<<fixed<<setprecision(7);
	ll t = n * (n - 1) / 2;
	long double ret = (double) ans/ t;
	cout << ret << endl;
	return 0;
}