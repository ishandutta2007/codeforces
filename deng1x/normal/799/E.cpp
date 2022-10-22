#include <bits/stdc++.h>

#define MAXN (200010)
#define ll long long
#define lowbit(i) ((i) & (-(i)))

int n, m, k;
int nab, na, nb, pos[MAXN], vis[MAXN];
std::pair<ll, int> c[MAXN], cnt[MAXN];
std::pair<ll, int> both[MAXN], onlya[MAXN], onlyb[MAXN];

void insert(int sit, int first, int second){
	for(int i = sit; i <= n; i += lowbit(i)){
		cnt[i].first  += first;
		cnt[i].second += second;
	}
}

std::pair<ll, int> getsum(int sit){
	std::pair<ll, int> ret(0, 0);
	for(int i = sit; i; i -= lowbit(i)){
		ret.first  += cnt[i].first;
		ret.second += cnt[i].second;
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++ i){
		scanf("%I64d", &c[i].first);
		c[i].second = i;
	}
	
	std::sort(c + 1, n + c + 1);
	for(int i = 1; i <= n; ++ i) pos[c[i].second] = i;
	
	for(int i = -1; i <= 2; i += 3){
		int x, y;
		scanf("%d", &x);
		for(int j = 1; j <= x; ++ j){
			scanf("%d", &y);
			vis[pos[y]] += i;
		}
	}
	
	for(int i = 1; i <= n; ++ i){
		switch(vis[i]){
			case  1: both [++ nab] = {c[i].first, i};     break;
			case -1: onlya[++  na] = {c[i].first, i};     break;
			case  2: onlyb[++  nb] = {c[i].first, i};     break;
			case  0: insert(i, c[i].first, 1); break;
		}
	}
	
	ll nowans = 0;
	int cntab = 0, cnta = 0, cntb = 0;
	
	for(int i = 1; i <= nab; ++ i){
		if(i <= k) nowans += both[i].first, cntab = i;
		else insert(both[i].second, both[i].first, 1);
	}
	for(int i = 1; i <= na; ++ i){
		if(i + cntab <= k) nowans += onlya[i].first, cnta = i;
		else insert(onlya[i].second, onlya[i].first, 1);
	}
	for(int i = 1; i <= nb; ++ i){
		if(i + cntab <= k) nowans += onlyb[i].first, cntb = i;
		else insert(onlyb[i].second, onlyb[i].first, 1);
	}
	
	if(cntab + cnta + cntb > m || cntab + cnta < k || cntab + cntb < k) return printf("-1\n"), 0;
	
	ll ans = LLONG_MAX;
	while(cntab >= 0 && cnta + cntb + cntab <= m){
		int left = 0, right = n;
		ll cost = -1;
		while(left <= right){
			int mid = left + right >> 1;
			std::pair<ll, int> query = getsum(mid);
			if(cnta + cntb + cntab + query.second >= m){
				cost = query.first;
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		
		if(cost != -1) ans = std::min(ans, nowans + cost);
		else return printf("-1\n"), 0;
		
		if(cnta ++ == na || cntb ++ == nb) break;
		nowans += onlya[cnta ].first;
		nowans += onlyb[cntb ].first;
		if(cntab) nowans -= both [cntab].first;
		
		insert(onlya[cnta ].second, - onlya[cnta] .first, -1);
		insert(onlyb[cntb ].second, - onlyb[cntb] .first, -1);
		if(cntab) insert(both [cntab].second,   both [cntab].first,  1);
		
		-- cntab;
	}
	
	printf("%I64d\n", ans == LLONG_MAX ? -1 : ans);
	return 0;
}