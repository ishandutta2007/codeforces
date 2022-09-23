#include <stdio.h>

int a[1000005];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	if(sum % 2)
	{
		puts("First");
		return 0;
	}

	bool isOdd = false;
	for(int i = 0; i < n; i++)	if(a[i] % 2)	isOdd = true;

	if(isOdd)	puts("First");
	else	puts("Second");
	return 0;
}