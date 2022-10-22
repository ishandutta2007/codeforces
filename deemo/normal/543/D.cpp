#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<deque>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const ll MOD = 1e9 + 7;
const ll max_n = 2e5 + 50;

int n;
int par[max_n], order[max_n];
vector<int>	child[max_n];
vector<ll>	l[max_n];
deque<ll>	r[max_n];
ll d[max_n], up[max_n];

void input(){
	int alaki = scanf("%d", &n);
	for (ll i = 1 ; i < n ;i++){
		alaki = scanf("%d", &par[i]);	
		par[i]--;
		child[par[i]].pb(i);
	}
}

void dfs(int v, int t){
	order[v] = t;
	if (child[v].size() == 0){
		d[v] = 1;
		return;
	}
	d[v] = 1;
	for (ll i = 0 ; i < child[v].size() ; i++){
		dfs(child[v][i], i);
		d[v] = (d[v] * (d[child[v][i]] + 1)) % MOD;
	}
	
	l[v].resize(child[v].size());
	r[v].resize(child[v].size());

	l[v][0] = d[child[v][0]] + 1;
	r[v][child[v].size() - 1] = d[child[v][child[v].size() - 1]] + 1;
	for (int i = 1 ; i < child[v].size() - 1; i++)
		l[v][i] = (l[v][i - 1] * (d[child[v][i]] + 1)) % MOD;
	for (int i = child[v].size() - 2; i >= 0 ; i--)
		r[v][i] = (r[v][i + 1] * (d[child[v][i]] + 1)) % MOD;
}

void cal_up(ll v){
	if (v == 0)	up[v] = 1;
	else{
		up[v] = up[par[v]];
		if (order[v] != 0)	up[v] *= l[par[v]][order[v] - 1];
		up[v] %= MOD;
		if (order[v] != child[par[v]].size() - 1)	up[v] *= r[par[v]][order[v] + 1];
		up[v]++;	
		up[v] %= MOD;
	}
	for (ll i = 0 ; i < child[v].size() ;i++)
		cal_up(child[v][i]);
}

int main(){
	input();
	dfs(0, 0);
	cal_up(0);
	for (ll i = 0 ; i < n ; i++){
		ll ans = d[i] * up[i];
		ans %= MOD;
		printf("%d ", int(ans));
	}
	printf("\n");
	return	0;
}