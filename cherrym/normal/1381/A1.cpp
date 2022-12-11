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

const int N = 1e5 + 5;

int n;
char a[N], b[N];

char conv(char c) {return c == '0' ? '1' : '0';}

void work()
{
	std::vector<int> ans;
	scanf("%d%s%s", &n, a + 1, b + 1);
	int l = 1, r = n, op1 = 0, op2 = 0;
	for (int i = n; i >= 1; i--)
	{
		int pl = op1 ? r : l, pr = op1 ? l : r;
		char lst = a[pr], fis = a[pl];
		if (op2) lst = conv(lst), fis = conv(fis);
		if (lst == b[i]) {if (op1) l++; else r--; continue;}
		if (fis == b[i]) a[pl] = conv(a[pl]), ans.push_back(1);
		ans.push_back(r - l + 1); if (op1) r--; else l++;
		op1 ^= 1; op2 ^= 1;
	}
	printf("%d ", ans.size());
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}