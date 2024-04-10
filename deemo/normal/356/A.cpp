#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int max_n = 4e5;

int n, q;
int lazy[5 * max_n];

void shift(int v){
	if (lazy[v<<1] == 0)	lazy[v<<1] = lazy[v];
	if (lazy[v<<1^1] == 0)	lazy[v<<1^1] = lazy[v];
}

void modify(int v, int b, int e, int l, int r, int val){
	if (lazy[v] != 0)	return;
	if (l > e || r < b)	return;
	if (l <= b && e <= r){
		lazy[v] = val;
		return;
	}
	int mid = (b + e) / 2;
	shift(v);
	modify(v<<1, b, mid, l, r, val);
	modify(v<<1^1, mid + 1, e, l, r, val);
}

int get(int v, int b, int e, int ind){
	if (ind > e || ind < b)	return -1;
	if (b == e && b == ind)	return lazy[v];
	int mid = (b+e)/2;
	shift(v);
	return	max(get(v<<1, b, mid, ind), get(v<<1^1, mid + 1, e, ind));
}

int main(){
	scanf("%d%d", &n, &q);
	while(q--){
		int l, r, x;	scanf("%d%d%d", &l, &r, &x);	l--, x--, r--;
		if (x != l)	modify(1, 0, n - 1, l, x - 1, x + 1);
		if (x != r)	modify(1, 0, n - 1, x + 1, r, x + 1);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", get(1, 0, n - 1, i));
	printf("\n");
	return 0;
}