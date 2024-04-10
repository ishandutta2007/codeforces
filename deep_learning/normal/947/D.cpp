#include <algorithm>
#include <cstring>
#include <cstdio>
char s[100005], t[100005]; 
int prea[100005], preb[100005], lena[100005], lenb[100005]; 
int main()
{
	// freopen("947D.in", "r", stdin); 
	scanf("%s%s", s, t); 
	int n = strlen(s), m = strlen(t), q; 
	for (int i = 0; i < n; i++)
	{
		prea[i] = (i ? prea[i - 1] : 0) + (s[i] != 'A'); 
		lena[i] = (i ? lena[i - 1] + 1 : 1) * (s[i] == 'A'); 
	}
	for (int i = 0; i < m; i++)
	{
		preb[i] = (i ? preb[i - 1] : 0) + (t[i] != 'A'); 
		lenb[i] = (i ? lenb[i - 1] + 1 : 1) * (t[i] == 'A'); 
	}
	scanf("%d", &q); 
	while (q--)
	{
		int l, r, x, y; 
		scanf("%d%d%d%d", &l, &r, &x, &y); 
		l--;
		r--;
		x--;
		y--; 
		int b1 = prea[r] - (l ? prea[l - 1] : 0), b2 = preb[y] - (x ? preb[x - 1] : 0);
		int la = std::min(lena[r], r - l + 1), lb = std::min(lenb[y], y - x + 1); 
		if (b1 > b2 || (b1 - b2 & 1) || la < lb)
			putchar('0'); 
		else if (b1 == b2)
			putchar((la - lb) % 3 ? '0' : '1');
		else if (la == lb)
			putchar(b1 ? '1' : '0'); 
		else
			putchar('1'); 
	}
	return 0; 
}