#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char S[101010];
int cnt[30][101010];
int N;

ll tmp[30];

int main() {
	scanf("%s", S + 1);
	N = strlen(S + 1);
	for(int i = 1; i <= N; i++) {
		cnt[S[i] - 'a'][i]++;
	}
	for(int i = 0; i < 26; i++) {
		for(int j = N; j >= 1; j--) cnt[i][j] += cnt[i][j + 1];
	}

	ll ans = 0;
	for(int i = 0; i < 26; i++) ans = max(ans, (ll)cnt[i][1]);

	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) tmp[j] = 0;
		for(int j = 1; j <= N; j++) {
			if(S[j] - 'a' != i) continue;
			for(int k = 0; k < 26; k++) {
				tmp[k] += cnt[k][j + 1];
			}
		}
		for(int j = 0; j < 26; j++) ans = max(ans, tmp[j]);
	}
	printf("%lld\n", ans);

	return 0;
}