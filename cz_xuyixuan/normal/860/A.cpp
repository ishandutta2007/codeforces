#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
char s[MAXN];
int cnt[26], all, now;
bool func(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}
int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	memset(cnt, 0, sizeof(cnt)); all = now = 0;
	for (int i = 1; i <= len; i++) {
		if (func(s[i])) {
			printf("%c", s[i]);
			memset(cnt, 0, sizeof(cnt));
			all = now = 0;
		} else {
			all++;
			cnt[s[i] - 'a']++;
			if (cnt[s[i] - 'a'] == 1) now++;
			if (all >= 3 && now >= 2) {
				printf(" %c", s[i]);
				all = 1; now = 1;
				memset(cnt, 0, sizeof(cnt));
				cnt[s[i] - 'a']++;
			} else printf("%c", s[i]);
		}
	}
	printf("\n");
	return 0;
}