#include<bits/stdc++.h>

inline int sqr(int n){return n * n;}

int d, r;
int n;

int main(){
	scanf("%d%d%d", &r, &d, &n);
	d = r - d;
	int cnt = 0;
	for (int i = 0, x, y, rr; i < n; ++ i){
		scanf("%d%d%d", &x, &y, &rr);
		if (!d){
			cnt += sqr(r - rr) >= sqr(x) + sqr(y);
			continue;
		}
		cnt += sqr(d + rr) <= sqr(x) + sqr(y) && sqr(r - rr) >= sqr(x) + sqr(y);
	}
	return printf("%d\n", cnt), 0;
}