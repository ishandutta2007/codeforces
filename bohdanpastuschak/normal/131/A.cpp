#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	if (s[0] <= 90)
	{
		bool d = true;
		for (int i = 1; i < s.length(); ++i)
		{
			if (s[i] > 90) d = false;
		}
		if (d)
		{
			for (int i = 0; i < s.length(); ++i)
			{
				if (s[i] > 90) s[i] -= 32;
				else s[i] += 32;
			}
			cout << s;
		}
		else
			cout << s;
		return 0;
	}
	else
	{
		bool d = true;
		for (int i = 1; i < s.length(); ++i)
		{
			if (s[i] > 90) d = false;
		}
		if (d)
		{
			for (int i = 0; i < s.length(); ++i)
			{
				if (s[i] > 90) s[i] -= 32;
				else s[i] += 32;
			}
			cout << s;
			return 0;
		}
		else
		{
			cout << s;
			return 0;
		}
	}




	return 0;
}