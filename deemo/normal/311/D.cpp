//Let tomorrow have its way, with the promises betrayed..

#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 10;
const int MOD = 95542721;
const int C = 48;

int n, q;
int a[max_n];
ll seg[4 * max_n][C + 2];
int lazy[4 * max_n];

void build(int v, int b, int e){
	if (e - b == 1){
		seg[v][0] = a[b];
		for (int i = 1; i < C; i++){
			ll temp = (seg[v][i - 1] * seg[v][i - 1]) % MOD;
			temp = (temp * seg[v][i - 1]) % MOD;
			seg[v][i] = temp;
		}
		return;
	}

	int mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	for (int i = 0; i < C; i++)
		seg[v][i] = (seg[v<<1][i] + seg[v<<1^1][i]) % MOD;
}

void shift(int v){
	if (lazy[v] == 0)	return;
	lazy[v<<1] = (lazy[v<<1] + lazy[v]) % C;
	lazy[v<<1^1] = (lazy[v<<1^1] + lazy[v]) % C;
	rotate(seg[v<<1], seg[v<<1] + lazy[v], seg[v<<1] + C);
	rotate(seg[v<<1^1], seg[v<<1^1] + lazy[v], seg[v<<1^1] + C);
	lazy[v] = 0;
}

void modify(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		lazy[v] = (lazy[v] + 1) % C;
		rotate(seg[v], seg[v] + 1, seg[v] + C);
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	shift(v);
	modify(v<<1, b, mid, l, r);
	modify(v<<1^1, mid, e, l, r);
	for (int i = 0; i < C; i++)
		seg[v][i] = (seg[v<<1][i] + seg[v<<1^1][i]) % MOD;
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	
		return	seg[v][0];
	if (r <= b || e <= l)
		return	0;

	int mid = (b + e)/ 2;
	shift(v);
	return	(get(v<<1, b , mid, l, r) + get(v<<1^1, mid, e, l, r)) % MOD;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build(1, 0, n);
	
	scanf("%d", &q);
	while (q--){
		int type;	scanf("%d", &type);
		if (type == 1){
			int l, r;	scanf("%d%d", &l, &r);	l--;
			printf("%d\n", get(1, 0, n, l, r));
		}
		else{
			int l, r;	scanf("%d%d", &l, &r);	l--;
			modify(1, 0, n, l, r);
		}	
	}
	return 0;
}