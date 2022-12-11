#include <bits/stdc++.h>
int main()
{
	int t, n, s; std::cin >> t;
	while(t--)
	{
		std::cin >> n >> s;
		printf("%d\n", s / (n - (n + 1) / 2 + 1));
	}
	return 0;
}