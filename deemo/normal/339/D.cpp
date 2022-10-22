#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 2e5 + 10;

int n, q;
int a[max_n];
bool mark[4 * max_n];
int seg[4 * max_n];

void build(int v, int b, int e){
	if (e - b == 1){
		mark[v] = 0;
		seg[v] = a[b];
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	mark[v] = !mark[v<<1];
	if (mark[v])
		seg[v] = seg[v<<1] | seg[v<<1^1];
	else
		seg[v] = seg[v<<1] ^ seg[v<<1^1];
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
	if (mark[v])
		seg[v] = seg[v<<1] | seg[v<<1^1];
	else
		seg[v] = seg[v<<1] ^ seg[v<<1^1];
}

int main(){
	scanf("%d%d", &n, &q);
	n = (1 << n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build(1, 0, n);

	while (q--){
		int v, x;	scanf("%d%d", &v, &x);	v--;
		modify(1, 0, n, v, x);
		printf("%d\n", seg[1]);
	}
	return 0;
}