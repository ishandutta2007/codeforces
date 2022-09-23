#include <stdio.h>
#include <algorithm>

using namespace std;

char s[3][100005];
int cnt[127];
int sc[3];

int main() {
	int N; scanf("%d", &N);
	for(int i = 0; i < 3; i++) scanf("%s", s[i]);
	int len = 0;
	for(int i = 0; s[0][i]; i++) len++;

	for(int j = 0; j < 3; j++) {
		int mx = -1;
		for(int i = 0; i < len; i++) cnt[s[j][i]]++;

		for(int i = 'A'; i <= 'Z'; i++) {
			if(mx < cnt[i]) mx = cnt[i];
		}
		for(int i = 'a'; i <= 'z'; i++) {
			if(mx < cnt[i]) mx = cnt[i];
		}
		for(int i = 0; i < 127; i++) cnt[i] = 0;
		sc[j] = min(len, mx + N);
		if(mx == len && N == 1) sc[j]--;
	}

	if(sc[0] > sc[1] && sc[0] > sc[2]) puts("Kuro");
	else if(sc[1] > sc[0] && sc[1] > sc[2]) puts("Shiro");
	else if(sc[2] > sc[0] && sc[2] > sc[1]) puts("Katie");
	else puts("Draw");
	return 0;
}