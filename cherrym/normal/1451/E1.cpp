#include <bits/stdc++.h>

const int N = (1 << 16) + 5;

int n, a[N], t0, c0[N], t1, c1[N], A, B;
std::vector<int> c[N];

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		printf("XOR %d %d\n", 1, i), fflush(stdout), scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] & 1) c1[++t1] = i; else c0[++t0] = i;
		c[a[i] >> 1].push_back(i);
	}
	if (t0 > 1) printf("OR %d %d\n", c0[1], c0[2]), fflush(stdout),
		scanf("%d", &A), A &= 1;
	else printf("OR %d %d\n", c1[1], c1[2]), fflush(stdout),
		scanf("%d", &A), A &= 1, A ^= 1;
	for (int s = 0; s < n / 2; s++) if (c[s].size() > 1)
	{
		printf("OR %d %d\n", c[s][0], c[s][1]); fflush(stdout);
		scanf("%d", &B); B >>= 1; B ^= s; B = B << 1 | A;
		break;
	}
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", a[i] ^ B);
	return puts(""), 0;
}