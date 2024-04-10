#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0, i = 0, j = 0;
	int count = 0;
	while (i < n || j < n)
	{
		if (j < n && count <= k)
		{
			if (s[j] == 'a')
				count++;
			j++;
			if (count <= k)
				ans = max(ans, j - i);
			continue;
		}
		if (s[i] == 'a')
			count--;
		i++;
		if (count <= k)
			ans = max(ans, j - i);
	}
	count = 0;
	i = 0;
	j = 0;
	while (i < n || j < n)
	{
		if (j < n && count <= k)
		{
			if (s[j] == 'b')
				count++;
			j++;
			if (count <= k)
				ans = max(ans, j - i);
			continue;
		}
		if (s[i] == 'b')
			count--;
		i++;
		if (count <= k)
			ans = max(ans, j - i);
	}
	cout << ans;
}