#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int LIMIT = (int)(1e7);

long long cnt[LIMIT + 5];
bool flag[LIMIT + 5];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	} 
	for(int i = 2; i <= LIMIT; i++) {
		if (flag[i]) {
			cnt[i] = 0;
			continue;
		}
		for(int j = i + i; j <= LIMIT; j += i) {
			cnt[i] += cnt[j];
			flag[j] = true;
		}
	}
	
	for(int i = 2; i <= LIMIT; i++) {
		cnt[i] += cnt[i - 1];
	}
	
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		if (r > LIMIT)
			r = LIMIT;
		if (l > LIMIT)
			l = LIMIT;
		printf("%I64d\n", cnt[r] - cnt[l - 1]);
	}
	return 0;
}