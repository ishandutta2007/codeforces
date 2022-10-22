#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 4e5 + 10;

int n, m, from[MAXN], to[MAXN], par[MAXN], sz;
pair<int, int>	ans[MAXN];
int s, t, ds, dt, cs, ct;
int mark[MAXN];

int get_par(int v){return par[v]==v?v:par[v]=get_par(par[v]);}

int main(){
	scanf("%d %d", &n, &m);
	iota(par, par + n, 0);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &from[i], &to[i]), from[i]--, to[i]--;
	scanf("%d %d %d %d", &s, &t, &ds, &dt), s--, t--;
	for (int i = 0; i < m; i++){
		if (from[i] == s || from[i] == t || to[i] == s || to[i] == t)	continue;
		int pa = get_par(from[i]);
		int pb = get_par(to[i]);
		if (pa == pb)	continue;
		par[pa] = pb;
		ans[sz++] = {from[i] + 1, to[i] + 1};
	}
	for (int i = 0; i < m; i++){
		if (from[i] != s && to[i] != s)	continue;
		if (from[i] != s)	swap(from[i], to[i]);
		int p = get_par(to[i]);
		mark[p] = 1;
	}
	for (int i = 0; i < m; i++){
		if (from[i] != t && to[i] != t)	continue;
		if (from[i] != t)	swap(from[i], to[i]);
		int p = get_par(to[i]);
		mark[p] |= 2;
	}

	mark[s] = mark[t] = 0;
	
	for (int i = 0; i < m; i++){
		if (from[i] != s && to[i] != s)	continue;
		if (from[i] != s)	swap(from[i], to[i]);
		int p = get_par(to[i]);
		if (mark[p] == 1){
			par[p] = s;
			ans[sz++] = {from[i] + 1, to[i] + 1};
			cs++;
		}
	}

	for (int i = 0; i < m; i++){
		if (from[i] != t && to[i] != t)	continue;
		if (from[i] != t)	swap(from[i], to[i]);
		int p = get_par(to[i]);
		if (mark[p] == 2){
			par[p] = t;
			ans[sz++] = {from[i] + 1, to[i] + 1};
			ct++;
		}
	}

	if (ct >= dt || cs >= ds){
		printf("No\n");
		return 0;
	}

	bool fl = 0;
	for (int i = 0; i < n; i++)
		if (mark[i] == 3)	fl = 1;
	int z = -1;
	if (!fl){
		ans[sz++] = {s + 1, t + 1};
		par[s] = t;
		cs++, ct++;
	}
	else{
		for (int i = 0; i < n; i++){
			int p = get_par(par[i]);
			if (mark[p] == 3){
				z = p;
				break;
			}
		}
		ct++, cs++;
	}

	bool done = 0;
	for (int i = 0; i < m; i++){
		if (from[i] != s && to[i] != s)	continue;
		if (from[i] != s)	swap(from[i], to[i]);
		int p = get_par(to[i]);
		if (mark[p] == 3){
			if (z == p && done)	continue;
			if (p == z)	done = 1, cs--;
			if (cs < ds){
				ans[sz++] = {from[i] + 1, to[i] + 1};
				cs++;
				if (p ^ z)
					par[p] = s;
			}
		}
	}

	done = 0;
	for (int i = 0; i < m; i++){
		if (from[i] != t && to[i] != t)	continue;
		if (from[i] != t)	swap(from[i], to[i]);
		int p = get_par(to[i]);
		if (mark[p] == 3){
			if (z == p && done)	continue;
			if (p == z)	done = 1, ct--;
			if (ct < dt){
				ans[sz++] = {from[i] + 1, to[i] + 1};
				ct++;
				if (p ^ z)
					par[p] = t;
			}
		}
	}

	if (sz != n - 1){
		printf("No\n");
		return 0;
	}
	

	printf("Yes\n");
	for (int e = 0; e < n - 1; e++)
		printf("%d %d\n", ans[e].F, ans[e].S);
	return 0;
}