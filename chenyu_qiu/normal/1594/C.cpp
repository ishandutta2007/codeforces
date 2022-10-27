#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() 
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char c;
		cin >> c;
		string s;
		cin >> s;
		s = 'w' + s;
		int key = 3;
		int ou = 0, ji = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] != c)
			{
				key--;
				break;
			}
		}
		if (key == 3)cout << "0" << endl;
		else
		{
			bool flag = 0;
			int as = 0;
			for (int i = 1; i <= n; i++)
			{
				bool t = false;
				for (int j = i; j <= n; j += i)
				{
					if (s[j] != c)
					{
						t = true;
					}
				}
				if (!t)
				{
					flag = true;
					as = i;
					break;
				}
			}
			if (!flag)
			{
				cout << 2 << endl;
				cout << n - 1 << ' ' << n << endl;
			}
			else
			{
				cout << 1 << endl;
				cout << as << endl;
			}
		}
	}
}