#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll T;
char A[101010];
int cnt[30];

int main() {
	scanf("%d%lld", &N, &T);
	scanf("%s", A + 1);
	for(int i = 1; i <= N - 2; i++) {
		cnt[A[i] - 'a']++;
	}

	T += (1 << A[N - 1] - 'a');
	T -= (1 << A[N] - 'a');

	for(int i = 25; i >= 0; i--) {
		for(int j = 0; j < cnt[i]; j++) {
			if(T > 0) T -= (1 << i);
			else T += (1 << i);
		}
	}
	puts(T ? "No" : "Yes");

	return 0;
}