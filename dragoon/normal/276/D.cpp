#include<stdio.h>

typedef __int64 LL;

LL p2[100];

int main()
{
	LL L, R, ans = 0;
	int i;

	scanf("%I64d%I64d", &L, &R);

	if(L==R)
	{
		printf("0\n");
		return 0;
	}

	p2[0] = 1;
	for(i = 1; i < 64; i++)
		p2[i] = p2[i-1]*2;

	for(i = 62; i>=0;i--)
	{
		if( (L&p2[i]) == (R&p2[i]) )
			continue;
		else
			break;
	}

	ans = p2[i];
	for(i = i-1; i>=0;i--)
		ans += p2[i];

	printf("%I64d\n", ans);

	return 0;
}