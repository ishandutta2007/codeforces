#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 111111;

int meet[MAXN];
int n, k, lower[MAXN], upper[MAXN], L, R, ch[MAXN];
vector<int> words[26];
char str[MAXN], buf[MAXN];
long long tot = 0;

int modify(int l, int r, int v) {
	for(int i = l; i <= r; i++) {
		if (meet[i] >= L && meet[i] <= R)
			tot--;
		meet[i] += v;
		if (meet[i] >= L && meet[i] <= R)
			tot++;
	}
}

int main() {
	scanf("%s", str);
	scanf("%d %d %d", &k, &L, &R);
	for(int i = 0; i < k; i++) {
		scanf("%s", buf);
		int l, r, x;
		scanf("%d %d", &lower[i], &upper[i]);
		ch[i] = buf[0] - 'a';
	}
	for(int i = 0; i < 26; i++)
		words[i].push_back(-1);
	long long ans = 0;
	for(int i = 0; str[i]; i++) {
		int x = str[i] - 'a';
		words[x].push_back(i);
		if (L == 0)
			tot++;
		for(int j = 0; j < k; j++) {
			if (ch[j] == x) {
				int size = words[x].size();
				if (size > lower[j] && lower[j]) {
					modify(words[x][size - lower[j] - 1] + 1, words[x][size - lower[j]], 1);
				}
				if (size > upper[j] + 1) {
					modify(words[x][size - upper[j] - 2] + 1, words[x][size - upper[j] - 1], -1);
				}
			}
			if (lower[j] == 0)
				modify(i, i, 1);
		}
		ans += tot;
		//printf("%d\n", tot);
	}
	printf("%I64d\n", ans);
	return 0;
}