#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define Query pair<pair<int, int>, int>

const int MAXN = 1e6 + 10;

int n, q, x[MAXN], ans[MAXN], p[MAXN], fen[MAXN];
Query que[MAXN];
map<int, int> mp;

bool cmp(Query q1, Query q2){
	return q1.F.S < q2.F.S;
}

int get(int l, int r){
	int ret = 0;
	int tr = r, tl = l;
	for (; l; l-=l&-l)
		ret ^= fen[l];
	for (; r; r-=r&-r)
		ret ^= fen[r];
	return ret ^ p[tr] ^ p[tl];
}

void add(int i){
	if (mp.count(x[i])){
		int z = mp[x[i]];
		for (z++; z < MAXN; z += z & -z)
			fen[z] ^= x[i];
	}
	mp[x[i]] = i;
	int val = x[i];
	for (i++; i < MAXN; i +=i&-i)
		fen[i] ^= val;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &x[i]), p[i + 1] = p[i]^x[i];
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
		scanf("%d %d", &que[i].F.F, &que[i].F.S), que[i].F.F--, que[i].S = i;
	sort(que, que + q, cmp);
	int cur = 0;
	for (int i = 0; i < n; i++){
		add(i);
		while (cur < q && i + 1 == que[cur].F.S)
			ans[que[cur].S] = get(que[cur].F.F, i + 1), cur++;
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	return 0;
}