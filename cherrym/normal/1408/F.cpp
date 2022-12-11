#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

void jiejuediao(int l, int r)
{
	if (l == r) return;
	int mid = l + r >> 1;
	jiejuediao(l, mid); jiejuediao(mid + 1, r);
	for (int i = l; i <= mid; i++)
		printf("%d %d\n", i, i - l + mid + 1);
}

int main()
{
	int n, k = 1, tot = 0; std::cin >> n;
	while ((k << 1) <= n) k <<= 1, tot++;
	std::cout << k * tot << std::endl;
	jiejuediao(1, k); jiejuediao(n - k + 1, n);
	return 0;
}