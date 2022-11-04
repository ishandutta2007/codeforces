#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

long long ans[300];

int main()
{
	int a, b, c;
	int answer = 0;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i < 82; i++)
	{
		long long sum = i;
		for (int j = 1; j < a; j++)
			sum *= i;
		sum *= b;
		sum += c;
		long long sum1 = sum;
		int sum2 = 0;
		if(sum < (long long)1e9)
		{
			while (sum > 0)
			{
				sum2 += sum % 10;
				sum /= 10;
			}
			if (sum2 == i)
			{
				ans[answer++] = sum1;
			}
		}
	}
	printf("%d\n", answer);
	sort(ans, ans + answer);
	for (int i = 0; i < answer; i++)
		printf("%I64d ", ans[i]);
	return 0;
}