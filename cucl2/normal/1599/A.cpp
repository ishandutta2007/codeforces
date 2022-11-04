#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int a[200005], p[200005];
char s[200005];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", a + i);
	scanf("%s", s + 1);
	sort(a + 1, a + N + 1);
	int lp = 0, rp = 0;
	p[1] = 0;
	for (int i = 2; i <= N; ++i) {
		if (s[i] != s[i - 1]) p[i] = ++rp;
		else p[i] = --lp;
	}
	int m2 = s[1] == 'L' ? 1 : 0;
	for (int i = 1; i <= N; ++i) {
		printf("%d ", a[p[i] - lp + 1]);
		if (s[i] != s[i - 1]) putchar(s[i]);
		else putchar("LR"[m2]), m2 ^= 1;
		puts("");
	}
	return 0;
}