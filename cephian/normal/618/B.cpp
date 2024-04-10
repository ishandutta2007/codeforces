#include <bits/stdc++.h>
using namespace std;

int g[55][55],n,p[55];

int main() {	
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d",g[i]+j);
	for(int k = 1; k <= n; ++k) {
		for(int t = 1; t <= n; ++t) {
			set<int> S;
			for(int r = 1; r <= n; ++r) {
				S.insert(g[r][t]), S.insert(g[t][r]);
			}
			if(S.size() == 2) {
				for(int r = 1; r <= n; ++r) {
					g[r][t] = g[t][r] = 0;
				}
				p[t] = k;
				break;
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(p[i] == 0) p[i] = n;
		printf("%d ",p[i]);
	}
	printf("\n");
}