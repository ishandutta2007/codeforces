#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, x;
int t[2048];
int h[2048];
int m[2048];
bool us[2048];

int gogo(int s)
{
	int y = x;
	int sl = 0;
	memset(us, 0, sizeof(us));
	while (1)
	{
		int cand = -1;
		for (int i = 0; i < n; ++i)
		{
			if (t[i] == s && h[i] <= y && us[i] == 0)
			{
				if (cand == -1 || m[cand] < m[i])
				{
					cand = i;
				}
			}
		}
		if (cand == -1)
		{
			break;
		}
		s = 1 - s;
		++sl;
		us[cand] = 1;
		y += m[cand];
	}
	return sl;
}

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &t[i], &h[i], &m[i]);
	}

	int sl = max(gogo(0), gogo(1));

	printf("%d\n", sl);

	return 0;
}