#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111111, M = 20;

int d, n, m;

int belone[N];
int f[1 << M];
int cnt[N];

int main() {
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 0; i < m; i++) {
		int len;
		scanf("%d", &len);
		for(int j = 1; j <= len; j++) {
			int x;
			scanf("%d", &x);
			belone[x] = i;
		}
	}
	for(int i = 1, j = 1, msk = 0; i + d - 1 <= n; i++) {
		while(j - i < d) {
			if (++cnt[belone[j]] == 1)
				msk |= (1 << belone[j]);
			++j;	
		}
		f[msk] = 1;
		if (--cnt[belone[i]] == 0)
			msk ^= (1 << belone[i]);
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < (1 << m); j++)
			if (j >> i & 1) {
				f[j] += f[j ^ (1 << i)];
			}
	int ans = m;
	for(int i = 0; i < (1 << m); i++)
		if (f[i] == 0) {
			int tmp = m;
			for(int j = 0; j < m; j++)
				if (i >> j & 1)
					tmp--;
			ans = min(ans, tmp);
		}
	printf("%d\n", ans);
	return 0;
}