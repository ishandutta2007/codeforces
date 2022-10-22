#include <bits/stdc++.h>

#define MAXN (200010)
#define lowbit(x) ((x) & (-(x)))
#define ll long long

int n, q;
int p[MAXN];
struct node{
	int x1, y1, x2, y2, id;
}query[MAXN];
ll ans[MAXN];
int cnt[MAXN];
std::vector<node> vec1[MAXN], vec2[MAXN];

void insert(int x){
	for(int i = x; i && i <= n; i += lowbit(i)){
		++ cnt[i];
	}
}

int getsum(int x){
	int ret = 0;
	for(int i = x; i; i -= lowbit(i)){
		ret += cnt[i];
	}
	return ret;
}

ll wjj(int x){
	return 1ll * x * (x - 1) / 2;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", p + i);
	}
	for(int i = 1; i <= q; ++ i){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans[i] += wjj(x1 - 1);
		ans[i] += wjj(n - x2);
		ans[i] += wjj(y1 - 1);
		ans[i] += wjj(n - y2);
		query[i] = {x1, y1, x2, y2, i};
	}
	for(int i = 1; i <= q; ++ i){
		vec1[query[i].x1].push_back(query[i]);
		vec2[query[i].x2].push_back(query[i]);
	}
	
	for(int i = 1; i <= n; ++ i){
		for(auto t : vec1[i]){
		//	printf("i = %d, t.x1 = %d\n", i, t.x1);
			int tmp1 = getsum(t.y1 - 1);
			int tmp2 = getsum(n) - getsum(t.y2);
			ans[t.id] -= 1ll * tmp1 * (tmp1 - 1) / 2;
			ans[t.id] -= 1ll * tmp2 * (tmp2 - 1) / 2;
		}
		insert(p[i]);
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = n; i >= 1; -- i){
		for(auto t : vec2[i]){
			int tmp1 = getsum(t.y1 - 1);
			int tmp2 = getsum(n) - getsum(t.y2);
			ans[t.id] -= 1ll * tmp1 * (tmp1 - 1) / 2;
			ans[t.id] -= 1ll * tmp2 * (tmp2 - 1) / 2;
		}
		insert(p[i]);
	}
//	printf("%d\n", wjj(n));
	for(int i = 1; i <= q; ++ i){
		printf("%I64d\n", wjj(n) - ans[i]);
	}
	return 0;
}