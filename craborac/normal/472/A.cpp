#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int mas[(int)1e6 + 20];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++)
		mas[i] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(mas[i] == 0)
		{
			long long q = (long long)i * i;
			while(q <= (long long)n)
			{
				mas[q] = 1;
				q += i;
			}
		}
	}
	for(int i = 4; i <= n; i++)
		if((mas[i] == 1) && (mas[n - i] == 1))
		{
			printf("%d %d", i, n - i);
			return 0;
		}
	return 0;
}