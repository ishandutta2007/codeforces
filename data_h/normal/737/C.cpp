#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 2e5 + 7;

int n, s, a[N];
int ans = 0;

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (a[s] != 0) {
		ans++;
		a[s] = 0;	
	}
	int rem = 0;
	for (int i = 1; i <= n; i++) {
		if (i != s && a[i] == 0) {
			rem++;
			ans++;
		}
	}
	sort(a + 1, a + n + 1);
	int s = 1;
	while (s <= n && a[s] == 0) s++;
	for (int cnt = 1, i = s, j; i <= n; i = j, ++cnt) {
		for (j = i; j <= n && a[j] == cnt; j++);
		if (j == i && n >= j) {
			if (rem) {
				rem--;
			} else {
				n--;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}