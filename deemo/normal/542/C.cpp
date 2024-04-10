#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 200 + 4;

ll n, f[MAXN];
ll d[MAXN], sz[MAXN], col[MAXN], g, depth[MAXN];

ll dfs(ll v, ll p = -1, ll de = 0){
	col[v] = 1;
	ll u = f[v];
	depth[v] = de;
	ll ret = 200;
	if (col[u] == 0){
		ret = dfs(u, v, de + 1);
		d[v] = -ret;
	}
	else{
		if (col[u] == 1)
			sz[g] = de - depth[u] + 1, ret = sz[g] - 1;
		else
			d[v] = max(0LL, d[u]) + 1, ret = -d[v]; 
	}
	col[v] = 2;
	return	--ret;
}

int main(){
	cin >> n;	
	for (ll i = 1; i <= n; i++)	cin >> f[i];
	for (ll i = 1; i <= n; i++)
		if (col[i] == 0)	g++, dfs(i);

	ll ans = 1;
	for (ll i = 0; i <= g; i++)
		if (sz[i])
			ans = ans / __gcd(ans, ll(sz[i])) * sz[i];

	ll tans = ans;
	for (ll i = 1; i <= n; i++)
		while (ans < d[i])	ans += tans;
	cout << ans << endl;
	return	0;
}