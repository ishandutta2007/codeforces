//Oh I shot, shot, shot a hole through every single thing that I loved..

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define tm asdf

const int MAXN = 5e5 + 10;

int n, q;
char type[MAXN];
int aa[MAXN], bb[MAXN];
int par[2][MAXN], sz[2][MAXN], zz[MAXN], mark[MAXN];
ll sm[MAXN], lst[MAXN];
vector<int>	vec[MAXN];

ll get(int v){
	ll ret = sm[v];
	while (par[0][v] ^ v)
		v = par[0][v], ret += sm[v];
	return ret;
}

void uMerge(int u, int v){
	while (par[0][u] ^ u)	u = par[0][u];
	while (par[0][v] ^ v)	v = par[0][v];
	if (u == v)	return;

	if (sz[0][u] < sz[0][v])
		swap(u, v);
	par[0][v] = u;
	sz[0][u] += sz[0][v];
	sm[v] -= sm[u];
}

void mMerge(int u, int v){
	while (par[1][u] ^ u)	u = par[1][u];
	while (par[1][v] ^ v)	v = par[1][v];
	if (u == v)	return;

	if (sz[1][u] < sz[1][v])
		swap(u, v);
	par[1][v] = u;
	sz[1][u] += sz[1][v];
	mark[v] = zz[u];
}

void raid(int v, int tm){
	while (par[1][v] ^ v)	v = par[1][v];
	zz[v] = tm;
}

void add(int v){
	while (par[0][v] ^ v)	v = par[0][v];
	sm[v] += sz[0][v];
}

int sg(int v){
	int ret = zz[v], y = -1;
	while (par[1][v] ^ v){
		y = mark[v];
		v = par[1][v];
		if (y^zz[v])
			ret = max(ret, zz[v]);
	}
	return ret;
}

void go(bool goodToGo){
	for (int i = 0; i < n; i++)
		par[0][i] = par[1][i] = i;
	for (int i = 0; i < n; i++)
		sz[0][i] = sz[1][i] = 1;
	memset(lst, 0, sizeof(lst));
	memset(sm, 0, sizeof(sm));
	memset(mark, -1, sizeof(mark));
	memset(zz, -1, sizeof(zz));
	
	for (int i = 0; i < q; i++){
		if (type[i] == 'U')//merge uni
			uMerge(aa[i] - 1, bb[i] - 1);

		if (type[i] == 'M')//merge mili
			mMerge(aa[i] - 1, bb[i] - 1);

		if (type[i] == 'A')//moving in
			add(aa[i] - 1);

		if (type[i] == 'Z')//raid
			raid(aa[i] - 1, i);

		if (type[i] == 'Q'){
			if (goodToGo)
				printf("%lld\n", get(aa[i] - 1) - lst[aa[i] - 1]);
			else{
				int temp = sg(aa[i] - 1);
				if (~temp)
					vec[temp].push_back(aa[i] - 1);
			}
		}

		for (int u:vec[i])
			lst[u] = get(u);
	}
}

int main(){
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++){
		scanf("%1s %d", &type[i], &aa[i]);
		if (type[i] == 'U' || type[i] == 'M')
			scanf("%d", &bb[i]);
	}
	go(0);
	go(1);
	return 0;
}