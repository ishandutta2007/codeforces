#include <bits/stdc++.h>
using namespace std;

char s[312345];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		int a = s[i] - '0';
		if(a % 4 == 0) ans++;
	}
	for(int i = 1; i < n; ++i) {
		int a = s[i] - '0';
		int b = s[i - 1] - '0';
		int t = b * 10 + a;
		if(t % 4 == 0) {
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}