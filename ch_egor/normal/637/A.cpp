#include <iostream>

using namespace std;

int cnt[1000228];
int n, h;

int main()
{
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h);
		cnt[h]++;
		if (cnt[h] > cnt[ans])
			ans = h;
	}
	printf("%d\n", ans);
	return 0;
}