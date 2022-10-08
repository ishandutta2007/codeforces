#include <stdio.h>
#include <algorithm>
struct data {
	int a, b;
	bool operator < (const data & l) const {
		if(a != l.a) return a<l.a;
		else return b<l.b;
	}
} d[5050];
int main() {
	int N, i;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d %d", &d[i].a, &d[i].b);
	std::sort(d+1, d+N+1);
	int ans = 0;
	for(i = 1; i <= N; i++) {
		if(d[i].b >= ans) ans = d[i].b;
		else ans = d[i].a;
	}
	printf("%d", ans);
	return 0;
}