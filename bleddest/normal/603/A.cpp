#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i] != s[i - 1])
			cnt++;
	}
	printf("%d", min(n, cnt + 3));
	
	return 0;
}