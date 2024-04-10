#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d:%d", &a, &b, &c);
	int r = 0;
	if (c / 10 >= 6)c = c % 10;
	if (a == 12 && b == 0)b = 10;
	if (a == 12 && b >= 13)
	{
		if (b % 10 == 0)b = 10;
		else b = b % 10;
	}
	if (a == 24 && b >= 24)b = b % 10 + 10;
	printf("%02d:%02d\n", b, c);
}