#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int p[32];
int cnt = 0;
int tinv = 0;

void go(int k)
{
	if (!k)
	{
		int inv = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (p[i] > p[j])
					++inv;
		tinv += inv;
		++cnt;
		return;
	}
	for (int l = 0; l < n; ++l)
	{
		for (int r = l; r < n; ++r)
		{
			reverse(p + l, p + r + 1);
			go(k - 1);
			reverse(p + l, p + r + 1);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}
	
	go(k);
	
	printf("%.12lf\n", (double) tinv / cnt);
	
	return 0;
}