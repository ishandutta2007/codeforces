#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1111;
int a[N];
int n, c;
int ans = 0;

int main() {
	scanf("%d %d", &n, &c);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i < n; i++) {
		ans = max(ans, a[i] - a[i + 1] - c);
	}
	
	printf("%d\n", ans);
	return 0;
}