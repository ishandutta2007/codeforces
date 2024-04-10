#include <cstdio>
long long r, ans;
char c;
int main()
{
	scanf("%I64d", &r);
	scanf("%c", &c);
	r = r - 1;
	ans = r / 4 * 16;
	r = r % 4;
	r = r % 2;
	ans += r * 7;
	if (c >= 'd')
		ans += 6 - (c - 'a');
	else
		ans += 4 + (c - 'a');
	printf("%I64d\n", ans);
	return 0;
}