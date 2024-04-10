#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
	int m, d;
	cin >> m >> d;

	if (m == 2 )
	{
		if (d == 1)
			cout << 4;
		else
			cout << 5;
		return 0;
	}
	
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d == 6 || d == 7)
		{
			cout << 6;
			return 0;
		}
		else
		{
			cout << 5;
			return 0;
		}
	}
	else
	{
		if (d == 7)
		{
			cout << 6;
			return 0;
		}
		else
		{
			cout << 5;
			return 0;
		}
	}
	
	return 0;
}