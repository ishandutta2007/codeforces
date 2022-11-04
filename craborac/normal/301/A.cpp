#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int mas[300];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n - 1; i++)
		scanf("%d", &mas[i]);
	sort(mas, mas + 2 * n - 1);
	int col = 0;
	int sum = 0;
	int sum1 = 0;
	while (col < 2 * n - 1)
	{
		if(mas[col] < 0)
		{
			sum += mas[col];
			col++;
		}
		else
		{
			sum1 = sum + mas[col];
			if(col > 0)
				sum -= mas[col - 1];
			break;
		}
	}
	
	if(n % 2 == 0)
	{
		if(col % 2 == 0)
		{
			int ans = 0;
			for(int i = 0; i < 2 * n - 1; i++)
				ans += abs(mas[i]);
			printf("%d", ans);
		}
		else
		{
			if(col == 2 * n - 1)
				sum -= mas[2 * n - 2];
			int ans = 0;
			for(int i = 0; i < 2 * n - 1; i++)
				ans += mas[i];
			ans -= 2 * (min(sum1, sum));
			printf("%d", ans);
		}	
	}
	else
	{
		int ans = 0;
		for(int i = 0; i < 2 * n - 1; i++)
			ans += abs(mas[i]);
		printf("%d", ans);
	}
	return 0;
}