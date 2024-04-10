//Bright lights, big city
//She dreams of Love
//Bright lights, big city
//He lives to run..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define Person pair<pair<int, int>, int>
#define age first.first
#define res first.second
#define id second
#define Query pair<pair<int, int>, int>
#define A first.first
#define B first.second

const int max_n = 1e5 + 30;

int n, k, q;
Person bc[max_n], p[max_n], sec[max_n];
Query que[max_n];
int vec[max_n], pos[max_n];
int sum[4 * max_n], maxi[4 * max_n];
int ans[max_n], save[max_n];

bool cmp_age(Person a, Person b){return	a.age < b.age;}
bool cmp_res(Person a, Person b){return	a.res < b.res;}
bool cmp_query(Query a, Query b){return	bc[a.B].res > bc[b.B].res;}

void modify(int v, int b, int e, int x, int val){
	if (e - b == 1){
		sum[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)	modify(v<<1, b, mid, x, val);
	else	modify(v<<1^1, mid, e, x, val);
	sum[v] = sum[v<<1] + sum[v<<1^1];
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	sum[v];
	if (r <= b || e <= l)	return	0;

	int mid = (b + e)/ 2;
	return	get(v<<1, b, mid, l, r) + get(v<<1^1, mid, e, l, r);
}

void init(){
	sort(p, p + n, cmp_age);
	for (int i = 0; i < n; i++)		pos[p[i].id] = i;
	for (int i = 0; i < n; i++)		vec[i] = p[i].age;
	copy(p, p + n, sec);
	sort(sec, sec + n, cmp_res);

	for (int i = 0; i < n; i++){
		modify(1, 0, n, pos[sec[i].id], 1);
		int hi = upper_bound(vec, vec + n, sec[i].age + k) - vec;
		int lo = lower_bound(vec, vec + n, sec[i].age - k) - vec;
		save[sec[i].id] = get(1, 0, n, lo, hi);
	}
}

void modify2(int v, int b, int e, int x, int val){
	if (e - b == 1){
		maxi[v] = val;
		return;
	}

	int mid = (b + e)/ 2;
	if (x < mid)	modify2(v<<1, b, mid, x, val);
	else	modify2(v<<1^1, mid, e, x, val);
	maxi[v] = max(maxi[v<<1], maxi[v<<1^1]);
}

int get2(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	maxi[v];
	if (r <= b || e <= l)	return	-1;

	int mid = (b + e)/ 2;
	return	max(get2(v<<1, b, mid, l, r), get2(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &p[i].res);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i].age), p[i].id = i;
	copy(p, p + n, bc);
	init();

	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		if (bc[a].res > bc[b].res)	swap(a, b);
		que[i] = {{a, b}, i};
	}
	sort(que, que + q, cmp_query);
	sort(p, p + n, cmp_res);
	reverse(p, p + n);

	int b = 0;
	for (int i = 0; i < q; i++){
		int u = que[i].A, v = que[i].B;
		while (b < n && p[b].res >= bc[v].res){		
			modify2(1, 0, n, pos[p[b].id], save[p[b].id]);
			b++;
		}

		if (bc[u].age > bc[v].age)	swap(u, v);
		int hi = upper_bound(vec, vec + n, bc[u].age + k) - vec;
		int lo = lower_bound(vec, vec + n, bc[v].age - k) - vec;
		if (lo >= hi){
			ans[que[i].id] = -1;
			continue;
		}
		ans[que[i].id] = get2(1, 0, n, lo, hi);
	}
	
	for (int i = 0; i < q; i++){
		if (ans[i] == 0)	ans[i] = -1;
		printf("%d\n", ans[i]);
	}
	return 0;
}