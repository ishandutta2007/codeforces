#include <bits/stdc++.h>

#define MAXN (1010)

int n;
struct P{
    int v[5];
}p[MAXN];

bool check(P a, P b, P c){
	long long up = 0;
	for(int i = 0; i < 5; ++ i){
		up += (b.v[i] - a.v[i]) * (c.v[i] - a.v[i]);
	}
	return up <= 0;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
		for(int j = 0; j < 5; ++ j){
			scanf("%d", &p[i].v[j]);
		}
	}
	if(n > 100){
		printf("0\n");
		return 0;
	}
	std::set<int> set;
	for(int i = 1; i <= n; ++ i){
		bool mark = true; 
		for(int j = 1; j <= n; ++ j){
			if(j == i) continue;
			for(int k = 1; k <= n; ++ k){
				if(k == j || k == i) continue;
				if(!check(p[i], p[j], p[k])){
					mark = false;
				}
			}
		}
		if(mark){
			set.insert(i);
		}
	}
	printf("%d\n", set.size());
	for(auto u : set){
		printf("%d\n", u);
	}
    return 0;
}