#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int LOG = 23;

int n, weed[LOG][MAXN], lst;
pair<int, int>	vec[MAXN];

void plant(int v = 1, int b = 0, int e = n, int de = 0){
	if (e - b == 1){
		weed[de][b] = vec[b].S;
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid, de + 1);
	plant(v<<1^1, mid, e, de + 1);
	merge(weed[de + 1] + b, weed[de + 1] + mid, weed[de + 1] + mid, weed[de + 1] + e, weed[de] + b);
}

int smoke(int v, int b, int e, int l, int r, int tl, int tr, int de = 0){
	if (l <= b && e <= r)	
		return lower_bound(weed[de] + b, weed[de] + e, tr) - lower_bound(weed[de] + b, weed[de] + e, tl);
	if (r <= b || e <= l)	
		return 0;

	int mid = (b + e)/ 2;
	return smoke(v<<1, b, mid, l, r, tl, tr, de + 1) + smoke(v<<1^1, mid, e, l, r, tl, tr, de + 1);
}

int f(int x){return ((x - 1 + lst) % n) + 1;}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x;	scanf("%d", &x), x--;
		vec[x].F = i;
	}
	for (int i = 0; i < n ;i++){
		int x;	scanf("%d", &x), x--;
		vec[x].S = i;
	}
	sort(vec, vec + n);
	plant();

	int q;	scanf("%d", &q);
	while (q--){
		int a, b, c, d;	scanf("%d %d %d %d", &a, &b, &c, &d);
		int l1 = min(f(a), f(b)), r1 = max(f(a), f(b));	l1--;
		int l2 = min(f(c), f(d)), r2 = max(f(c), f(d)); l2--;
		lst = smoke(1, 0, n, l1, r1, l2, r2);
		printf("%d\n", lst++);
	}
	return 0;
}