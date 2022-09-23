#include <bits/stdc++.h>

using namespace std;

int N;
char A[55];
int cnt[26];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) cnt[A[i] - 'a']++;
		for(int i = 0; i < 26; i++) if(cnt[i] == 2) printf("%c", 'a' + i);
		for(int i = 0; i < 26; i++) if(cnt[i] == 2) printf("%c", 'a' + i);
		for(int i = 0; i < 26; i++) if(cnt[i] == 1) printf("%c", 'a' + i);
		puts("");
	}
	return 0;
}