#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int n;
LL a[100005], c[100005], sig;
int main(){
	int t = 1;
	while(t --){
		scanf("%d%lld", &n, &a[1]);sig = 0;
		for (register int i = 2;i <= n;i ++){
			scanf("%lld", &a[i]);
			c[i] = a[i] - a[i - 1];
			if(c[i] > 0) sig += c[i];
		}
		printf("%lld\n", ((sig + a[1]) >> 1) + ((sig + a[1]) & 1));
		int q;scanf("%d", &q);
		while(q --){
			int l, r;LL w;scanf("%d%d%lld", &l, &r, &w);
			if(l == 1) a[1] += w;
			else{
				if(c[l] > 0) sig -= c[l];
				c[l] += w;
				if(c[l] > 0) sig += c[l];
			}
			++ r;
			if(r <= n){
				if(c[r] > 0) sig -= c[r];
				c[r] -= w;
				if(c[r] > 0) sig += c[r];
			}
			printf("%lld\n", ((sig + a[1]) >> 1) + ((sig + a[1]) & 1));
		}
	}
}