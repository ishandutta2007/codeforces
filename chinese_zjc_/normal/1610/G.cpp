// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s;
int n, nxt[300005];
std::stack<int> sta;
bool cmp(int x, int y)
{
	while (x < n && y < n && s[x] == s[y])
		x = nxt[x + 1], y = nxt[y + 1];
	return y < n && (x >= n || s[x] == '(');
}
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin >> s;
	n = s.size();
	nxt[n] = n;
	sta.push(n);
	for (int i = n; i--;)
	{
		nxt[i] = i;
		if (s[i] == ')')
			sta.push(i);
		else
		{
			sta.pop();
			if (sta.empty())
				sta.push(i);
			else if (cmp(i, sta.top()))
				sta.top() = i;
			else
				nxt[i] = sta.top();
		}
	}
	for (int i = nxt[0]; i < n; i = nxt[i + 1])
		std::cout << s[i];
	std::cout << std::endl;
	return 0;
}