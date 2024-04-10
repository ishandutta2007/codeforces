#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int MAXN = 1000000;

char str[2000];

int check[MAXN + 10];
int a[MAXN];

int rever(int x)
{
	int len = 0;
	while(x)
	{
		a[++len] = x % 10;
		x /= 10;
	}	
	int res = 0;
	for(int i = 1; i <= len; i++)
		res = res * 10 + a[i];
	return res;
}

int main()
{
	/*
	gets(str);
	int len = strlen(str);
	for(int j = 1; j < 26; j++, printf("\n"))
	for(int i = 0; i < len; i++)
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			str[i]++;
			if (str[i] > 'z')
				str[i] = 'a';
		}
		printf("%c", str[i]);
	}
	*/
	int d;
	scanf("%d", &d);
	for(int i = 2; i <= MAXN; i++)
		if (!check[i])
		{
			for(int j = i + i; j <= MAXN; j += i)
				check[j] = 1;
		}
		
	for(int i = 13; d; i++)
	if (!check[i])
	{
		if (i != rever(i) && !check[rever(i)])
		{
			d--;
			if (!d)
				printf("%d\n", i);
		}
	}
	return 0;
}