#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int LIMIT = 1e6 + 1;

int n, k;
map<int, int> pairs;
int min_factor[LIMIT];

int main() {
	{
		int bound = 1e6;
		for (int i = 2; i <= bound; i++) {
			min_factor[i] = i;
		}
		for (int i = 2; i <= bound; i++) {
			for (int j = i; j <= bound; j += i) {
				min_factor[j] = min(min_factor[j], i);
			}
		}
	}

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		while (x > 1) {
			int prime = min_factor[x], cnt = 0;
			while (x % prime == 0) {
				x /= prime;
				cnt++;
			}
			if (pairs.count(prime)) {
				pairs[prime] = max(pairs[prime], cnt);
			} else {
				pairs[prime] = cnt;
			}
		}
	}

	int x = k;
	while (x > 1) {
		int prime = min_factor[x], cnt = 0;
		while (x % prime == 0) {
			x /= prime;
			cnt++;
		}
		if (pairs[prime] < cnt) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}