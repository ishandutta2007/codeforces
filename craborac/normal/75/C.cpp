#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

long long go(long long a, long long b)
{
	if(b == 0)
		return a;
	else
		return go(b, a % b);
}

vector<long long> mas;

int main()
{
	long long a, b;
	scanf("%I64d %I64d", &a, &b);
	int n;
	long long nod = go(a, b);
	for (long long i = 1; i * i <= nod; i++)
	{
		if (nod % i == 0)
		{
			if (i * i != nod)
			{
				mas.push_back(i);
				mas.push_back(nod / i);
			}
			else
			{
				mas.push_back(i);
			}
		}
	}
	sort(mas.begin(), mas.end());
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		long long l, r;
		scanf("%I64d %I64d", &l, &r);
		if(l > nod)
			printf("-1\n");
		else if(nod <= r)
			printf("%I64d\n", nod);
		else
		{
			int ll = 0;
			int rr = mas.size();
			int m;
			while(rr - ll > 1)
			{
				m = (ll + rr) / 2;
				if(mas[m] <= r)
					ll = m;
				else
					rr = m;
			}
			if(mas[ll] >= l)
					printf("%I64d\n", mas[ll]);
			else
				printf("-1\n");
		}
	}
	return 0;
}