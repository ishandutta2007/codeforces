#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;

int n, t;

struct ex {
	int l, r;
};

ex p[maxn];
int a[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++)p[i].l = inf, p[i].r = 0;
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			p[a[i]].r = max(p[a[i]].r, i);
			p[a[i]].l = min(p[a[i]].l, i);
		}
		int ans = inf;
		int cnt = 0;
		for(i=1;i<=n;i++)if(p[i].r)cnt++;
		for(i=1;i<=n;i+=j){
			if(!p[i].r){
				j = 1;
				continue;
			}
			int sum = 0;
			int r = 0;
			for(j=0;i+j<=n;j++){
				if(!p[i + j].r)continue;
				if(p[i + j].l > r){
					sum++;
					r = p[i + j].r;
				}else{
					break;
				}
			}
			ans = min(ans, cnt - sum);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}