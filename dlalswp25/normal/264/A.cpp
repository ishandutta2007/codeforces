#include <stdio.h>

int ans[1000005];
char s[1000005];

int main() {
	scanf("%s", s);
	int N;
	for(N = 0; s[N]; N++);
	int l = 1, r = N;
	for(int i = 0; i < N; i++) {
		if(s[i] == 'l') ans[r--] = i + 1;
		else ans[l++] = i + 1;		
	}
	for(int i = 1; i <= N; i++) {
		printf("%d\n", ans[i]);		
	}
	return 0;
}