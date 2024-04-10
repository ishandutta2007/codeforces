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

const int N = 4e5 + 5;

int n, a[N], m, x[N], y[N], top1, top2;

struct point
{
	int x, y;
} stk1[N], stk2[N];

int main()
{
	read(n); int nowr = n;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = n; i >= 1; i--)
		if (a[i] == 0) continue;
		else if (a[i] == 1)
		{
			x[++m] = nowr--; y[m] = i;
			stk1[++top1] = (point) {nowr + 1, i};
		}
		else if (a[i] == 2)
		{
			if (!top1) return puts("-1"), 0;
			stk2[++top2] = (point) {stk1[top1].x, i};
			x[++m] = stk1[top1--].x; y[m] = i;
		}
		else if (top2)
		{
			x[++m] = nowr--; y[m] = i;
			x[++m] = nowr + 1; y[m] = stk2[top2].y;
			stk2[top2] = (point) {x[m - 1], y[m - 1]};
		}
		else if (top1)
		{
			x[++m] = nowr--; y[m] = i;
			x[++m] = nowr + 1; y[m] = stk1[top1].y;
			stk2[++top2] = (point) {x[m - 1], y[m - 1]};
			top1--;
		}
		else return puts("-1"), 0;
	std::cout << m << std::endl;
	for (int i = 1; i <= m; i++) printf("%d %d\n", x[i], y[i]);
	return 0;
}