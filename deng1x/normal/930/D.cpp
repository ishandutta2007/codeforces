#include <bits/stdc++.h>

#define MAXN (200010)
#define ll long long

int n;
int a[MAXN << 1], b[MAXN << 1];
int pa[MAXN << 1], sa[MAXN << 1];
int pb[MAXN << 1], sb[MAXN << 1];
struct node{
	int x, y;
}p[MAXN];

ll solve(int t){
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(pa, 0, sizeof(pa));
	memset(pb, 0, sizeof(pb));
	memset(sa, 0, sizeof(sa));
	memset(sb, 0, sizeof(sb));
	for (int i = 0; i < MAXN << 1; ++ i){
		b[i] = (MAXN << 1) - 1;
	}
	for (int i = 0; i < n; ++ i){
		if((p[i].x & 1) ^ t) continue;
		a[p[i].x] = std::max(a[p[i].x], p[i].y);
		b[p[i].x] = std::min(b[p[i].x], p[i].y);
	}
	pb[0] = sb[(MAXN << 1) - 1] = (MAXN << 1) - 1;
	for (int i = 1; i < MAXN << 1; ++ i){
		pa[i] = std::max(pa[i - 1], a[i]);
		pb[i] = std::min(pb[i - 1], b[i]);
	}
	for (int i = (MAXN << 1) - 2; ~i; -- i){
		sa[i] = std::max(sa[i + 1], a[i]);
		sb[i] = std::min(sb[i + 1], b[i]);
	}
	ll ret = 0;
	for (int i = 1 + t; i < (MAXN << 1) - 1; i += 2){
		int l = std::min(pa[i - 1], sa[i + 1]);
		int r = std::max(pb[i - 1], sb[i + 1]);
		if (l <= r){
			ret += MAXN;
			continue;
		}
		if ((l ^ i) & 1) ++ l;
		if ((r ^ i) & 1) -- r;
		ret += (((MAXN << 1) - 1 - l) >> 1) + 1;
		ret += (r >> 1) + 1;
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = {x + y + MAXN, x - y + MAXN};
	}
	ll ans = 1ll * (MAXN << 1) * ((MAXN << 1) - 2) / 2 - solve(0) - solve(1);
	printf("%I64d\n", ans);
	return 0;
}