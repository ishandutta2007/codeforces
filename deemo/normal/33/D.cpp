//Accepted!

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const ll MAXN = 1e3 + 10;

ll n, m, q;
pair<ll, ll>	vec[MAXN], sec[MAXN];
ll r[MAXN], par[MAXN], col[MAXN];
ll dd[MAXN][MAXN], ss[MAXN];
vector<ll>	adj[MAXN];

ll dis(ll a, ll b, ll c, ll d){return	(a - c) * (a - c) + (b - d) * (b - d);}	

void dfs(ll v, ll p = -1, ll de = 0){
	ss[v] = de;
	for (ll u:adj[v])	
		if (u != p)	dfs(u, v, de + 1);
}

int main(){
	scanf("%I64d %I64d %I64d", &n, &m, &q);
	for (ll i = 0; i < n; i++)	scanf("%I64d %I64d", &vec[i].F, &vec[i].S);
	for (ll i = 0; i < m; i++)	scanf("%I64d %I64d %I64d", &r[i], &sec[i].F, &sec[i].S);
	memset(par, -1, sizeof(par));
	for (ll i = 0; i < m; i++)	for (ll j = 0; j < m; j++)
		if (r[i] < r[j] && dis(sec[i].F, sec[i].S, sec[j].F, sec[j].S) < (r[i] + r[j]) * (r[i] + r[j]) && (par[i] == -1 || r[par[i]] > r[j]))	par[i] = j;
	for (ll i = 0; i < m; i++){	if (par[i] == -1)	par[i] = m;	adj[par[i]].push_back(i), adj[i].push_back(par[i]);}
	for (ll i = 0; i < n; i++){
		col[i] = -1;
		for (ll j = 0; j < m; j++)
			if (dis(sec[j].F, sec[j].S, vec[i].F, vec[i].S) < r[j] * r[j] && (col[i] == -1 || r[col[i]] > r[j]))	col[i] = j;
		if (col[i] == -1)
			col[i] = m;
	}
	for (ll i = 0; i <= m; i++){
		dfs(i);
		for (ll j = 0; j <= m; j++)	dd[i][j] = ss[j];
	}

	while (q--){ll a, b;	scanf("%I64d %I64d", &a, &b);	a--, b--;	printf("%I64d\n", dd[col[a]][col[b]]);}
	return	0;		
}