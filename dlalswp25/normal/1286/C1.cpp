#include <bits/stdc++.h>

using namespace std;

int N;

multiset<string> S;

int cnt[105][150];
char ans[105];

int main() {
	scanf("%d", &N);
	printf("? 1 %d\n", N); fflush(stdout);

	for(int i = 1; i <= N * (N + 1) / 2; i++) {
		string x; cin >> x;
		sort(x.begin(), x.end());
		S.insert(x);
	}

	if(N == 1) {
		printf("! %c\n", (*(S.begin()))[0]);
		return 0;
	}

	printf("? 1 %d\n", N - 1); fflush(stdout);

	for(int i = 1; i <= (N - 1) * (N) / 2; i++) {
		string x; cin >> x;
		sort(x.begin(), x.end());
		S.erase(S.find(x));
	}

	for(auto i : S) {
		int m = i.size();
		for(char j : i) cnt[m][(int)j]++;
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 'a'; j <= 'z'; j++) {
			if(cnt[i][j]) {
				ans[N - i + 1] = j;
				for(int k = i + 1; k <= N; k++) cnt[k][j]--;
			}
		}
	}	

	printf("! "); for(int i = 1; i <= N; i++) printf("%c", ans[i]); puts("");
	fflush(stdout);

	return 0;
}