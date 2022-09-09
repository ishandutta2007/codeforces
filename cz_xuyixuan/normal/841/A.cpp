#include<bits/stdc++.h>
using namespace std;
#define MAXN	505
int cnt[256];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	char s[MAXN];
	scanf("\n%s", s + 1);
	for (int i = 1; i <= n; i++)
		cnt[s[i]]++;
	for (int i = 'a'; i <= 'z'; i++)
		if (cnt[i] > k) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}