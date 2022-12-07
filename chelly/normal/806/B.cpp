#include<bits/stdc++.h>
using namespace std;
const int N(199);
int n;
int a[N][5];
int delta[5], init[5];
bool check(int x) {
	for(int d(0); d < 5; d++) {
		if(a[0][d] != -1 && (a[1][d] == -1 || a[1][d] > a[0][d])) {
			delta[d] = 0;
		}else if(a[0][d] != -1) {
			delta[d] = x;
		}else {
			delta[d] = 0;
		}
		delta[d] += init[d];
	}
	int sc[2] = {0, 0};
	for(int i(0); i < 2; i++) {
		for(int d(0); d < 5; d++) {
			int c;
			if(2ll * delta[d] > (n + x)) {
				c = 500;
			}else if(4ll * delta[d] > (n + x))
				c = 1000;
			else if(8ll * delta[d] > (n + x))
				c = 1500;
			else if(16ll * delta[d] > (n + x))
				c = 2000;
			else if(32ll * delta[d] > (n + x))
				c = 2500;
			else
				c = 3000;
			if(a[i][d] != -1)
				sc[i] += c * (250 - a[i][d]) / 250;
		}
	}
	if(sc[0] > sc[1])
		return true;
	else 
		return false;
}
int main() {
	scanf("%d", &n);
	for(int i(0); i < n; i++) {
		for(int j(0); j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i(0); i < n; i++) {
		for(int d(0); d < 5; d++) {
			if(a[i][d] != -1) {
				init[d]++;
			}
		}
	}
	int ans(1e9);
	for(int i(0); i <= 100000; i++) {
		if(check(i))
			ans = min(ans, i);
	}
	if(ans == 1e9)
		ans = -1;
	printf("%d\n", ans);
}