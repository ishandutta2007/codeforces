#include <bits/stdc++.h>

using namespace std;

char S[500005];
int C[500005];
int D[500005];

int main() {
	int N; scanf("%d", &N);
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%s", S);
		int t = 0, mn = 0;
		for(int j = 0; S[j]; j++) {
			if(S[j] == '(') t++;
			else t--;
			mn = min(mn, t);
		}

		if(t >= 0) {
			if(mn < 0) continue;
			else C[t]++;
		}
		else {
			if(mn < t) continue;
			else D[-t]++;
		}
	}

	ans = C[0] / 2;
	for(int i = 1; i <= 500000; i++) {
		ans += min(C[i], D[i]);
	}
	printf("%d\n", ans);
	return 0;
}