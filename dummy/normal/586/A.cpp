#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i<n; i++) {
		scanf("%d", a+i);
	}
	a[n] = a[n+1] = 0;
	int ans = 0;
	bool at = false;
	for(int i = 0; i<n; i++) {
		if(at) {
			if(a[i] == 0 && a[i+1] == 0)
				at = false;
		}
		else {
			if(a[i] == 1)
				at = true;
		}
		if(at)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}