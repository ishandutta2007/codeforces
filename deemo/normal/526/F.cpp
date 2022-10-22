#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 3e5 + 10;
const int INF = 1e9;

int n, arr[MAXN];
int nut[4 * MAXN], pmin, pmax;
pair<int, int>	weed[4 * MAXN], sec[MAXN], secMax[MAXN];

void plant(int v, int b, int e){
	weed[v] = {INF, INF};
	if (e - b == 1)	return;

	int mid = b+e>>1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
}

pair<int, int>	merge(pair<int, int> a, pair<int, int> b){
	pair<int, int>	ret = (a.F<b.F?a:b);
	if (a.F == b.F)
		ret.S = a.S + b.S;
	return ret;
}

void absorb(int v){
	if (!nut[v])	return;
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	weed[v<<1].F += nut[v];
	weed[v<<1^1].F += nut[v];
	nut[v] = 0;
}

void modify(int v, int b, int e, int pos, int val){
	if (e - b == 1){
		weed[v] = {val, 1};
		return;	
	}

	int mid = b+e>>1;
	if (pos < mid)
		modify(v<<1, b, mid, pos, val);
	else
		modify(v<<1^1, mid, e, pos, val);
	weed[v] = merge(weed[v<<1], weed[v<<1^1]);
}

void water(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		weed[v].F += val;
		nut[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = b+e>>1;
	absorb(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	weed[v] = merge(weed[v<<1], weed[v<<1^1]);
}

pair<int, int>	smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return {INF, INF};

	int mid = b+e>>1;
	absorb(v);
	return merge(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		arr[b] = a;
	}

	plant(1, 0, n);
	int pmax = 0, pmin = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int v = arr[i], cur = i;
		while (pmin && sec[pmin-1].F > v)
			pmin--, water(1, 0, n, pmin?sec[pmin-1].S:0, cur, sec[pmin].F - v), cur = sec[pmin].S;
		sec[pmin++] = {v, i + 1};

		cur = i;
		while (pmax && secMax[pmax-1].F < v)
			pmax--, water(1, 0, n, pmax?secMax[pmax-1].S:0, cur, v - secMax[pmax].F), cur = secMax[pmax].S;
		secMax[pmax++] = {v, i + 1};
		
		modify(1, 0, n, i, 1);
		
		water(1, 0, n, 0, i + 1, -1);
		if (!weed[1].F)
			ans += weed[1].S;
	}

	printf("%I64d\n", ans);
	return 0;
}