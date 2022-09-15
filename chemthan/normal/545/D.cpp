#include <iostream>
#include <algorithm>

typedef long long ll;

int n;
ll a[100000];

void solve()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::cin>>n;
	for (int i = 0; i < n; i++)
		std::cin>>a[i];
	std::sort(a, a + n);
	ll temp = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			temp += a[i - 1];
		bool check = false;
		if (a[i] >= temp)
		{
			result++;
			check = true;
		}
		else
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[j] >= temp)
				{
					int buf = a[i];
					a[i] = a[j];
					a[j] = buf;
					result++;
					check = true;
					break;
				}
			}
		}
		if (!check)
			break;
	}
	std::cout<<result;
}

void main()
{
	solve();
}