#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, q, k, que[MAXN];
bool ok[MAXN];
int aa[MAXN], bb[MAXN], cc[MAXN], dd[MAXN];
pair<int, int>	vec[MAXN];
int weed[4 * MAXN];

bool cmp(int u, int v){return cc[u] < cc[v];}

void water(int v, int b, int e, int x, int val){
	if (e - b == 1){
		weed[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val);
	else
		water(v<<1^1, mid, e, x, val);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	1e8;

	int mid = (b + e)/ 2;
	return min(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

void solve(){
	iota(que, que + q, 0);
	sort(que, que + q, cmp);
	
	memset(weed, -1, sizeof(weed));
	int cur = 0, b = 0;
	for (int i = 0; i < n; i++){
		while (cur < k && vec[cur].first == i)
			water(1, 0, m, vec[cur].second, i), cur++;
		
		while (b < q && cc[que[b]] == i + 1)
			ok[que[b]] |= bool(smoke(1, 0, m, bb[que[b]], dd[que[b]]) >= aa[que[b]]), b++;
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++)	scanf("%d %d", &vec[i].first, &vec[i].second), vec[i].first--, vec[i].second--;
	sort(vec, vec + k);
	for (int i = 0; i < q; i++)	scanf("%d %d %d %d", &aa[i], &bb[i], &cc[i], &dd[i]), aa[i]--, bb[i]--;
	solve();
	swap(n, m);
	for (int i = 0; i < k; i++)	swap(vec[i].first, vec[i].second);
	sort(vec, vec + k);
	for (int i = 0; i < q; i++)	swap(aa[i], bb[i]), swap(cc[i], dd[i]);
	solve();

	for (int i = 0; i < q; i++)
		if (ok[i])
			printf("YES\n");
		else
			printf("NO\n");
	return	0;
}