#include <bits/stdc++.h>

using namespace std;

int X, Y;
char S[101010];
int N;
int cnt[130];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		cnt['R'] = cnt['L'] = cnt['U'] = cnt['D'] = 0;
		scanf("%d%d", &X, &Y);
		scanf("%s", S + 1);
		N = strlen(S + 1);
		for(int i = 1; i <= N; i++) cnt[S[i]]++;
		if(X > cnt['R'] || X < -cnt['L'] || Y > cnt['U'] || Y < -cnt['D']) puts("NO");
		else puts("YES");
	}
	return 0;
}