#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[105];
int cnt[105];

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(cnt, 0, sizeof cnt);
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			++cnt[a[i]];
		}
		int x = 2, s = 0;
		for(int i = 0; i <= 100; i++) {
			if(cnt[i] < x) {
				s += (x - cnt[i]) * i;
				x = cnt[i];
			}
			if(!cnt[i]) break;
		}
		printf("%d\n", s);
	}
	return 0;
}