#include <stdio.h>
#include <iostream>
#include <algorithm>
#define myABS(x)	(((x) > 0) ? (x) : ((x) * (-1)))

using namespace std;

int N, K, P;
int a[1005];
int b[2005];

int main()
{
	scanf("%d %d %d", &N, &K, &P);

	for(int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < K; i++)
	{
		scanf("%d", &b[i]);
	}

	sort(a, a + N);
	sort(b, b + K);

	long long left = 0, right = 1;
	for(int i = 0; i < 18; i++)	right *= 10;

	while(left <= right)
	{
		long long mid = (left + right) / 2;

		bool possible = true;

		int key = 0;
		for(int i = 0; i < N; i++)
		{
			int j;
			for(j = key; j < K; j++)
			{
				if((long long)myABS(a[i] - b[j]) + myABS(b[j] - P) <= mid)
				{
					key = j + 1;
					break;
				}
			}
			if(j == K)
			{
				possible = false;
				break;
			}
		}

		if(possible)	right = mid - 1;
		else	left = mid + 1;
	}

	cout << left;
	return 0;
}