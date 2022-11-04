#include<cstdio>
int mas[20];
int main()
{
	long long a;
	int k;
	scanf("%I64d %d", &a, &k);
	int q = 1;
	long long w = 10;
	while(a >= w)
	{
		q++;
		w *= 10;
	}
	for(int i = q - 1; i >= 0; i--)
	{
		mas[i] = a % 10;
		a = a / 10;
	}
	for(int i = 0; i < q; i++)
	{
		int maxx = mas[i];
		int maxi = i;
		for(int j = i + 1; j < q; j++)
		{
			if(j - i <= k)
			{
				if(mas[j] > maxx)
				{
					maxx = mas[j];
					maxi = j;
				}
			}
			else
				break;
		}
		for(int j = maxi; j > i; j--)
			mas[j] = mas[j - 1];
		mas[i] = maxx;
		k = k - maxi + i;	
	}
	for(int i = 0; i < q; i++)
		printf("%d", mas[i]);
	return 0;
}