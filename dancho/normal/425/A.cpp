#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int a[256], b[256], c[256];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int mx = a[0];
	for (int l = 0; l < n; ++l)
	{
		for (int r = l + 1; r <= n; ++r)
		{
			memcpy(b, a + l, (r-l) * sizeof(int));
			sort(b, b + r - l);
			memcpy(c, a, l * sizeof(int));
			memcpy(c + l, a + r, (n-r) * sizeof(int));
			int cnt = n - (r - l);
			sort(c, c + cnt);
			for (int j = 0; j < k && j < r-l && cnt-j-1 >= 0; ++j)
			{
				if (b[j] < c[cnt-j-1])
				{
					swap(b[j], c[cnt-j-1]);
				}
				else
					break;
			}
			int sm = 0;
			for (int i = 0; i < r-l; i++)
			{
				sm += b[i];
			}
			//~ printf("%d %d %d\n", l, r, sm);
			if (sm > mx)
				mx = sm;
		}
	}

	printf("%d\n", mx);
	return 0;
}