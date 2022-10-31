#include <bits/stdc++.h>
using namespace std;
char s[105];
int n;
bool cmp(char a, char b) { return a > b; }
int main()
{
	scanf("%d%s", &n, s);
	sort(s, s + n, cmp);
	if (s[0] == '1') putchar('1');
	else
	{
		putchar('0');
		return 0;
	}
	for (int i = 1; i < n; i++)
		if (s[i] == '0') putchar('0');
	return 0;
}