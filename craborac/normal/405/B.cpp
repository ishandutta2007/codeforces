#include<cstdio>
int mas[3000];
int main()
{
	int n;
	scanf("%d\n", &n);
	int coll = 0, colr = 0;
	for(int i = 0; i < n; i++)
	{
		char c;
		scanf("%c", &c);
		if(c == 'L')
		{
			coll++;
			mas[i] = -1;
		}
		else if(c == 'R')
		{
			colr++;
			mas[i] = 1;
		}
		else
			mas[i] = 0;
	}
	if((coll == 0) && (colr == 0))
	{
		printf("%d", n);
		return 0;
	}
	if(coll == 0)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			if(mas[i] == -1)
			{
				printf("%d", n - 1 - i);
				return 0;
			}
		}
	}
	if(colr == 0)
	{
		for(int i = 0; i < n; i++)
		{
			if(mas[i] == 1)
			{
				printf("%d", i);
				return 0;
			}
		}
	}
	int answer = 0;
	for(int i = 0; i < n; i++)
	{
		if(mas[i] == -1) 
			break;
		else if(mas[i] == 1)
		{
			answer += i;
			break;
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(mas[i] == 1)
			break;
		else if(mas[i] == -1)
		{
			answer += n - 1 - i;
			break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(mas[i] == 1)
		{
			for(int j = i; j < n; j++)
			{
				if(mas[j] == -1)
				{
					if((j - i) % 2 == 0)
						answer++;
					break; 
				}
			}
		}
		else if(mas[i] == -1)
		{
			for(int j = i; j < n; j++)
			{
				if(mas[j] == 1)
				{
					answer += j - i - 1;
					break;
				}
			}
		}
	}
	printf("%d", answer);
	return 0;
}