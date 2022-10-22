#include <bits/stdc++.h>

#define MAXN (1000010)

int min[MAXN];
std::vector <int> prime;

void shai() {
	for (int i = 2; i < MAXN; ++ i){
		if (!min[i]){
			min[i] = i;
			prime.push_back(i);
		}
		for (int j = 0, k, sz = (int) prime.size(); j < sz && i * prime[j] < MAXN; ++ j){
			min[k = i * prime[j]] = prime[j];
			if (i % prime[j] == 0){
				break;
			}
		}
	}
}

int go(int x){
	int t = x, max = 0;
	while (t != 1) {
		max = std::max(max, min[t]);
		t /= min[t];
	}
	return x - max + 1;
}

int main() {
	shai();
	int x;
	scanf("%d", &x);
	int ans = INT_MAX;
	for (int i = go(x); i <= x; ++ i){
		if (min[i] != i){
			ans = std::min(ans, go(i));
		}
	}
	printf("%d\n", ans);
	return 0;
}