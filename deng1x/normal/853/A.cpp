#include <bits/stdc++.h>

#define MAXN (300010)
#define ll long long

int n, k;
int c[MAXN];
std::priority_queue<std::pair<int, int> > pq;
int ans2[MAXN];

int main(){
	scanf("%d%d", &n, &k);
	ll ans = 0;
	for(int i = 1; i <= n; ++ i){
		scanf("%d", c + i);
	}
	for(int i = k + 1, j = 1; i <= k + n; ++ i){
		while(j <= i && j <= n){ pq.push({c[j], j}); ++ j; }
		auto p = pq.top(); pq.pop();
		ans += 1ll * p.first * (i - p.second);
		ans2[p.second] = i;
	}
	printf("%I64d\n", ans);
	for(int i = 1; i <= n; ++ i) printf("%d%c", ans2[i], " \n"[i == n]);
	
	return 0;
}