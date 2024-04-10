#include<bits/stdc++.h>
using namespace std;
const int N(5555);
int dis[N], cnt[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(dis, 0x7f, sizeof(dis));
	for(int i(1); i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		b = b - a;
		if(b < 0) b += n;
		cnt[a - 1]++;
		dis[a - 1] = min(dis[a - 1], b);
	}
	for(int i(0); i < n; i++) {
		int ans = 0;
		for(int j(0); j < n; j++) {
			if(cnt[j]) 
				ans = max(ans, n * (cnt[j] - 1) + (j - i + n) % n + dis[j]);
		}
		printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
	}
}