#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 24;

int cnt[1 << N], n;

void solve(int s) {
	int num = 0;
	for(int i = 0; i < N; i++) {
		num += (s >> i & 1);
	}
	
	if (num % 2 == 1) {
		cnt[s]++;
	} else {
		cnt[s]--;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		char word[6];
		scanf("%s", word);
		int delta = 0;
		for(int j = 0; j < 3; j++) {
			delta |= (1 << (word[j] - 'a'));
		}
		
		for(int s = delta; ; s = ((s - 1) & delta)) {
			if (s == 0)
				break;
			solve(s);
		}
	}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < (1 << N); j++) {
			if (~j >> i & 1) {
				cnt[j | (1 << i)] += cnt[j];
			}
		}
		
	int ans = 0;
	for(int i = 0; i < (1 << N); i++) {
		ans ^= (cnt[i] * cnt[i]);
	}
	
	printf("%d\n", ans);
	return 0;
}