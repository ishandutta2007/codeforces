#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 0x3f3f3f3f;
int n;
int a[N];

int solve(int l, int r) {
	if(!r || !l || l > r) return 0;
	if(l == r) return min(a[l], 1);
	int mn = inf, k;
	for(int i = l; i <= r; i++) 
		if(a[i] < mn) 
			mn = a[i], k = i;
	int tmp = a[k];
	for(int i = l; i <= r; i++) 
		a[i] -= tmp;
	int x = solve(l, k - 1), y = solve(k + 1, r);
	return min(tmp + x + y, r - l + 1);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	printf("%d\n", min(n, solve(1, n)));	
	return 0;
}