#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Line;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int n, a[MAXN], b[MAXN];
Line lines[MAXN];
int sec[MAXN];
ll opt[MAXN];

ll meet(Line l1, Line l2){
	return ((l2.S - l1.S) + (l1.F - l2.F - 1))/ (l1.F - l2.F);
}

ll getVal(Line l, ll x){
	return l.F*x + l.S;
}

int h, t;
ll getBestY(ll x){
	int lo = h, hi = t;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (opt[sec[mid]] <= x)
			lo = mid;
		else
			hi = mid;
	}
	return getVal(lines[sec[lo]], x);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)	scanf("%d", &b[i]);

	h = t = 0;
	opt[0] = -INF;
	lines[0] = {b[0], 0};
	sec[t++] = 0;
	for (int i = 1; i < n; i++){
		lines[i].F = b[i];
		lines[i].S = getBestY(a[i]);
		while (t-h>1 && meet(lines[sec[t - 2]], lines[i]) 
				< meet(lines[sec[t - 2]], lines[sec[t - 1]]))	t--;
		opt[i] = meet(lines[sec[t-1]], lines[i]);
		sec[t++] = i;
	}
	printf("%lld\n", lines[n - 1].S);
	return 0;
}