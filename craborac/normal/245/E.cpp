#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] != s[i + 1])
		{
			int col = 0;
			for(int j = i + 1; j < n; j++)
			{
				if(s[j] == '+')
					col++;
				else
					col--;
				ans = max(ans, abs(col));
			}
		}
	}
	int col = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '+')
			col++;
		else
			col--;
		ans = max(ans, abs(col));
	}
	cout << ans;
	return 0;
}