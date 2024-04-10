#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<utility>

using namespace std;

#define Query pair<pair<int, int>, int>
#define A first.first
#define B first.second
#define C second

const int MAXN = 1e6 + 10;

int q, n, sec[MAXN], cc[MAXN], weed[4 * MAXN], tl[MAXN], tr[MAXN];
Query que[MAXN];
map<int, int>	mp, mpt;
pair<int, int>	gec[MAXN];

void water(int v, int b, int e, int x, int val){
	if (e - b == 1){
		weed[v] += val;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val);
	else
		water(v<<1^1, mid, e, x, val);
	weed[v] = weed[v<<1] + weed[v<<1^1];
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)
		return weed[v];
	if (r <= b || e <= l)
		return 0;

	int mid = (b + e)/ 2;
	return smoke(v<<1, b, mid, l, r) + smoke(v<<1^1, mid, e, l, r);
}

int main(){
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
		scanf("%d %d %d", &que[i].A, &que[i].B, &que[i].C), sec[i] = que[i].C;
	sort(sec, sec + q);
	n = unique(sec, sec + q) - sec;
	for (int i = 0; i < n; i++)	mp[sec[i]] = i;
	for (int i = 0; i < q; i++){
		que[i].C = mp[que[i].C];
		gec[i] = {que[i].B, que[i].C};
	}
	sort(gec, gec + q);
	for (int i = 0; i < q; i++)
		mpt[gec[i].first] = cc[gec[i].second]++;
	for (int i = 0; i < q; i++)
		que[i].B = mpt[que[i].B];

	int lst = 0;
	for (int i = 0; i < n; i++)
		tl[i] = lst, tr[i] = lst + cc[i], lst = tr[i];

	for (int i = 0; i < q; i++){
		int type = que[i].A, tm = que[i].B, x = que[i].C;
		if (type == 1)
			water(1, 0, q, tl[x] + tm, 1);
		if (type == 2)
			water(1, 0, q, tl[x] + tm, -1);
		if (type == 3)
			printf("%d\n", smoke(1, 0, q, tl[x], tl[x] + tm + 1));
	}	
	return 0;
}