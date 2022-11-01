#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000 + 15;

int n, m, t;

int a[maxn];

int fa[maxn];

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void join(int x, int y){
	int ra = find(x), rb = find(y);
	if(ra != rb){
		fa[ra] = rb;
	}
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			fa[i] = i;
		}
		fa[n + 1] = n + 1;
		
		long long ans = 0;
		
		for(i=1;i<n;i++){
			if(a[i] == 1){
				join(i, i + 1);
			}
		}
		
		for(i=1;i<n;i++){
			if(a[i] == 1) continue;
			if(a[i] > n - i){
				ans += a[i] - (n - i);
				a[i] = n - i;
			}
			while(a[i] > 1){
				int p = i;
				p = p + a[i];
				a[i]--;
				ans++;
				while(p <= n){
					p = find(p);
					if(p > n) break;
					int np = p + a[p];
					a[p] = max(a[p] - 1, 1);
					if(a[p] == 1) join(p, p + 1);
					p = np;
				}
			}
			join(i, i + 1);
		}
		ans += a[n] - 1;
		
		printf("%lld\n", ans);
	}
	
	return 0;
}