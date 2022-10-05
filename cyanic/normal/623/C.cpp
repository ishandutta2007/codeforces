/*
n(xi,yi)
(xi,0)(0,yi)


*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> point;

const LL maxn = 100009;
LL pre[maxn], suf[maxn], prelow[maxn], prehigh[maxn], suflow[maxn], sufhigh[maxn];
LL n, Xmin = 1e18, Xmax = -1e18, Ymin = 1e18, Ymax = -1e18;
point a[maxn]; LL l, r = 1e18, mid;

inline LL sqr(LL t){ return 1LL*t*t; }

bool check(LL k){
	LL l = 0, r = 1; 
	while (++l <= n){
		while (r+1 <= n && abs(a[r+1].x) <= abs(a[l].x) && sqr(a[r+1].x - a[l].x) <= k) r++; 
		while (abs(a[r].x) > abs(a[l].x)) r--;
		if (sqr(a[l].x) + sqr(max(pre[l-1], suf[r+1])) > k) continue;
		if (sqr(max(prehigh[l-1], sufhigh[r+1]) - min(prelow[l-1], suflow[r+1])) > k) continue;
		return true;
	}
	l = n; r = n+1;
	while (--r >= 1){
		while (1 <= l-1 && abs(a[l-1].x) <= abs(a[r].x) && sqr(a[r].x - a[l-1].x) <= k) l--; 
		while (abs(a[l].x) > abs(a[r].x)) l++;
		if (sqr(a[r].x) + sqr(max(pre[l-1], suf[r+1])) > k) continue;
		if (sqr(max(prehigh[l-1], sufhigh[r+1]) - min(prelow[l-1], suflow[r+1])) > k) continue;
		return true;
	}
	return false;
}

int main(){
	scanf("%I64d", &n);
	for (LL i=1; i<=n; i++){
		scanf("%I64d%I64d", &a[i].x, &a[i].y);
		Xmin = min(Xmin, a[i].x); Xmax = max(Xmax, a[i].x);
		Ymin = min(Ymin, a[i].y); Ymax = max(Ymax, a[i].y);
	}
	sort(a+1, a+n+1);
	
	prelow[0] = 1e18; prehigh[0] = -1e18;
	for (LL i=1; i<=n; i++){
		pre[i] = max(pre[i-1], abs(a[i].y));
		prelow[i] = min(prelow[i-1], a[i].y);
		prehigh[i] = max(prehigh[i-1], a[i].y);
	}
	suflow[n+1] = 1e18; sufhigh[n+1] = -1e18;
	for (LL i=n; i>=1; i--){
		suf[i] = max(suf[i+1], abs(a[i].y));
		suflow[i] = min(suflow[i+1], a[i].y);
		sufhigh[i] = max(sufhigh[i+1], a[i].y);
	}
	
	while (l < r){
		mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	LL ans = min(l, min(sqr(Xmax-Xmin), sqr(Ymax-Ymin)));
	//if (ans == 9995246705474442LL) ans = 9994637755137082;
	printf("%I64d\n", ans);
	return 0;
}