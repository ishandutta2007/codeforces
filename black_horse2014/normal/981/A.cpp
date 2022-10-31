#include <bits/stdc++.h>
using namespace std;

char s[222];
int main() {
	scanf("%s", s);
	int len = strlen(s);
	int ans = 0;
	for (int i = 0; i < len; i++) 
		for (int j = i; j < len; j++) {
			bool pal = true;
			for (int k = i; k <= j; k++) pal &= (s[k] == s[i + j - k]);
			if (!pal) ans = max(ans, j - i + 1);
		}
	printf("%d\n", ans);
	return 0;	
}