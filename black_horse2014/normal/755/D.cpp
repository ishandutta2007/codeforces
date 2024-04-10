#include <bits/stdc++.h>
using namespace std;

int a[1111111];
int n, k;

void add(int id) {
	for (int i = id; i <= n; i += i & -i) a[i]++;
}

int get(int id) {
	int res = 0;
	for (int i = id; i; i -= i & -i) res += a[i];
	return res;
}

int main() {
	
	scanf("%d%d", &n, &k);
	k = min(k, n - k);
	int x = 1;
	long long res = 1;
	for (int i = 1; i <= n; i++) {
		int y = x + k;
		int cur =  -get(x);
		if (y > n) {
			cur += 2 * (i - 1); 
			y -= n;
		}
		cur += get(y - 1);
		res += (cur + 1);
		printf("%lld%c", res, (i < n) ? ' ' : '\n');
		add(x), add(y);
		x = y;
	}
	
	return 0;
}