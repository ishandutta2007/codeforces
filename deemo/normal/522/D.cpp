#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

#define Query pair<pair<int, int>, int>
#define left first.first
#define right first.second
#define id second

const int MAX = 5e5 + 30;
const int INF = 1e9 + 4;

int n, q, a[MAX];
map<int, int>	mp;
int ans[MAX];
int seg[4 * MAX];
Query vec[MAX];

void build(int v, int b, int e){
	seg[v] = INF;
	if (e - b == 1)	return;
	
	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
}

void modify(int v, int b, int e, int x, int val){
	if (e - b == 1){
		seg[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)
		modify(v<<1, b, mid, x, val);
	else
		modify(v<<1^1, mid, e, x, val);
	seg[v] = min(seg[v<<1], seg[v<<1^1]);
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	seg[v];
	if (r <= b || e <= l)	return	INF;

	int mid = (b + e)/ 2;
	return	min(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

bool cmp(Query a, Query b){return	a.right < b.right;}

int main(){
	scanf("%d%d", &n, &q);	
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < q; i++){
		scanf("%d%d", &vec[i].left, &vec[i].right);	vec[i].left--;
		vec[i].id = i;
	}
	sort(vec, vec + q, cmp);
	build(1, 0, n);
	
	int b = 0;
	for (int i = 0; i < n; i++){
		if (mp.count(a[i]))
			modify(1, 0, n, mp[a[i]], i - mp[a[i]]);
		mp[a[i]] = i;

		while (b < q && i + 1 >= vec[b].right){
			ans[vec[b].id] = get(1, 0, n, vec[b].left, vec[b].right);
			b++;
		}
	}

	for (int i = 0; i < q; i++){
		if (ans[i] == INF)	ans[i] = -1;
		printf("%d\n", ans[i]);
	}
	return 0;
}