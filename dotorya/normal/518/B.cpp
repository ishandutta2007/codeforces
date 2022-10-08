#include <stdio.h>
char s[200050];
char t[200050];

int cnt1[55];
int cnt2[55];

int charToNum(char c) {
	if(c >= 'a' && c <= 'z') return c-'a';
	else return c-'A'+26;
}
int main() {
	int i;
	scanf("%s %s", s, t);
	for(i = 0; s[i] != 0; i++) cnt1[charToNum(s[i])]++;
	for(i = 0; t[i] != 0; i++) cnt2[charToNum(t[i])]++;

	int ans1 = 0, ans2 = 0;
	for(i = 0; i < 52; i++) {
		if(cnt2[i] >= cnt1[i]) {
			cnt2[i] -= cnt1[i];
			ans1 += cnt1[i];
			cnt1[i] = 0;
		}
		else {
			ans1 += cnt2[i];
			cnt1[i] -= cnt2[i];
			cnt2[i] = 0;
		}
	}

	for(i = 0; i < 52; i++) {
		int t = (i+26)%52;
		ans2 += (cnt1[i] < cnt2[t])? cnt1[i] : cnt2[t];
	}

	printf("%d %d", ans1, ans2);
	return 0;
}