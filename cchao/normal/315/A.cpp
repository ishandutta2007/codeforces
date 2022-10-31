#include <cstdio>
int n, a[110], b[110];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &a[i], &b[i]);
	int ans = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			if(i==j) continue;
			if(b[j] == a[i]) { ans++; break; }
		}
	printf("%d\n", n-ans);
	return 0;
}