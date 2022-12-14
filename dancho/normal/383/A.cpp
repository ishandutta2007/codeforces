#include <cstdio>
#include <cstring>
#include <iostream>

int n;
int a[1<<20];

int main()
{
	scanf("%d", &n);
	long long cnt = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		cnt += a[i];
		if (a[i] == 0)
			ans += cnt;
	}
	
	std::cout << ans << '\n';
	return 0;
}