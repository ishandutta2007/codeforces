#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	s.push_back('a');
	string r;
	int now = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (now == 0)
		{
			if (s[i] == 'o')now = 1;
			else r.push_back(s[i]);
		}
		else if (now == 1)
		{
			if (s[i] == 'g')now = 2;
			else if (s[i] == 'o')now = 1, r.push_back(s[i - 1]);
			else now = 0, r.push_back(s[i - 1]), r.push_back(s[i]);
		}
		else if (now == 2)
		{
			if (s[i] == 'o')
			{
				now = 0, r += "***";
				for (;;)
				{
					if (i + 2 < s.size())
					{
						if (s[i + 1] == 'g'&&s[i + 2] == 'o')i += 2;
						else break;
					}
					else break;
				}
			}
			else r.push_back(s[i - 2]), r.push_back(s[i - 1]), r.push_back(s[i]), now = 0;
		}
	}
	r.pop_back();
	cout << r << endl;
}