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

const int N = 3e5 + 5;

int n, a[N], top, stk[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	top = 0;
	for (int i = 1; i <= n; i++)
		if (!top || stk[top] > a[i]) stk[++top] = a[i];
		else
		{
			int lst;
			while (top && stk[top] < a[i]) lst = stk[top--];
			stk[++top] = lst;
		}
	puts(top == 1 ? "YES" : "NO");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}