#include<bits/stdc++.h>
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
using namespace std;
const int N = 35100;
const int KM = 55;
int T[N << 2], tag[N << 2];
int f[N][KM], seq[N], las[N], pre[N];

void Update(int x){
	T[x] = max(T[lc(x)], T[rc(x)]);
	return;
}

void Build(int x, int l, int r, int k){
	tag[x] = 0;
	if(l == r){
		T[x] = f[l][k];
		return;
	}
	int mid = l + r >> 1;
	Build(lc(x), l, mid, k);
	Build(rc(x), mid + 1, r, k);
	Update(x);
	return;
}

void Pushdown(int x){
	if(!tag[x]) return;
	T[lc(x)] += tag[x];
	T[rc(x)] += tag[x];
	tag[lc(x)] += tag[x];
	tag[rc(x)] += tag[x];
	tag[x] = 0;
	return; 
}

void Add(int x, int l, int r, int L, int R, int d){
	if(L <= l && r <= R){
		T[x] += d;
		tag[x] += d;
		return;
	}
	Pushdown(x);
	int mid = l + r >> 1;
	if(L <= mid) Add(lc(x), l, mid, L, R, d);
	if(R > mid) Add(rc(x), mid + 1, r, L, R, d);
	Update(x);
	return;
}

int Query(int x, int l, int r, int L, int R){
	if(L > R) return 0;
	if(L <= l && r <= R) return T[x];
	Pushdown(x);
	int mid = l + r >> 1, res = 0;
	if(L <= mid) res = max(res, Query(lc(x), l, mid, L, R));
	if(R > mid) res = max(res, Query(rc(x), mid + 1, r, L, R));
	Update(x);
	return res; 
}

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i ++){
		scanf("%d", &seq[i]);
		pre[i] = las[seq[i]];
		las[seq[i]] = i;
	}
	
	for(int k = 1; k <= K; k ++){
		Build(1, 0, n - 1, k - 1);
		for(int i = 1; i <= n; i ++){
			Add(1, 0, n - 1, pre[i], i - 1, 1);
			f[i][k] = Query(1, 0, n - 1, 0, i - 1);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = max(ans, f[i][K]);
	printf("%d\n", ans);
	return 0;
}