#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

struct chislo
{
	int qwe, ind;
	bool operator <(const chislo a)const
	{
		return qwe < a.qwe;
	}
};

chislo mas[(int)1e5 + 10];

int ans[(int)1e5 + 10], answer[(int)1e5 + 10];

int main()
{
	int sum, n;
	scanf("%d %d", &sum, &n);
	int summ = 0;
	for(int i = 1; i <= n; i++)
	{
		int q = i;
		ans[i] = 1;
		while(q % 2 == 0)
		{
			ans[i] *= 2;
			q /= 2;
		}
		summ += ans[i];
		mas[i - 1].qwe = ans[i];
		mas[i - 1].ind = i;
	}
	int col = 0;
	if(summ < sum)
		printf("-1");
	else
	{
		summ = 0;
		sort(mas, mas + n);
		for(int i = n - 1; i >= 0; i--)
		{
			if(summ + mas[i].qwe <= sum)
			{
				answer[col] = mas[i].ind;
				col++;
				summ += mas[i].qwe;
			}	
		}
		if(summ == sum)
		{
			printf("%d\n", col);
			for(int i = 0; i < col; i++)
				printf("%d ", answer[i]);
		}
		else
			printf("-1");
	}
	return 0;
}