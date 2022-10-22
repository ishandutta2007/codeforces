#include <bits/stdc++.h>

#define MAXN (500010)
#define MAXA (1000010)
#define ll long long

int n, x, y;
int a[MAXN], cnt[MAXA];

ll getans(int t){
	ll ret = 0;
	for(int i = 1; i <= n; ++ i){
		ret += std::min(1ll * x, 1ll * y * ((t - a[i] % t) % t));
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", a + i);
		++ cnt[a[i]];
	}
	for(int i = 1; i < MAXA; ++ i){
		for(int j = i + i; j < MAXA; j += i){
			cnt[i] += cnt[j];
		}
	}
	ll ans = getans(2);
	std::vector<std::pair<int, int> > vec;
	for(int i = 2; i < MAXA; ++ i){
		if(cnt[i]){
			vec.push_back({-cnt[i], i});
		}
	}
	std::sort(vec.begin(), vec.end());
	for(int i = 0, sz = (int)vec.size(); i < 200 && i < sz; ++ i){
		ans = std::min(ans, getans(vec[i].second));
	}
	printf("%I64d\n", ans);
	return 0;
}