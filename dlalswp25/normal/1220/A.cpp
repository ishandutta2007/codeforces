#include <bits/stdc++.h>

using namespace std;

int N;
char S[101010];
int cnt[130];

int main() {
	scanf("%d", &N);
	scanf("%s", S + 1);
	for(int i = 1; i <= N; i++) cnt[S[i]]++;

	cnt['o'] -= cnt['z'];
	for(int i = 1; i <= cnt['o']; i++) printf("1 ");
	for(int i = 1; i <= cnt['z']; i++) printf("0 ");
	puts("");
	return 0;
}