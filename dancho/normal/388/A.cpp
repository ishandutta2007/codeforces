#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int x[1<<10];

vector<int> v[1<<10];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}

	sort(x, x + n);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		int k;
		for (k = 0; k < j; ++k)
		{
			if ((int) v[k].size() <= x[i])
			{
				//~ printf("ADD %d %d\n", x[i], (int) v[k].size());
				v[k].push_back(x[i]);
				break;
			}
		}
		if (k >= j)
		{
			v[j++].push_back(x[i]);
		}
	}
	
	printf("%d\n", j);
	return 0;
}