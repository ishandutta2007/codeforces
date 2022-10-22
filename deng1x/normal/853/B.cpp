#include <bits/stdc++.h>

#define MAXN (1000010)
#define ll long long

struct node{
	int t, c;
};
int n, m, k;
std::vector<node> from[MAXN], to[MAXN];
int now[MAXN];
ll pre[MAXN], suf[MAXN];
bool vpre[MAXN], vsuf[MAXN];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++ i){
		int d, f, t, c;
		scanf("%d%d%d%d", &d, &f, &t, &c);
		if(!f){
			to[d].push_back({t, c});
		}
		else{
			from[d].push_back({f, c});
		}
	}
		
	memset(now, -1, sizeof(now));
	int cnt = 0;
	ll sum = 0;
	for(int i = 1; i < MAXN; ++ i){
		vpre[i] = vpre[i - 1];
		pre[i] = pre[i - 1];
		for(auto p : from[i]){
			if(now[p.t] == -1){
				now[p.t] = p.c;
				++ cnt;
				sum += p.c;
			}
			else if(now[p.t] > p.c){
				sum += p.c - now[p.t];
				now[p.t] = p.c;
			}
			if(cnt == n){
				vpre[i] = true;
				pre[i] = sum;
			}
		}
	}
		
	memset(now, -1, sizeof(now));
	cnt = 0;
	sum = 0;
	for(int i = MAXN - 1; i; -- i){
		vsuf[i] = vsuf[i + 1];
		suf[i] = suf[i + 1];
		for(auto p : to[i]){
			if(now[p.t] == -1){
				now[p.t] = p.c;
				++ cnt;
				sum += p.c;
			}
			else if(now[p.t] > p.c){
				sum += p.c - now[p.t];
				now[p.t] = p.c;
			}
			if(cnt == n){
				vsuf[i] = true;
				suf[i] = sum;
			}
		}
	}
	
	ll ans = LLONG_MAX;
	for(int i = 1; i + k + 1 < MAXN; ++ i){
		if(vpre[i] && vsuf[i + k + 1]){
			ans = std::min(ans, pre[i] + suf[i + k + 1]);
		}
	}
	
	printf("%I64d\n", ans == LLONG_MAX ? -1 : ans);
	return 0;
}