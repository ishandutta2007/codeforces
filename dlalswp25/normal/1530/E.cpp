#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];
int cnt[30];
vector<int> X;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		X.clear();
		for(int i = 0; i < 26; i++) cnt[i] = 0;

		scanf("%s", A + 1);
		N = strlen(A + 1);
		for(int i = 1; i <= N; i++) cnt[A[i] - 'a']++;
		for(int i = 0; i < 26; i++) {
			if(cnt[i]) X.push_back(i);
		}

		if(X.size() == 1) {
			printf("%s\n", A + 1);
			continue;
		}

		int one = -1;
		for(int i = 0; i < 26; i++) {
			if(cnt[i] == 1) {
				one = i; break;
			}
		}

		if(one != -1) {
			printf("%c", one + 'a');
			cnt[one]--;
			for(int i = 0; i < 26; i++) {
				for(int j = 0; j < cnt[i]; j++) printf("%c", i + 'a');
			}
			puts("");
			continue;
		}

		if(N >= cnt[X[0]] * 2 - 2) {
			int p = 1;
			printf("%c%c", X[0] + 'a', X[0] + 'a');
			cnt[X[0]] -= 2;
			while(p < X.size()) {
				while(p < X.size() && !cnt[X[p]]) p++;
				if(p >= X.size()) break;
				printf("%c", X[p] + 'a');
				cnt[X[p]]--;
				if(cnt[X[0]]) {
					printf("%c", X[0] + 'a');
					cnt[X[0]]--;
				}
			}
			puts("");
			continue;
		}

		if(X.size() == 2) {
			printf("%c", X[0] + 'a');
			cnt[X[0]]--;
			for(int i = 0; i < cnt[X[1]]; i++) printf("%c", X[1] + 'a');
			for(int i = 0; i < cnt[X[0]]; i++) printf("%c", X[0] + 'a');
			puts("");
			continue;
		}

		printf("%c", X[0] + 'a'); cnt[X[0]]--;
		printf("%c", X[1] + 'a'); cnt[X[1]]--;
		for(int i = 0; i < cnt[X[0]]; i++) printf("%c", X[0] + 'a');
		printf("%c", X[2] + 'a'); cnt[X[2]]--;
		for(int i = 1; i < X.size(); i++) {
			for(int j = 0; j < cnt[X[i]]; j++) printf("%c", X[i] + 'a');
		}
		puts("");
	}
	return 0;
}