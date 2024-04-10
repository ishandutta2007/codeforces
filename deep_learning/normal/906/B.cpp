#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
int ans[200005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("906B.in", "r", stdin); 
#endif
	int n, m; 
	scanf("%d%d", &n, &m); 
	if (n == 4 && m == 4)
	{
		puts("YES"); 
		puts("6 11 3 5");
		puts("9 1 8 16");
		puts("7 4 2 10");
		puts("14 12 15 13"); 
		return 0; 
	}
	else if (n == 4 && m == 3)
	{
		puts("YES"); 
		puts("3 11 5");
        puts("12 6 7");
        puts("2 8 1");
        puts("9 4 10");
		return 0; 
	}
	else if (n == 4 && m == 2)
	{
		puts("YES");
		puts("5 2"); 
		puts("4 7"); 
		puts("1 6"); 
		puts("8 3"); 
		return 0;
	}
	else if (n == 4 && m == 1)
	{
		puts("YES"); 
		puts("3");
		puts("1");
		puts("4");
		puts("2");
		return 0; 
	}
	else if (n == 3 && m == 4)
	{
		puts("YES"); 
		puts("6 3 1 4");
		puts("8 10 7 2");
		puts("9 12 5 11"); 
		return 0; 
	}
	else if (n == 3 && m == 3)
	{
		puts("YES"); 
		puts("8 1 6");
		puts("3 5 7");
		puts("4 9 2");
	}
	else if ((n == 2 || n == 3) && m <= 2)
	{
		puts("NO");
		return 0; 
	}
	else if (n == 2 && m == 3)
	{
		puts("NO");
		return 0; 
	}
	else if (n == 2 && m == 4)
	{
		puts("YES");
		puts("5 4 7 2");
		puts("3 6 1 8");
		return 0; 
	}
	else if (n == 1 && m == 1)
	{
		puts("YES"); 
		puts("1"); 
		return 0; 
	}
	else if (n == 1 && (m == 2 || m == 3))
	{
		puts("NO");
		return 0; 
	}
	else if (n == 1 && m == 4)
	{
		puts("YES");
		puts("3 1 4 2");
		return 0; 
	}
	else if (n >= 5)
	{
		puts("YES"); 
		int cur = 0; 
		if (n & 1)
		{
			for (int i = n; i > 0; i -= 2)
				ans[++cur] = i; 
			for (int i = n - 1; i > 0; i -= 2)
				ans[++cur] = i; 
		}
		else
		{
			for (int i = n - 1; i > 0; i -= 2)
				ans[++cur] = i; 
			for (int i = n; i > 0; i -= 2)
				ans[++cur] = i; 
		}
		for (int i = 1; i <= n; i++)
		{
			ans[i] = (ans[i] - 1) * m + 1; 
			ans[i + n] = ans[i]; 
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d%c", j - 1 + ans[(i + j - 1) % n + 1], " \n"[j == m]);
		}
		return 0; 
	}
	else if (m >= 5)
	{
		puts("YES");
		int cur = 0; 
		if (m & 1)
		{
			for (int i = m; i > 0; i -= 2)
				ans[++cur] = i; 
			for (int i = m - 1; i > 0; i -= 2)
				ans[++cur] = i; 
		}
		else
		{
			for (int i = m - 1; i > 0; i -= 2)
				ans[++cur] = i; 
			for (int i = m; i > 0; i -= 2)
				ans[++cur] = i; 
		}
		for (int i = 1; i <= m; i++)
			ans[i + m] = ans[i]; 
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d%c", ans[j + (i - 1) % m + 1] + (i - 1) * m, " \n"[j == m]);
		}
		return 0;
	}
	return 0; 
}